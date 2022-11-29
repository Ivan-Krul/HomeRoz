#pragma once
#include "week.h"
#include "iformattostring.h"
#include <string>
#include <vector>
class Lesson : public IFormatToString
{
	std::string mName;
	std::string mLink;
	std::vector<Week> mWeeks;
public:
	auto BeginWeeks();
	auto EndWeeks();
	auto getName();
	auto getLink();
	void setName(std::string name);
	void getLink(std::string link);
	void PushWeek(Week week);
	void PopWeek(std::vector<Week>::iterator iter);
	std::string FormatToString();
};

