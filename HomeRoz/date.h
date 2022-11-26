#pragma once
#include <cassert>
#include <string>
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

class Date
{
public:
	enum class Month;
	Date(Month month, unsigned short day);
	Date(unsigned short month, unsigned short day);
	Date() = default;
	Month month;
	unsigned short day : 5;
	short ConvertDateToDays();
	unsigned short ConvertMonthDays(Month month);
	std::string ConvertMonthToString();
	void Test();
private:
	void mTestConvertDateToDays0();
	void mTestConvertDateToDays1();
public:
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

