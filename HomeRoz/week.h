#pragma once
#include <chrono>
#include <string>
#pragma warning(disable : 4996)
namespace date_week
{
	enum class Week
	{
		monday = 0,
		tuesday,
		wednesday,
		thursday,
		friday,
		saturday,
		sunday
	};
	inline Week WeekSetCurrentTime()
	{
		time_t now = time(0);
		tm* gmtm = gmtime(&now);
		return static_cast<Week>(gmtm->tm_wday-1);
	}
	inline std::string WeekToString(Week week)
	{
		switch (week)
		{
		case Week::monday:		return "Mon";
		case Week::tuesday:		return "Tue";
		case Week::wednesday:	return "Wed";
		case Week::thursday:	return "Thu";
		case Week::friday:		return "Fri";
		case Week::saturday:	return "Sat";
		case Week::sunday:		return "Sun";
		default:				return "Def";
		}
	}
}

