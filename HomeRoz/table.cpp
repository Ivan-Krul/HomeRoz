#include "table.h"
void Table::SenseControl(UserActions action)
{
	if(action != UserActions::nothing)
		mCurrentAction = action;
}
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
	if(mLineChoose != LineChoose::lesson)
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
}
void Table::mConSave(std::string dir)
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
		"HomeRoz"
	*/
	std::ofstream fout;
	const std::string cBuffer = "HomeRoz";
	fout.open(dir, std::ios::binary | std::ios::out);
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
		for (auto week = lesson.BeginWeeks(); week != lesson.EndWeeks();week++)
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
	fout.write(cBuffer.c_str(), cBuffer.size());
	fout.close();
}
void Table::mConLoad(std::string dir)
{
	std::ifstream fin;
	fin.open(dir, std::ios::binary | std::ios::out);
	if (!fin) return;
	fin.re
	fin.close();
}
void Table::Execute()
{
	switch (mCurrentAction)
	{
	case Table::UserActions::move_up:
		mConMoveUp();
		break;
	case Table::UserActions::move_down:
		mConMoveDown();
		break;
	case Table::UserActions::move_right:
		mConMoveRight();
		break;
	case Table::UserActions::move_left:
		mConMoveLeft();
		break;
	case Table::UserActions::input:
		break;
	case Table::UserActions::create_lesson:
		mConCreateLesson();
		break;
	case Table::UserActions::create_homework:
		mConCreateHomework();
		break;
	case Table::UserActions::erase_lesson:
		mConEraseLesson();
		break;
	case Table::UserActions::erase_homework:
		mConEraseHomework();
		break;
	case Table::UserActions::select_homework:
		mConSelectHomework();
		break;
	case Table::UserActions::save:
		break;
	case Table::UserActions::load:
		break;
	default:
		mConNothing();
		break;
	}
}

