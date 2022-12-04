#include "lesson.h"
std::vector<Week>::iterator Lesson::BeginWeeks()
{
	return mWeeks.begin();
}
std::vector<Week>::iterator Lesson::EndWeeks()
{
	return mWeeks.end();
}
size_t Lesson::SizeWeek()
{
	return mWeeks.size();
}
std::string Lesson::getName()
{
	return mName;
}
std::string Lesson::getLink()
{
	return mLink;
}
void Lesson::setName(std::string name)
{
	mName = name;
}
void Lesson::setLink(std::string link)
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
std::string Lesson::FormatToString()
{
	std::string string;
	string = mName;
	string += ' ';
	string += mLink.empty() ? "no link" : "link   ";
	string += " (";
	for (int w = 0; w < mWeeks.size(); w++)
	{
		string += WeekToString(mWeeks[w]);
		string += '/';
	}
	string += ")";
	return string;
}
