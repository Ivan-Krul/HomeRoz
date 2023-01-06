#include "queryhomeroz.h"

#include "additionalstringlib.h"

#include <iostream>

namespace query_home_roz
{
	void QueryHomeRoz::WriteBinaryString(const std::string& str, std::ofstream& fs)
	{
		auto s = str.size();
		fs.write((char*)(&s), sizeof(str.size()));
		fs.write(str.c_str(), str.size());
	}

	std::string QueryHomeRoz::ReadBinaryString(const size_t size, std::ifstream& fs)
	{
		auto buffer = std::unique_ptr<char>(new char[size + 1]);
		buffer.get()[size] = 0;
		fs.read(buffer.get(), size);
		return buffer.get();
	}

	/*
	Definition:
		&S (string):
			string.size() > c
			->
				string[c]
			<-
	Structure:
		lesson.size() > l
		->
			&S (lesson[l].name)
			&S (lesson[l].link)
			&S (lesson[l].week)
			homework[l].size() > h
			->
				&S (homework[l][h].context)
				homework[l][h].date_from.day
				homework[l][h].date_from.month
				homework[l][h].date_to.day
				homework[l][h].date_to.month
				homework[l][h].done
			<-
		<-
	*/

	std::string QueryHomeRoz::ExecuteSave_(std::string& query)
	{
		if (SearchToken_(additional_string_lib::SplitStr(query)) != TokenIndex::in)
			return cs_not_valid_token_msg + ": SAVE (IN) [file]";

		auto fs = std::ofstream(additional_string_lib::SplitStr(query), std::ios::out | std::ios::binary);
		auto bufnum = mgr_.SizeLessons();

		fs.write(reinterpret_cast<const char*>(&bufnum), sizeof(mgr_.SizeLessons()));
		
		for (size_t l = 0; l < mgr_.SizeLessons(); l++)
		{
			auto& lesson = *mgr_.GetLesson(l);

			WriteBinaryString(lesson.GetName(), fs);
			WriteBinaryString(lesson.GetLink(), fs);

			bufnum = lesson.SizeWeek();

			fs.write(reinterpret_cast<const char*>(&bufnum), sizeof(lesson.SizeWeek()));

			for (size_t w = 0; w < lesson.SizeWeek(); w++)
				fs.write(reinterpret_cast<const char*>(lesson.GetWeek(w)), sizeof(lesson.GetWeek(w)));

			bufnum = mgr_.SizeHomeworks(l);

			fs.write(reinterpret_cast<const char*>(&bufnum), sizeof(mgr_.SizeHomeworks(l)));

			for (size_t h = 0; h < mgr_.SizeHomeworks(l); h++)
			{
				auto& homework = *mgr_.GetHomework(l, h);
				auto date = homework.GetFromDate();
				auto done = homework.GetDone();

				WriteBinaryString(homework.GetContex(), fs);
				fs.write(reinterpret_cast<const char*>(&date), sizeof(date));

				date = homework.GetToDate();

				fs.write(reinterpret_cast<const char*>(&date), sizeof(date));
				fs.write(reinterpret_cast<const char*>(&done), sizeof(done));
			}
		}
		fs.close();

		return cs_success_msg;
	}

	std::string QueryHomeRoz::ExecuteLoad_(std::string& query)
	{
		if (SearchToken_(additional_string_lib::SplitStr(query)) != TokenIndex::in)
			return cs_not_valid_token_msg + ": LOAD (IN) [file]";

		auto fs = std::ifstream(additional_string_lib::SplitStr(query), std::ios::in | std::ios::binary);

		if (!fs.is_open())
			return cs_nothing_msg+": no file there";

		auto bufnum = size_t();
		auto l = size_t();
		auto h = size_t();
		auto date = date_week::Date();
		auto done = bool();

		mgr_.Clear();
		fs.read(reinterpret_cast<char*>(&bufnum), sizeof(mgr_.SizeLessons()));
		
		for (l = 0; l < bufnum; l++)
			mgr_.PushLesson();
		for (l = 0; l < mgr_.SizeLessons(); l++)
		{
			auto& lesson = *mgr_.GetLesson(l);

			fs.read(reinterpret_cast<char*>(&bufnum), sizeof(lesson.GetName().size()));
			lesson.SetName(ReadBinaryString(bufnum, fs));
			fs.read(reinterpret_cast<char*>(&bufnum), sizeof(lesson.GetLink().size()));
			lesson.SetLink(ReadBinaryString(bufnum, fs));
			fs.read(reinterpret_cast<char*>(&bufnum), sizeof(lesson.SizeWeek()));

			for (size_t w = 0; w < bufnum; w++)
			{
				lesson.PushWeek(date_week::Week());
				fs.read(reinterpret_cast<char*>(lesson.GetWeek(w)), sizeof(lesson.GetWeek(w)));
			}
			fs.read(reinterpret_cast<char*>(&bufnum), sizeof(mgr_.SizeHomeworks(l)));

			for (h = 0; h < bufnum; h++)
				mgr_.PushHomework(l);
			for (h = 0; h < mgr_.SizeHomeworks(l); h++)
			{
				auto& homework = *mgr_.GetHomework(l, h);

				fs.read(reinterpret_cast<char*>(&bufnum), sizeof(homework.GetContex().size()));
				ReadBinaryString(bufnum, fs);
				fs.read(reinterpret_cast<char*>(&date), sizeof(date));
				homework.SetFromDate(date);
				fs.read(reinterpret_cast<char*>(&date), sizeof(date));
				homework.SetToDate(date);
				fs.read(reinterpret_cast<char*>(&done), sizeof(done));
				homework.SetDone(done);
			}	
		}
		fs.close();

		return cs_success_msg;
	}


}
