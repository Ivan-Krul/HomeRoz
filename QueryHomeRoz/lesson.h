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
		size_t SizeWeek() const;
		date_week::Week& GetWeek(size_t index);
		const std::string& GetName() const;
		const std::string& GetLink() const;
		void SetName(const std::string name);
		void SetLink(const std::string link);
		void PushWeek(const date_week::Week week);
		void PopWeek(const std::vector<date_week::Week>::iterator iter);
	};
}
