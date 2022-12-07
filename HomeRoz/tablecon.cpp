#include "table.h"
void Table::mConNothing()
{
	mCurrentAction = UserActions::nothing;
}
void Table::mConMoveUp()
{
	if (mIsSelectHW) {
		auto list = mHomeworkSelect.getLessonList();
		if (mIterLesson != list.begin())
			mIterLesson--;
	}
	else
	{
		auto list = mHomeworkSelect.getHomeworkList(*mIterLesson);
		if (mIterHomework != list.begin())
			mIterHomework--;
	}
	mConNothing();
}
void Table::mConMoveDown()
{
	if (mIsSelectHW) {
		auto list = mHomeworkSelect.getLessonList();
		if (mIterLesson != list.end())
			mIterLesson++;
	}
	else
	{
		auto list = mHomeworkSelect.getHomeworkList(*mIterLesson);
		if (mIterHomework != list.end())
			mIterHomework++;
	}
	mConNothing();
}
void Table::mConMoveLeft()
{
	if (mLineChoose != LineChoose::lesson)
		mLineChoose = static_cast<LineChoose>(static_cast<int>(mLineChoose) - 1);
	mConNothing();
}
void Table::mConMoveRight()
{
	if (mLineChoose != LineChoose::done)
		mLineChoose = static_cast<LineChoose>(static_cast<int>(mLineChoose) + 1);
	mConNothing();
}
void Table::mConCreateLesson()
{
	static Lesson sTemplateLesson;
	sTemplateLesson.setName("New Lesson");
	sTemplateLesson.PushWeek(WeekSetCurrentTime());
	mHomeworkSelect.AddLesson(sTemplateLesson);
	mConNothing();
}
void Table::mConCreateHomework()
{
	static Homework sTemplateHomework;
	Date date_from;
	date_from.SetCurrentTime();
	sTemplateHomework.setContex("New Homework");
	sTemplateHomework.setFromDate(date_from);
	sTemplateHomework.setToDate(date_from);
	sTemplateHomework.setLesson(&(*mIterLesson));
	mHomeworkSelect.AddHomework(sTemplateHomework);
	mConNothing();
}
void Table::mConSelectHomework()
{
	mIsSelectHW = !mIsSelectHW;
	mConNothing();
}
void Table::mConEraseLesson()
{
	mHomeworkSelect.EraseLesson(*mIterLesson);
	mConNothing();
}
void Table::mConEraseHomework()
{
	if (!mIsSelectHW)
	{
		mHomeworkSelect.EraseHomework(*mIterHomework);
		mConNothing();
	}
	else
		mConSelectHomework();
	mConNothing();
}
void Table::mConSave()
{
	/*
		*Structure of File*
		"HomeRoz"
		lesson_list size ->
			lesson name size
			lesson name
			lesson link size
			lesson link
			lesson weeks size ->
				weeks <-
			homework size ->
				homework context size
				homework context
				homework fromdate day
				homework fromdate month
				homework todate day
				homework todate month
				homework done <-
			<-
		<-
	*/
	std::ofstream fout;
	const std::string cBuffer = "HomeRoz";
	fout.open(mInputString, std::ios::binary | std::ios::out);
	fout.write(cBuffer.c_str(), cBuffer.size());
	// iterate a list of every lesson
	auto lesson_list = mHomeworkSelect.getLessonList();
	fout.write((char*)lesson_list.size(), sizeof(lesson_list.size()));
	for (auto& lesson : lesson_list)
	{
		fout.write((char*)lesson.getName().size(), sizeof(lesson.getName().size()));
		fout.write(lesson.getName().c_str(), lesson.getName().size());
		fout.write(lesson.getLink().c_str(), lesson.getLink().size());
		// iterate a list of weeks in lesson
		fout.write((char*)lesson.SizeWeek(), sizeof(lesson.SizeWeek()));
		for (auto week = lesson.BeginWeeks(); week != lesson.EndWeeks(); week++)
			fout.write((char*)*week, sizeof(*week));
		// iterate a list of every homework in lesson
		auto homework_list = mHomeworkSelect.getHomeworkList(lesson);
		fout.write((char*)homework_list.size(), sizeof(homework_list.size()));
		for (auto homework = homework_list.begin(); homework != homework_list.end(); homework++)
		{
			fout.write(homework->getContex().c_str(), homework->getContex().size());
			fout.write((char*)homework->getFromDate().getDay(), sizeof(homework->getFromDate().getDay()));
			fout.write((char*)homework->getFromDate().getMonth(), sizeof(homework->getFromDate().getMonth()));
			fout.write((char*)homework->getToDate().getDay(), sizeof(homework->getToDate().getDay()));
			fout.write((char*)homework->getToDate().getMonth(), sizeof(homework->getToDate().getMonth()));
			fout.write((char*)homework->getDone(), sizeof(homework->getDone()));
		}
	}
	fout.close();
	mConNothing();
}
void Table::mConLoad()
{
	/*
		*Structure of File*
		"HomeRoz"
		lesson_list size ->
			lesson name size
			lesson name
			lesson link size
			lesson link
			lesson weeks size ->
				weeks <-
			homework size ->
				homework context size
				homework context
				homework fromdate day
				homework fromdate month
				homework todate day
				homework todate month
				homework done <-
			<-
		<-
	*/
	std::ifstream fin;
	char buffer[1024];
	fin.open(mInputString, std::ios::binary | std::ios::in);
	if (!fin) return;
	fin.read(buffer, 7);
	if (buffer != "HomeRoz")
	{
		fin.close();
		return;
	}
	size_t sizelesson = 0;
	fin.read((char*)sizelesson, sizeof(sizelesson));
	for (size_t l = 0; l < sizelesson; l++)
	{
		Lesson lesson;
		size_t sizestr;
		size_t sizehw;
		lesson.setName(mWriteStrBinaryFin(fin));
		lesson.setLink(mWriteStrBinaryFin(fin));
		fin.read((char*)sizestr, sizeof(sizestr));
		for (size_t w = 0; w < sizestr; w++)
		{
			Week week;
			fin.read((char*)week, sizeof(week));
			lesson.PushWeek(week);
		}
		mHomeworkSelect.AddLesson(lesson);
		fin.read((char*)sizehw, sizeof(sizehw));
		for (size_t hw = 0; hw < sizehw; hw++)
			mHomeworkSelect.AddHomework(mWriteHomeworkFromBinary(fin,lesson));
	}
	fin.close();
	mConNothing();
}
void Table::mConInput()
{
	mIsInputAwait = !mIsInputAwait;
}
void Table::mConInputBuffer()
{
	mConInput();
	mIsInputBufferise = !mIsInputBufferise;
}
