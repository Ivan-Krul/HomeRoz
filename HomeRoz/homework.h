#pragma once
#include "date.h"
#include "lesson.h"
#include "iformattostring.h"
#include <string>
class Homework : IFormatToString
{
	bool mDone;
	Lesson* mpLesson;
	Date mFromDate;
	Date mToDate;
	std::string mContext;
public:
	std::string getContex();
	bool getDone();
	Lesson* getLesson();
	Date getToDate();
	Date getFromDate();
	void setContex(std::string context);
	void setLesson(Lesson* pLesson);
	void setToDate(Date toDate);
	void setFromDate(Date fromDate);
	void MarkDone();
	std::string FormatToString();
};

