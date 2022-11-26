#include "date.h"

Date::Date(Month month, unsigned short day)
{
	this->month = month;
	this->day = day;
}
Date::Date(unsigned short month, unsigned short day)
{
	this->month = static_cast<Month>(month);
	this->day = day;
}
short Date::ConvertDateToDays()
{
	short days = 0;
	for (char month_i = static_cast<char>(month) - 1; month_i >= 0; month_i--)
		days += ConvertMonthDays(static_cast<Month>(month_i));
	days += day;
	return days;
}
unsigned short Date::ConvertMonthDays(Month month)
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
	switch (month)
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
void Date::Test()
{
	mTestConvertDateToDays0();
	mTestConvertDateToDays1();
}
void Date::mTestConvertDateToDays0()
{
	short days;
	Date date;
	date.month = Month::march;
	date.day = 5;
	days = ConvertMonthDays(Month::february);
	days += ConvertMonthDays(Month::january);
	days += 5;
	assert(date.ConvertDateToDays() == days);
#ifdef IOSTREAM
	std::cout << __FUNCTION__ << ": (" << date.day << ' ' << date.ConvertMonthToString() << ") done\n";
#endif // IOSTREAM
}
void Date::mTestConvertDateToDays1()
{
	short days;
	Date date;
	date.month = Month::december;
	date.day = 25;
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
	std::cout << __FUNCTION__ << ": (" << date.day << ' ' << date.ConvertMonthToString() << ") done\n";
#endif // IOSTREAM
}

