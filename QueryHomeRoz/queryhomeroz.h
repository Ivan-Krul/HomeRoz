#pragma once
#include <string>
#include <vector>

#include "homemgr.h"
#include "additionalstringlib.h"

class QueryHomeRoz
{
	const static std::vector<std::string> cs_list_of_token_ =
	{
		//UNDONE: fill this list of tokens
		// Definitions
		"LESSON",
		"HOMEWORK",
		// Size
		"SIZE OF", // () -> LESSON | HOMEWORK
		"IN", // SIZE OF HOMEWORK -> () -> lesson_name
		// Get
		"OUTPUT", // () -> LESSON | HOMEWORK
		// Set something
		"SET", // () -> LESSON | HOMEWORK
		"NAME",
		"LINK",
		"WEEK",

		"CONTEXT",
	};
	HomeRozMGR mgr_;
public:
	std::string Query(std::string query);
};

