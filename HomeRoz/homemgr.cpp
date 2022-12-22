#include "homemgr.h"

size_t HomeMGR::SizeLessons()
{
	return lessons_.size();
}

size_t HomeMGR::SizeHomeworks(size_t lesson_index)
{
	return homeworks_[lesson_index].size();
}

Lesson* HomeMGR::GetLesson(size_t index)
{
	if(index < SizeLessons())
		return &lessons_[index];
	return nullptr;
}

Homework* HomeMGR::GetHomework(size_t lesson_index, size_t homework_index)
{
	if (lesson_index < SizeLessons())
		if (homework_index < SizeHomeworks(lesson_index))
			return &homeworks_[lesson_index][homework_index];
	return nullptr;
}

void HomeMGR::PushLesson()
{
	Lesson lesson;
	lessons_.push_back(lesson);
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
