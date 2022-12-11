#pragma once
#include "homework.h"
#include "lesson.h"
#include "homeworkselect.h"
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
class Table
{
public:
	enum class UserActions;
	enum class LineChoose;
private:
	HomeworkSelect mHomeworkSelect;
	std::string mInputString;
	std::string mInputBuffer;
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
	Date mFromStringToDate(std::string str);
	std::vector<Week> mStringToListWeek(std::string str);
	std::string mListWeekToString(std::vector<Week>::iterator begin, std::vector<Week>::iterator end);
	Homework mWriteHomeworkFromBinary(std::ifstream& fin, Lesson& lesson);
	bool mSortHomeworkByDate(Homework& hw1, Homework& hw2);
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
	void mConInput();
	void mConInputBuffer();
public:
	void SenseControl(UserActions action);
	void Execute();
	std::string& GiveInput();
	void CheckInput();
	LineChoose getLineChoose();
	const HomeworkSelect getHomeworkSelect();
	const std::list<Lesson>::iterator getIterLesson();
	const std::list<Homework>::iterator getIterHomework();
	std::list<Homework> getLatestHomework();
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
#include "tablecon.cpp"