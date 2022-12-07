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
void TableRend::getIterHomework(std::list<Homework>::iterator homework)
{
	mCurVertHomework = homework;
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
	// calculate cursor position
	COORD cursor_pos = { 0,0 };
	if (!mIsHWSelectInput)
	{
		// X of cursor
		switch (mCurHor)
		{
			case Table::LineChoose::done:
			case Table::LineChoose::to_date:
			case Table::LineChoose::from_date:
			case Table::LineChoose::homework:
			case Table::LineChoose::weeks:
				{
					int chars = 0;
					for (auto weeks = mCurVertLesson->BeginWeeks(); weeks != mCurVertLesson->EndWeeks(); (weeks++, chars += 4));
					chars--;
					cursor_pos.X += chars;
					cursor_pos.X += mSpaceSize;
				}
			case Table::LineChoose::link:
				cursor_pos.X += mCurVertLesson->getName().size();
				cursor_pos.X += mSpaceSize;
			case Table::LineChoose::lesson:
				break;
			default:
				break;
		}
		// Y of cursor
		auto lessons = mHomeworkSelect.getLessonList();
		size_t lesson = 0;
		for (auto iter_lessons = lessons.begin(); iter_lessons != mCurVertLesson && iter_lessons != lessons.end(); (lesson++, iter_lessons++));
		cursor_pos.Y = lesson;
	}
	else
	{

	}
	/*  UNDONE  */
	return mWindow;
}
