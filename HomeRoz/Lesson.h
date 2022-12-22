#pragma once
#include "week.h"
#include <string>
#include <vector>
class Lesson
{
	std::string name_;
	std::string link_;
	std::vector<Week> weeks_;
public:
	std::vector<Week>::iterator BeginWeeks();
	std::vector<Week>::iterator EndWeeks();
	size_t SizeWeek();
	Week& GetWeek(size_t index);
	std::string GetName();
	std::string GetLink();
	void SetName(std::string name);
	void SetLink(std::string link);
	void PushWeek(Week week);
	void PopWeek(std::vector<Week>::iterator iter);
};

