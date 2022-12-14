#include "date.h"

Date::Date(Month month, short day)
{
	mMonth = month;
	mDay = day;
}
Date::Date(short month, short day)
{
	mMonth = static_cast<Month>(month);
	mDay = day;
}
short Date::ConvertDateToDays()
{
	short days = 0;
	for (char month_i = static_cast<char>(mMonth) - 1; month_i >= 0; month_i--)
		days += ConvertMonthDays(static_cast<Month>(month_i));
	days += mDay;
	return days;
}
short Date::ConvertMonthDays(Month month)
{
	switch (month)
	{
		case Date::Month::january:		return 31;
		case Date::Month::february:		return 28;
		case Date::Month::march:		return 31;
		case Date::Month::april:		return 30;
		case Date::Month::may:			return 31;
		case Date::Month::june:			return 30;
		case Date::Month::july:			return 31;
		case Date::Month::august:		return 31;
		case Date::Month::september:	return 30;
		case Date::Month::october:		return 31;
		case Date::Month::november:		return 30;
		case Date::Month::december:		return 31;
		default:						return 30;
	}
}
std::string Date::ConvertMonthToString()
{
	switch (mMonth)
	{
		case Date::Month::january:		return "Jan";
		case Date::Month::february:		return "Feb";
		case Date::Month::march:		return "Mar";
		case Date::Month::april:		return "Apr";
		case Date::Month::may:			return "May";
		case Date::Month::june:			return "Jun";
		case Date::Month::july:			return "Jul";
		case Date::Month::august:		return "Aug";
		case Date::Month::september:	return "Sep";
		case Date::Month::october:		return "Oct";
		case Date::Month::november:		return "Nov";
		case Date::Month::december:		return "Dec";
		default:						return "Def";
	}
}
short Date::getDay()
{
	return mDay;
}
Date::Month Date::getMonth()
{
	return mMonth;
}
void Date::setDay(short day)
{
	if (mDay >= ConvertMonthDays(mMonth))
		day = ConvertMonthDays(mMonth) - 1;
	else if (mDay < 0)
		mDay = 0;
	else
		mDay = day;	
}
void Date::setMonth(Month month)
{
	mMonth = month;
}
void Date::setMonth(short month)
{
	if (month >= 12)
		mMonth = Month::december;
	else if (month < 0)
		mMonth = Month::january;
	else
		mMonth = static_cast<Month>(month);
}
void Date::Test()
{
	mTestConvertDateToDays0();
	mTestConvertDateToDays1();
}
void Date::SetCurrentTime()
{
	time_t now = time(0);
	tm* gmtm = gmtime(&now);
	mMonth = static_cast<Month>(gmtm->tm_mon);
	mDay = gmtm->tm_mday;
}
std::string Date::FormatToString()
{
	std::string string;
	string = std::to_string(mDay);
	string += ' ';
	string += ConvertMonthToString();
	return string;
}
Date& Date::operator=(const Date& some)
{
	mDay = some.mDay;
	mMonth = some.mMonth;
	return *this;
}
void Date::mTestConvertDateToDays0()
{
	short days;
	Date date;
	date.mMonth = Month::march;
	date.mDay = 5;
	days = ConvertMonthDays(Month::february);
	days += ConvertMonthDays(Month::january);
	days += 5;
	assert(date.ConvertDateToDays() == days);
#ifdef IOSTREAM
	std::cout << __FUNCTION__ << ": (" << date.mDay << ' ' << date.ConvertMonthToString() << ") done\n";
#endif // IOSTREAM
}
void Date::mTestConvertDateToDays1()
{
	short days;
	Date date;
	date.mMonth = Month::december;
	date.mDay = 25;
	days = ConvertMonthDays(Month::november);
	days += ConvertMonthDays(Month::october);
	days += ConvertMonthDays(Month::september);
	days += ConvertMonthDays(Month::august);
	days += ConvertMonthDays(Month::july);
	days += ConvertMonthDays(Month::june);
	days += ConvertMonthDays(Month::may);
	days += ConvertMonthDays(Month::april);
	days += ConvertMonthDays(Month::march);
	days += ConvertMonthDays(Month::february);
	days += ConvertMonthDays(Month::january);
	days += 25;
	assert(date.ConvertDateToDays() == days);
#ifdef IOSTREAM
	std::cout << __FUNCTION__ << ": (" << date.mDay << ' ' << date.ConvertMonthToString() << ") done\n";
#endif // IOSTREAM
}

