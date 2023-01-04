#include "queryhomeroz.h"

#include "additionalstringlib.h"

namespace query_home_roz
{
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
	void query_home_roz::QueryHomeRoz::WriteBinaryString(const std::string& str, std::ofstream& fs)
	{
		size_t s = str.size();
		fs.write((char*)(&s), sizeof(str.size()));
		fs.write(str.c_str(), str.size());
	}

	std::string QueryHomeRoz::ReadBinaryString(std::ifstream& fs)
	{
		size_t size = ReadBinarySize(fs);
		char* buf = new char[size];
		fs.read(buf, size);
		std::string string = buf;
		delete[] buf;
		return string;
	}

	size_t QueryHomeRoz::ReadBinarySize(std::ifstream& fs)
	{
		size_t s;
		fs.read((char*)(&s), sizeof(s));
		return s;
	}

	std::string QueryHomeRoz::ExecuteSave_(std::string& query)
	{
		if (SearchToken_(additional_string_lib::SplitStr(query)) != TokenIndex::in)
			return cs_not_valid_token_msg + ": SAVE (IN) [file]";
		std::ofstream fs(additional_string_lib::SplitStr(query), std::ios::out | std::ios::binary);
		size_t numbuf = mgr_.SizeLessons();
		// Lesson
		fs.write((char*)(&numbuf), sizeof(mgr_.SizeLessons()));
		for (size_t l = 0; l < mgr_.SizeLessons(); l++)
		{
			auto lesson = mgr_.GetLesson(l);	
			WriteBinaryString(lesson->GetName(), fs);
			WriteBinaryString(lesson->GetLink(), fs);	
			// Weeks
			numbuf = lesson->SizeWeek();
			fs.write((char*)(&numbuf), sizeof(lesson->SizeWeek()));
			for (size_t w = 0; w < lesson->SizeWeek(); w++)
				fs.write((char*)(lesson->GetWeek(w)), sizeof(lesson->GetWeek(w)));
			numbuf = mgr_.SizeHomeworks(l);
			fs.write((char*)(&numbuf), sizeof(mgr_.SizeHomeworks(l))); // Homework
			for (size_t h = 0; h < mgr_.SizeHomeworks(l); h++)
			{
				auto homework = mgr_.GetHomework(l, h);
				WriteBinaryString(homework->GetContex(), fs);
				// Date Creation
				numbuf = homework->GetFromDate().GetDay();
				fs.write((char*)(&numbuf), sizeof(homework->GetFromDate().GetDay()));
				numbuf = (size_t)homework->GetFromDate().GetMonth();
				fs.write((char*)(&numbuf), sizeof(homework->GetFromDate().GetMonth()));
				// Date Term
				numbuf = homework->GetToDate().GetDay();
				fs.write((char*)(&numbuf), sizeof(homework->GetToDate().GetDay()));
				numbuf = (size_t)homework->GetToDate().GetMonth();
				fs.write((char*)(&numbuf), sizeof(homework->GetToDate().GetMonth()));
				numbuf = homework->GetDone();
				fs.write((char*)(&numbuf), sizeof(homework->GetDone())); // Done
			}
		}
		fs.close();
		return cs_success_msg;
	}

	std::string QueryHomeRoz::ExecuteLoad_(std::string& query)
	{
		if (SearchToken_(additional_string_lib::SplitStr(query)) != TokenIndex::in)
			return cs_not_valid_token_msg + ": LOAD (IN) [file]";
		std::ifstream fs(additional_string_lib::SplitStr(query), std::ios::in | std::ios::binary);
		if (!fs.is_open())
			return cs_nothing_msg+": no file there";
		mgr_.Clear();
		size_t lesson_size = ReadBinarySize(fs), week_size, homework_size;
		std::string buffer;
		Lesson lesson;
		Homework homework;
		date_week::Week week;
		date_week::Date date;
		short bufnum = 0; // TODO: There's problem, need fix it, cuz stack is corrupted, and compiler decided, what this variable is a little sus
		bool done = false;
		mgr_.PushLesson();
		for (size_t l = 0; l < lesson_size; l++)
		{
			lesson.SetName(ReadBinaryString(fs));
			lesson.SetLink(ReadBinaryString(fs));
			week_size = ReadBinarySize(fs);
			for (size_t w = 0; w < week_size; w++)
			{
				fs.read((char*)(&week), sizeof(week));
				lesson.PushWeek(week);
			}
			mgr_.SetLesson(l, lesson);
			homework_size = ReadBinarySize(fs);
			for (size_t h = 0; h < homework_size; h++)
			{
				mgr_.PushHomework(l);
				homework.SetContex(ReadBinaryString(fs));
				for (size_t i = 0; i < 2; i++)
				{
					fs.read((char*)(&bufnum), sizeof(date.GetDay()));
					date.SetDay(bufnum);
					fs.read((char*)(&bufnum), sizeof(date.GetMonth()));
					date.SetMonth(bufnum);
					(i == 0)
						? homework.SetFromDate(date)
						: homework.SetToDate(date);
				}
				fs.read((char*)(&done), sizeof(homework.GetDone()));
				homework.SetDone(done);
				mgr_.SetHomework(l, h, homework);
			}
		}
		fs.close();
		return cs_success_msg;
	}


}
