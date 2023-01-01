#pragma once
#include <string>
#include <vector>
#include "week.h"

namespace query_home_roz
{
	class Lesson
	{
		std::string name_;
		std::string link_;
		std::vector<date_week::Week> weeks_;
	public:
		Lesson(std::string name = "", std::string link = "", std::vector<date_week::Week> weeks = {});
		std::vector<date_week::Week>::iterator BeginWeeks();
		std::vector<date_week::Week>::iterator EndWeeks();
		size_t SizeWeek();
		date_week::Week& GetWeek(size_t index);
		std::string GetName();
		std::string GetLink();
		void SetName(std::string name);
		void SetLink(std::string link);
		void PushWeek(date_week::Week week);
		void PopWeek(std::vector<date_week::Week>::iterator iter);
	};
}
