#include "tablerend.h"
std::string TableRend::mCompareInput()
{
	std::string input_row = mCurVertLesson->getName();

	switch (mCurHor)
	{
		case Table::LineChoose::link:
			input_row += mInputSplitter;
			input_row += "link";
			break;
		case Table::LineChoose::weeks:
			input_row += mInputSplitter;
			input_row += "weeks";
			break;
		case Table::LineChoose::homework:
			input_row += mInputSplitter;
			input_row += "homework";
			break;
		case Table::LineChoose::from_date:
			input_row += mInputSplitter;
			input_row += "homework";
			input_row += mInputSplitter;
			input_row += "from date";
			break;
		case Table::LineChoose::to_date:
			input_row += mInputSplitter;
			input_row += "homework";
			input_row += mInputSplitter;
			input_row += "to date";
			break;
	}
	input_row += ": ";
	input_row += mInput;
	return input_row;
}
std::list<std::string> TableRend::mCompareToRows()
{
	std::list<std::string> rows;
	if (mIsHWSelectInput)
	{
		auto homework_list = mHomeworkSelect.getHomeworkList(*mCurVertLesson);
		auto homework = homework_list.begin();
		for (homework; homework != homework_list.end(); homework++)
			rows.push_back(homework->FormatToString());
	}
	else
	{
		auto lesson_list = mHomeworkSelect.getLessonList();
		auto lesson = lesson_list.begin();
		auto latest_hw = mLatestHomework.begin();
		for ((lesson, latest_hw); lesson != lesson_list.end() && latest_hw != mLatestHomework.end(); (lesson++, latest_hw++))
		{
			std::string row;
			row = lesson->FormatToString();
			row += latest_hw->FormatToString();
			rows.push_back(row);
		}
	}
	if (mIsAwaitInput)
	{
		rows.push_back("---------------------------");
		rows.push_back(mCompareInput());
	}
	return rows;
}
void TableRend::setHomeworkSelect(HomeworkSelect hwselect)
{
	mHomeworkSelect = hwselect;
}
void TableRend::setInput(std::string input)
{
	mInput = input;
}
void TableRend::setLineChoose(Table::LineChoose lineChoose)
{
	mCurHor = lineChoose;
}
void TableRend::setIterLesson(std::list<Lesson>::iterator lesson)
{
	mCurVertLesson = lesson;
}
void TableRend::setIterHomework(std::list<Homework>::iterator homework)
{
	mCurVertHomework = homework;
}
void TableRend::setLatestHomework(std::list<Homework> listLatestHW)
{
	mLatestHomework = listLatestHW;
}
void TableRend::setInputCurPos(size_t curpos)
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
	// We divide rows in array of strings
	auto rows = mCompareToRows();
	// And render it
	size_t y = 0;
	for (auto row = rows.begin(); row != rows.end(); row++)
	{
		for (int i = 0; i < row->size(); i++)
			mWindow[i + y * mWindow.size().X] = (*row)[i];
	}
	return mWindow;
}
COORD TableRend::getCursorCoord()
{
	return mCalculateCursorPos();
}