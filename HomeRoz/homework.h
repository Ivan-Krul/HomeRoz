#pragma once
#include "date.h"
#include "lesson.h"
#include <string>
class Homework
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
	void setContex(std::string str);
	void setLesson(Lesson* lesson);
	void setToDate(Date toDate);
	void setFromDate(Date fromDate);
	void MarkDone();
	std::string FormatToString();
};

