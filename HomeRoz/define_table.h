#pragma once
#include <string>
#include "homeworkselect.h"
namespace Table
{
	using Size = unsigned short;
	using String = std::string;
	enum class LineChooser
	{
		home,
		lesson_name,
		link,
		weeks,
		homework_context,
		from_date,
		to_date,
		done
	};
}