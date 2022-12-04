#include "table.h"
std::string Table::mWriteStrBinaryFin(std::ifstream& fin)
{
	std::string str;
	size_t size;
	fin.read((char*)size, sizeof(size));
	str.resize(size);
	fin.read((char*)str.c_str(), size);
	return str;
}
Date Table::mWriteDateBinaryFin(std::ifstream& fin)
{
	Date date;
	unsigned short day;
	Date::Month month;
	fin.read((char*)day, sizeof(day));
	fin.read((char*)month, sizeof(month));
	date.setDay(day);
	date.setMonth(month);
	return date;
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
		break;
	case Table::UserActions::input_buffer:
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
std::string& Table::GiveInput()
{
	switch (mLineChoose)
	{
	case Table::LineChoose::lesson:
		mInputString = mIterLesson->getName();
		break;
	case Table::LineChoose::link:
		mInputString = mIterLesson->getLink();
		break;
	case Table::LineChoose::weeks: 
		{
			auto week = mIterLesson->BeginWeeks();
			mInputString += WeekToString(*week);
			week++;
			for (week; week != mIterLesson->EndWeeks(); week++)
			{
				mInputString += '/';
				mInputString += WeekToString(*week);
			}
		}
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
	if (!mIsInputAwait)
		return mInputBuffer;
	else
		return mInputString;
}
void Table::CheckInput()
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
			std::vector<Week> weeks;
			std::string weekstr = "Def";
			auto checked = false;
			for (size_t i = 0;i < mInputString.size();i++)
			{
				if (!checked)
				{
					weekstr = mInputString.substr(i, 3);
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
				else if (mInputString[i] == '/')
					checked = false;
			}
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
		{
			Date date;
			std::string sday = mInputString.substr(0,2);
			std::string smonth;
			if (sday[1] == ' ') 
			{
				sday.erase(1);
				smonth = mInputString.substr(2, 3);
			}
			smonth = mInputString.substr(3, 3);
			date.setDay(std::stoi(sday));
			if (smonth == "Jan")
				date.setMonth(Date::Month::january);
			else if(smonth == "Feb")
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
			mIterHomework->setFromDate(date);
		}
		break;
	case Table::LineChoose::to_date:
		{
			Date date;
			std::string sday = mInputString.substr(0, 2);
			std::string smonth;
			if (sday[1] == ' ')
			{
				sday.erase(1);
				smonth = mInputString.substr(2, 3);
			}
			smonth = mInputString.substr(3, 3);
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
			mIterHomework->setToDate(date);
		}
		break;
	case Table::LineChoose::done:
		mIterHomework->MarkDone();
		break;
	}
}
Table::LineChoose Table::getLineChoose()
{
	return mLineChoose;
}

