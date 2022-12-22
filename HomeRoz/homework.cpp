#include "homework.h"
std::string Homework::GetContex()
{
	return context_;
}
bool Homework::GetDone()
{
	return done_;
}
Lesson* Homework::GetLesson()
{
	return plesson_;
}
Date Homework::GetToDate()
{
	return to_date_;
}
Date Homework::GetFromDate()
{
	return from_date_;
}
void Homework::SetContex(std::string context)
{
	context_ = context;
}
void Homework::SetLesson(Lesson* pLesson)
{
	plesson_ = pLesson;
}
void Homework::SetToDate(Date toDate)
{
	to_date_ = toDate;
}
void Homework::SetFromDate(Date fromDate)
{
	from_date_ = fromDate;
}
void Homework::MarkDone()
{
	done_ = !done_;
}
Homework& Homework::operator=(const Homework& some)
{
	context_ = some.context_;
	plesson_ = some.plesson_;
	from_date_ = some.from_date_;
	to_date_ = some.to_date_;
	done_ = some.done_;
	return *this;
}
