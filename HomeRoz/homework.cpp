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
Homework& Homework::operator=(const Homework& some)
{
	mContext = some.mContext;
	mpLesson = some.mpLesson;
	mFromDate = some.mFromDate;
	mToDate = some.mToDate;
	mDone = some.mDone;
	return *this;
}
std::string Homework::FormatToString()
{
	std::string string;
	string = mContext;
	string += " | ";
	string += mFromDate.FormatToString();
	string += " | ";
	string += mToDate.FormatToString();
	string += " | ";
	string += mDone ? "done" : "dont";
	return string;
}
