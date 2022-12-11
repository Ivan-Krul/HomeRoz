#include "tablerend.h"
COORD TableRend::mCalculateCursorPos()
{
	// calculate cursor position
	if (mIsHWSelectInput)
		if (mIsAwaitInput)
			return mCalculateCurPosYInpYSel();
		else
			return mCalculateCurPosNInpYSel();
	else
		if (mIsAwaitInput)
			return mCalculateCurPosYInpNSel();
		else
			mCalculateCurPosNInpNSel();
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
COORD TableRend::mCalculateCurPosYInpYSel()
{
	COORD cursor_pos = { 0,0 };
	// X cursor
	cursor_pos.X += 2; // #####: #####
	if (!mIsBufInput) 
	{
		switch (mCurHor)
		{
			case Table::LineChoose::homework: // *lesson/homework: |
				cursor_pos.X += mCurVertHomework->getLesson()->getName().size();
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 8;
				break;
			case Table::LineChoose::from_date: // *lesson/homework/from_date: |
				cursor_pos.X += mCurVertHomework->getLesson()->getName().size();
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 8;
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 9;
				break;
			case Table::LineChoose::to_date: // *lesson/homework/to_date: |
				cursor_pos.X += mCurVertHomework->getLesson()->getName().size();
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 8;
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 7;
				break;
		}
	}
	else
		cursor_pos.X += 6; // Buffer
	cursor_pos.X += mCurInputPos;
	// Y cursor
	cursor_pos.Y += mHomeworkSelect.getHomeworkList(*mCurVertLesson).size();
	cursor_pos.Y++;
	return cursor_pos;
}
COORD TableRend::mCalculateCurPosYInpNSel()
{
	COORD cursor_pos = { 0,0 };
	// X cursor
	cursor_pos.X += 2; // #####: #####
	if (!mIsBufInput)
	{
		switch (mCurHor)
		{
			case Table::LineChoose::lesson: // *lesson: |
				cursor_pos.X += mCurVertLesson->getName().size();
				break;
			case Table::LineChoose::link: // *lesson/link: |
				cursor_pos.X += mCurVertLesson->getName().size();
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 4;
				break;
			case Table::LineChoose::weeks: // *lesson/weeks: |
				cursor_pos.X += mCurVertLesson->getName().size();
				cursor_pos.X += mInputSplitter.size();
				cursor_pos.X += 5;
				break;
		}
	}
	else
		cursor_pos.X += 6; // Buffer
	cursor_pos.X += mCurInputPos;
	// Y cursor
	cursor_pos.Y += mHomeworkSelect.getHomeworkList(*mCurVertLesson).size();
	cursor_pos.Y++;
	return cursor_pos;
}