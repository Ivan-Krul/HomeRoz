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
	auto cur_pos = mCalculateCursorPos();
	// UNDONE: Need also made output for render
	return mWindow;
}
