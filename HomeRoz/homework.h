#pragma once
#include <string>
#include "date.h"
#include "lesson.h"
class Homework
{
	bool done_;
	//Lesson* plesson_;
	date_week::Date from_date_;
	date_week::Date to_date_;
	std::string context_;
public:
	std::string GetContex();
	bool GetDone();
	//Lesson* GetLesson();
	date_week::Date GetToDate();
	date_week::Date GetFromDate();
	void SetContex(std::string context);
	//void SetLesson(Lesson* pLesson);
	void SetToDate(date_week::Date toDate);
	void SetFromDate(date_week::Date fromDate);
	void MarkDone();
};

