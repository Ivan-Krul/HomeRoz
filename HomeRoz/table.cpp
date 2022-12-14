#include "table.h"
std::string Table::mWriteStrBinaryFin(std::ifstream& fin)
{
	std::string str;
	size_t size = 0;
	fin.read((char*)size, sizeof(size));
	str.resize(size);
	fin.read((char*)str.c_str(), size);
	return str;
}
Date Table::mWriteDateBinaryFin(std::ifstream& fin)
{
	Date date;
	unsigned short day = 0;
	Date::Month month = Date::Month::january;
	fin.read((char*)day, sizeof(day));
	fin.read((char*)month, sizeof(month));
	date.setDay(day);
	date.setMonth(month);
	return date;
}
Date Table::mFromStringToDate(std::string str)
{
	Date date;
	std::string sday = str.substr(0, 2);
	std::string smonth;
	if (sday[1] == ' ')
	{
		sday.erase(1);
		smonth = str.substr(2, 3);
	}
	smonth = str.substr(3, 3);
	date.setDay(std::stoi(sday));
	if (smonth == "Jan")
		date.setMonth(Date::Month::january);
	else if (smonth == "Feb")
		date.setMonth(Date::Month::february);
	else if (smonth == "Mar")
		date.setMonth(Date::Month::march);
	else if (smonth == "Apr")
		date.setMonth(Date::Month::april);
	else if (smonth == "May")
		date.setMonth(Date::Month::may);
	else if (smonth == "Jun")
		date.setMonth(Date::Month::june);
	else if (smonth == "Jul")
		date.setMonth(Date::Month::july);
	else if (smonth == "Aug")
		date.setMonth(Date::Month::august);
	else if (smonth == "Sep")
		date.setMonth(Date::Month::september);
	else if (smonth == "Oct")
		date.setMonth(Date::Month::october);
	else if (smonth == "Nov")
		date.setMonth(Date::Month::november);
	else if (smonth == "Dec")
		date.setMonth(Date::Month::december);
	return date;
}
std::vector<Week> Table::mStringToListWeek(std::string str)
{
	std::vector<Week> weeks;
	std::string weekstr = "Def";
	auto checked = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!checked)
		{
			weekstr = str.substr(i, 3);
			if (weekstr == "Mon")
				weeks.push_back(Week::monday);
			else if (weekstr == "Tue")
				weeks.push_back(Week::tuesday);
			else if (weekstr == "Wed")
				weeks.push_back(Week::wednesday);
			else if (weekstr == "Thu")
				weeks.push_back(Week::thursday);
			else if (weekstr == "Fri")
				weeks.push_back(Week::friday);
			else if (weekstr == "Sat")
				weeks.push_back(Week::saturday);
			else if (weekstr == "Sun")
				weeks.push_back(Week::sunday);
			checked = true;
		}
		else if (str[i] == '/')
			checked = false;
	}
	return weeks;
}
std::string Table::mListWeekToString(std::vector<Week>::iterator begin, std::vector<Week>::iterator end)
{
	std::string str;
	auto week = begin;
	str += WeekToString(*week);
	week++;
	for (week; week != end; week++)
	{
		str += '/';
		str += WeekToString(*week);
	}
	return str;
}
Homework Table::mWriteHomeworkFromBinary(std::ifstream& fin, Lesson& lesson)
{
	Homework homework;
	homework.setLesson(&lesson);
	homework.setContex(mWriteStrBinaryFin(fin));
	homework.setFromDate(mWriteDateBinaryFin(fin));
	homework.setToDate(mWriteDateBinaryFin(fin));
	bool is_done = false;
	fin.read((char*)is_done, sizeof(is_done));
	if (is_done)
		homework.MarkDone();
	return homework;
}
bool Table::mSortHomeworkByDate(Homework& hw1, Homework& hw2)
{
	// 1 Jan < 31 Dec
	return hw1.getToDate().ConvertDateToDays() < hw2.getToDate().ConvertDateToDays();
}
void Table::SenseControl(UserActions action)
{
	mCurrentAction = action;
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
		mConInput();
		break;
	case Table::UserActions::input_buffer:
		mConInputBuffer();
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
		mConSave();
		break;
	case Table::UserActions::load:
		mConLoad();
		break;
	default:
		mConNothing();
		break;
	}
}
bool Table::getIsSelectHW() {
	return mIsSelectHW;
}
bool Table::getIsInputAwait() {
  return mIsInputAwait;
}
bool Table::getIsInputBufferise() {
  return mIsInputBufferise;
}
std::string& Table::GiveInput()
{
	if (!mIsInputBufferise) {
		switch (mLineChoose)
		{
			case Table::LineChoose::lesson:
				mInputString = mIterLesson->getName();
				break;
			case Table::LineChoose::link:
				mInputString = mIterLesson->getLink();
				break;
			case Table::LineChoose::weeks:
				mInputString = mListWeekToString(mIterLesson->BeginWeeks(), mIterLesson->EndWeeks());
				break;
			case Table::LineChoose::homework:
				mInputString = mIterHomework->getContex();
				break;
			case Table::LineChoose::from_date:
				mInputString = mIterHomework->getFromDate().FormatToString();
				break;
			case Table::LineChoose::to_date:
				mInputString = mIterHomework->getToDate().FormatToString();
				break;
			case Table::LineChoose::done:
				mIterHomework->MarkDone();
				mIsInputAwait = false;
				break;
		}
	}
	if (!mIsInputAwait)
		return mInputBuffer;
	else
		return mInputString;
}
void Table::CheckInput()
{
	if (mIsInputBufferise)
	{
		mInputBuffer = mInputString;
		mConInputBuffer();
	}
	else
	{
		switch (mLineChoose)
		{
			case Table::LineChoose::lesson:
				mIterLesson->setName(mInputString);
				break;
			case Table::LineChoose::link:
				mIterLesson->setLink(mInputString);
				break;
			case Table::LineChoose::weeks:
				{
					auto weeks = mStringToListWeek(mInputString);
					for (int i = 0; i < mIterLesson->SizeWeek(); i++)
						mIterLesson->PopWeek(mIterLesson->BeginWeeks());
					for (auto& week : weeks)
						mIterLesson->PushWeek(week);
				}
				break;
			case Table::LineChoose::homework:
				mIterHomework->setContex(mInputString);
				break;
			case Table::LineChoose::from_date:
				mIterHomework->setFromDate(mFromStringToDate(mInputString));
				break;
			case Table::LineChoose::to_date:
				mIterHomework->setToDate(mFromStringToDate(mInputString));
				break;
			case Table::LineChoose::done:
				mIterHomework->MarkDone();
				break;
		}
	}
	mConInput();
	mConNothing();
}
Table::LineChoose Table::getLineChoose()
{
	return mLineChoose;
}
const HomeworkSelect Table::getHomeworkSelect()
{
	return mHomeworkSelect;
}
const std::list<Lesson>::iterator Table::getIterLesson()
{
	return mIterLesson;
}
const std::list<Homework>::iterator Table::getIterHomework()
{
	return mIterHomework;
}
std::list<Homework> Table::getLatestHomework()
{
	std::list<Homework> latesthw;
	auto lesson_list = mHomeworkSelect.getLessonList();
	for (auto lesson = lesson_list.begin(); lesson != lesson_list.end(); lesson++)
	{
		// First need to sort by date,...
		// then, we're parse from end to begin...
		// and search the nearest future homework
		// and push in list
		auto homework_list = mHomeworkSelect.getHomeworkList(*lesson);
		//std::sort(homework_list.begin(), homework_list.end(), mSortHomeworkByDate);
		Date current_date;
		current_date.SetCurrentTime();
		auto homework = homework_list.begin();
		for (homework; homework != homework_list.end(); homework++)
			if ((homework->getToDate().ConvertDateToDays() - current_date.ConvertDateToDays()) > 0)
				break;
		if (homework != homework_list.end())
			homework--;
		latesthw.push_back(*homework);
	}
	return latesthw;
}

