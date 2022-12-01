#pragma once
#include "homework.h"
#include "lesson.h"
#include <list>
class Table
{
public:
	enum class UserActions;
	enum class LineChoose;
private:
	std::list<Homework> mHomeworks;
	std::list<Lesson> mLessons;
	std::string mInputString;
	UserActions mCurrentAction = UserActions::nothing;
	LineChoose mLineChoose;
	std::list<Lesson>::iterator mIterLesson = mLessons.begin();
private:
	void mConNothing();
	void mConMoveUp();
	void mConMoveDown();
	void mConMoveLeft();
	void mConMoveRight();
	void mConCreateLesson();
	void mConCreateHomework();
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
		create_lesson,
		create_homework,
		erase_lesson,
		erase_homework,
		select_homework,
		save,
		load
	};
};     
