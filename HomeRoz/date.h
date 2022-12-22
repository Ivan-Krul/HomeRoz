#pragma once
#include <cassert>
#include <chrono>
#include <string>
#pragma warning(disable : 4996)
class Date
{
public:
	enum class Month;
private:
	Month mMonth;
	unsigned short mDay;
public:
	Date(Month month, short day);
	Date(short month, short day);
	Date() = default;
	short ConvertDateToDays();
	short ConvertMonthDays(Month month);
	std::string ConvertMonthToString();
	short GetDay();
	Month GetMonth();
	void SetDay(short day);
	void SetMonth(Month month);
	void SetMonth(short month);
	void SetCurrentTime();
	Date& operator=(const Date& some);
	enum class Month
	{
		january = 0,
		february,
		march,
		april,
		may,
		june,
		july,
		august,
		september,
		october,
		november,
		december
	};
};
