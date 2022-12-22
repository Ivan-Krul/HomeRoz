#include "homemgr.h"

size_t HomeMGR::SizeLessons()
{
	return size_t();
}

size_t HomeMGR::SizeHomeworks(size_t lesson_index)
{
	return size_t();
}

Lesson HomeMGR::GetLesson(size_t index)
{
	return Lesson();
}

Homework HomeMGR::GetHomework(size_t lesson_index, size_t homework_index)
{
	return Homework();
}

void HomeMGR::PushLesson()
{
}

void HomeMGR::PushHomework(size_t lesson_index)
{
}

void HomeMGR::PopLesson(size_t index)
{
}

void HomeMGR::PopHomework(size_t lesson_index, size_t homework_index)
{
}

void HomeMGR::SetLesson(size_t index, Lesson lesson)
{
}

void HomeMGR::SetHomework(size_t lesson_index, size_t homework_index, Homework homework)
{
}

void HomeMGR::SetLessonName(size_t lesson_index, std::string name)
{
}

void HomeMGR::SetLessonLink(size_t lesson_index, std::string link)
{
}

void HomeMGR::SetHomeworkContext(size_t lesson_index, size_t homework_index, std::string context)
{
}

void HomeMGR::SetHomeworkDateFrom(size_t lesson_index, size_t homework_index, date_week::Date date)
{
}

void HomeMGR::SetHomeworkDateTo(size_t lesson_index, size_t homework_index, date_week::Date date)
{
}

void HomeMGR::SetHomeworkDone(size_t lesson_index, size_t homework_index, bool done)
{
}
