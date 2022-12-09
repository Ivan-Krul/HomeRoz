#include "tablerend.h"

void TableRend::getHomeworkSelect(HomeworkSelect hwselect)
{
	mHomeworkSelect = hwselect;
}
void TableRend::getInput(std::string input)
{
	mInput = input;
}
void TableRend::getLineChoose(Table::LineChoose lineChoose)
{
	mCurHor = lineChoose;
}
void TableRend::getIterLesson(std::list<Lesson>::iterator lesson)
{
	mCurVertLesson = lesson;
}
COORD TableRend::mCalculateCursorPos()
{
	// calculate cursor position
	if (mIsHWSelectInput)
		if (mIsAwaitInput)
			return COORD();
		else
			return mCalculateCurPosNInpYSel();
	else
		if (mIsAwaitInput)
			return COORD();
		else
			mCalculateCurPosNInpNSel();
}
void TableRend::getIterHomework(std::list<Homework>::iterator homework)
{
	mCurVertHomework = homework;
}
COORD TableRend::mCalculateCurPosNInpNSel()
{
	COORD cursor_pos = { 0,0 };
	// X of cursor
	switch (mCurHor)
	{
		case Table::LineChoose::weeks: // lesson_link_|
			cursor_pos.X += mCurVertLesson->getLink().size();
			cursor_pos.X += mSpaceSize;
		case Table::LineChoose::link: // lesson_|
			cursor_pos.X += mCurVertLesson->getName().size();
			cursor_pos.X += mSpaceSize;
		case Table::LineChoose::lesson: // |
			break;
	}
	// Y of cursor
	auto lessons = mHomeworkSelect.getLessonList();
	size_t lesson = 0;
	for (auto iter_lessons = lessons.begin(); iter_lessons != mCurVertLesson && iter_lessons != lessons.end(); (lesson++, iter_lessons++));
	cursor_pos.Y = lesson;
	return cursor_pos;
}
COORD TableRend::mCalculateCurPosNInpYSel()
{
	// UNDONE: modify this for divided on homework select
	COORD cursor_pos = { 0,0 };
	// X of cursor
	switch (mCurHor)
	{
		case Table::LineChoose::done: // hwcontext_from_date_to_date_|
			cursor_pos.X += mCurVertHomework->getToDate().FormatToString().size();
			cursor_pos.X += mSpaceSize;
		case Table::LineChoose::to_date: // hwcontext_from_date_|
			cursor_pos.X += mCurVertHomework->getFromDate().FormatToString().size();
			cursor_pos.X += mSpaceSize;
		case Table::LineChoose::from_date: // hwcontext_|
			cursor_pos.X += mCurVertHomework->getContex().size();
			cursor_pos.X += mSpaceSize;
		case Table::LineChoose::homework: // |
			break;
	}
	// Y of cursor
	auto homeworks = mHomeworkSelect.getLessonList();
	size_t homework = 0;
	for (auto iter_homeworks = homeworks.begin(); iter_homeworks != mCurVertLesson && iter_homeworks != homeworks.end(); (homework++, iter_homeworks++));
	cursor_pos.Y = homework;
	return cursor_pos;
}
void TableRend::getInputCurPos(size_t curpos)
{
	mCurInputPos = curpos;
}
void TableRend::HearBufferingInput(bool word)
{
	mIsBufInput = word;
}
void TableRend::HearAwaitingInput(bool word)
{
	mIsAwaitInput = word;
}
void TableRend::HearHWSelectMode(bool word)
{
	mIsHWSelectInput = word;
}
Window& TableRend::Render()
{
	auto cur_pos = mCalculateCursorPos();
	// UNDONE: Need also made output
	return mWindow;
}
