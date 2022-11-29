#include "homework.h"
std::string Homework::getContex()
{
	return mContext;
}
bool Homework::getDone()
{
	return mDone;
}
Lesson* Homework::getLesson()
{
	return mpLesson;
}
Date Homework::getToDate()
{
	return mToDate;
}
Date Homework::getFromDate()
{
	return mFromDate;
}
void Homework::setContex(std::string context)
{
	mContext = context;
}
void Homework::setLesson(Lesson* pLesson)
{
	mpLesson = pLesson;
}
void Homework::setToDate(Date toDate)
{
	mToDate = toDate;
}
void Homework::setFromDate(Date fromDate)
{
	mFromDate = fromDate;
}
void Homework::MarkDone()
{
	mDone = !mDone;
}
std::string Homework::FormatToString()
{
	/*	UNDONE	*/
	return std::string();
}
