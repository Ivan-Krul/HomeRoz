#pragma once
#include "date.h"
#include "lesson.h"
#include <string>
class Homework
{
	bool done_;
	Lesson* plesson_;
	Date from_date_;
	Date to_date_;
	std::string context_;
public:
	std::string GetContex();
	bool GetDone();
	Lesson* GetLesson();
	Date GetToDate();
	Date GetFromDate();
	void SetContex(std::string context);
	void SetLesson(Lesson* pLesson);
	void SetToDate(Date toDate);
	void SetFromDate(Date fromDate);
	void MarkDone();
};

