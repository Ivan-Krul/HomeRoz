#include "homemgr.h"

bool HomeMGR::CheckHomework_(size_t lesson_index, size_t homework_index)
{
	if (lesson_index < SizeLessons())
		return homework_index < SizeHomeworks(lesson_index);
	return false;
}

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
	if (CheckHomework_(lesson_index,homework_index))
		return &homeworks_[lesson_index][homework_index];
	return nullptr;
}

void HomeMGR::PushLesson()
{
	Lesson lesson;
	std::vector<Homework> homeworks;
	lessons_.push_back(lesson);
	homeworks_.push_back(homeworks);
}

void HomeMGR::Clear()
{
	lessons_.clear();
	homeworks_.clear();
}

bool HomeMGR::PushHomework(size_t lesson_index)
{
	Homework homework;
	if (!(lesson_index < SizeLessons()))
		return false;
	homeworks_[lesson_index].push_back(homework);
	return true;
}

bool HomeMGR::PopLesson(size_t index)
{
	if (!(index < SizeLessons()))
		return false;
	lessons_.erase(lessons_.begin() + index);
	homeworks_.erase(homeworks_.begin() + index);
	return true;	
}

bool HomeMGR::PopHomework(size_t lesson_index, size_t homework_index)
{
	if (!CheckHomework_(lesson_index, homework_index))
		return false;
	homeworks_[lesson_index].erase(homeworks_[lesson_index].begin() + homework_index);
	return true;
}

bool HomeMGR::SetLesson(size_t index, Lesson lesson)
{
	if(!(index < SizeLessons()))
		return false;
	lessons_[index] = lesson;
	return true;
}

bool HomeMGR::SetHomework(size_t lesson_index, size_t homework_index, Homework homework)
{
	if (!CheckHomework_(lesson_index, homework_index))
		return false;
	homeworks_[lesson_index][homework_index] = homework;
	return true;
}

bool HomeMGR::SetLessonName(size_t lesson_index, std::string name)
{
	if (!(lesson_index < SizeLessons()))
		return false;
	lessons_[lesson_index].SetName(name);
	return true;
}

bool HomeMGR::SetLessonLink(size_t lesson_index, std::string link)
{
	if(!(lesson_index < SizeLessons()))
		return false;
	lessons_[lesson_index].SetLink(link);
	return true;
}

bool HomeMGR::SetHomeworkContext(size_t lesson_index, size_t homework_index, std::string context)
{
	if(!(CheckHomework_(lesson_index, homework_index)))
		return false;
	homeworks_[lesson_index][homework_index].SetContex(context);
	return true;
}

bool HomeMGR::SetHomeworkDateFrom(size_t lesson_index, size_t homework_index, date_week::Date date)
{
	if(!(CheckHomework_(lesson_index, homework_index)))
		return false;
	homeworks_[lesson_index][homework_index].SetFromDate(date);
	return true;
}

bool HomeMGR::SetHomeworkDateTo(size_t lesson_index, size_t homework_index, date_week::Date date)
{
	if (!(CheckHomework_(lesson_index, homework_index)))
		return false;
	homeworks_[lesson_index][homework_index].SetFromDate(date);
	return true;
}

bool HomeMGR::SetHomeworkDone(size_t lesson_index, size_t homework_index, bool done)
{
	if (!(CheckHomework_(lesson_index, homework_index)))
		return false;
	homeworks_[lesson_index][homework_index].SetDone(done);
	return true;
}
