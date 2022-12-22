#include "lesson.h"
std::vector<Week>::iterator Lesson::BeginWeeks()
{
	return weeks_.begin();
}
std::vector<Week>::iterator Lesson::EndWeeks()
{
	return weeks_.end();
}
size_t Lesson::SizeWeek()
{
	return weeks_.size();
}
Week& Lesson::GetWeek(size_t index)
{
	return weeks_[index];
}
std::string Lesson::GetName()
{
	return name_;
}
std::string Lesson::GetLink()
{
	return link_;
}
void Lesson::SetName(std::string name)
{
	name_ = name;
}
void Lesson::SetLink(std::string link)
{
	link_ = link;
}
void Lesson::PushWeek(Week week)
{
	weeks_.push_back(week);
}
void Lesson::PopWeek(std::vector<Week>::iterator iter)
{
	weeks_.erase(iter);
}
