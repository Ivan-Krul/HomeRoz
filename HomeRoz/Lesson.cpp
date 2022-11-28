#include "lesson.h"
auto Lesson::BeginWeeks()
{
	return mWeeks.begin();
}
auto Lesson::EndWeeks()
{
	return mWeeks.end();
}
auto Lesson::getName()
{
	return mName;
}
auto Lesson::getLink()
{
	return mLink;
}
void Lesson::setName(std::string name)
{
	mName = name;
}
void Lesson::getLink(std::string link)
{
	mLink = link;
}
void Lesson::PushWeek(Week week)
{
	mWeeks.push_back(week);
}
void Lesson::PopWeek(std::vector<Week>::iterator iter)
{
	mWeeks.erase(iter);
}
