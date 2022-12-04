#pragma once
#include "homework.h"
#include "lesson.h"
#include "homeworkselect.h"
#include <list>
#include <fstream>
class Table
{
public:
	enum class UserActions;
	enum class LineChoose;
private:
	HomeworkSelect mHomeworkSelect;
	std::string mInputString;
	UserActions mCurrentAction = UserActions::nothing;
	LineChoose mLineChoose;
	std::list<Lesson>::iterator mIterLesson = mHomeworkSelect.getLessonList().begin();
	std::list<Homework>::iterator mIterHomework;
	bool mIsSelectHW = false;
	bool mIsInputAwait = false;
	bool mIsInputBufferise = false;
private:
	std::string mWriteStrBinaryFin(std::ifstream& fin);
	Date mWriteDateBinaryFin(std::ifstream& fin);
private:
	void mConNothing();
	void mConMoveUp();
	void mConMoveDown();
	void mConMoveLeft();
	void mConMoveRight();
	void mConCreateLesson();
	void mConCreateHomework();
	void mConSelectHomework();
	void mConEraseLesson();
	void mConEraseHomework();
	void mConSave();
	void mConLoad();
public:
	void SenseControl(UserActions action);
	void Execute();
public:
	enum class LineChoose
	{
		lesson,
		link,
		weeks,
		homework,
		from_date,
		to_date,
		done
	};
	enum class UserActions
	{
		nothing,
		move_up,
		move_down,
		move_right,
		move_left,
		input,
		input_buffer,
		create_lesson,
		create_homework,
		erase_lesson,
		erase_homework,
		select_homework,
		save,
		load
	};
};     
