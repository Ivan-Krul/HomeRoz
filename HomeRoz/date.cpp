#include "date.h"

date_week::Date::Date(Month month, short day)
{
	mMonth = month;
	mDay = day;
}

date_week::Date::Date(short month, short day)
{
	mMonth = static_cast<Month>(month);
	mDay = day;
}

short date_week::Date::ConvertDateToDays()
{
	short days = 0;
	for (char month_i = static_cast<char>(mMonth) - 1; month_i >= 0; month_i--)
		days += ConvertMonthDays(static_cast<Month>(month_i));
	days += mDay;
	return days;
}

short date_week::Date::ConvertMonthDays(Month month)
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

std::string date_week::Date::ConvertMonthToString()
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

short date_week::Date::GetDay()
{
	return mDay;
}

date_week::Date::Month date_week::Date::GetMonth()
{
	return mMonth;
}

void date_week::Date::SetDay(short day)
{
	if (mDay >= ConvertMonthDays(mMonth))
		day = ConvertMonthDays(mMonth) - 1;
	else if (mDay < 0)
		mDay = 0;
	else
		mDay = day;	
}

void date_week::Date::SetMonth(Month month)
{
	mMonth = month;
}

void date_week::Date::SetMonth(short month)
{
	if (month >= 12)
		mMonth = Month::december;
	else if (month < 0)
		mMonth = Month::january;
	else
		mMonth = static_cast<Month>(month);
}

void date_week::Date::SetCurrentTime()
{
	time_t now = time(0);
	tm* gmtm = gmtime(&now);
	mMonth = static_cast<Month>(gmtm->tm_mon);
	mDay = gmtm->tm_mday;
}

date_week::Date& date_week::Date::operator=(const Date& some)
{
	mDay = some.mDay;
	mMonth = some.mMonth;
	return *this;
}

