#include "homework.h"
std::string Homework::GetContex()
{
	return context_;
}
bool Homework::GetDone()
{
	return done_;
}
//Lesson* Homework::GetLesson()
//{
//	return plesson_;
//}
date_week::Date Homework::GetToDate()
{
	return to_date_;
}
date_week::Date Homework::GetFromDate()
{
	return from_date_;
}
void Homework::SetContex(std::string context)
{
	context_ = context;
}
//void Homework::SetLesson(Lesson* pLesson)
//{
//	plesson_ = pLesson;
//}
void Homework::SetToDate(date_week::Date toDate)
{
	to_date_ = toDate;
}
void Homework::SetFromDate(date_week::Date fromDate)
{
	from_date_ = fromDate;
}
void Homework::MarkDone()
{
	done_ = !done_;
}
