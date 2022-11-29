#pragma once
#include <cassert>
#include <chrono>
#include <string>
#include "iformattostring.h"
#ifdef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM
class Date : public IFormatToString
{
public:
	enum class Month;
private:
	Month mMonth;
	unsigned short mDay;
	void mTestConvertDateToDays0();
	void mTestConvertDateToDays1();
public:
	Date(Month month, short day);
	Date(short month, short day);
	Date() = default;
	short ConvertDateToDays();
	short ConvertMonthDays(Month month);
	std::string ConvertMonthToString();
	short getDay();
	Month getMonth() {}
	void setDay(short day);
	void setMonth(Month month);
	void setMonth(short month);
	void Test();
	void SetCurrentTime();
	std::string FormatToString();
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
