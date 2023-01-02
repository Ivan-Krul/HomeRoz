#pragma once
#include <string>
#include <vector>

#include "homemgr.h"
#include "additionalstringlib.h"

class QueryHomeRoz
{
	static const std::vector<std::string> cs_list_of_token_;

	HomeRozMGR mgr_;
private:
	TokenIndex SearchToken_(std::string str);
public:
	std::string Query(std::string query);
};

enum class TokenIndex
{
	nothing = 0,
	lesson,
	homework,
	size_of,
	size_of_in,
	output,
	set,
	set_name,
	set_link,
	set_week,
	set_week_not,
	set_context,
	set_date,
	set_date_creation,
	set_date_term,
	set_done,
	clear,
	create,
	erase
};

const std::vector<std::string> QueryHomeRoz::cs_list_of_token_ =
{
	//UNDONE: fill this list of tokens
	// Definitions
	"NOTHING",
	"LESSON",
	"HOMEWORK",
		// Size
	"SIZE OF", // () -> LESSON | HOMEWORK
	"IN", // SIZE OF HOMEWORK -> () -> lesson_name
		// Get
	"OUTPUT", // () -> LESSON | HOMEWORK
		// Set something
	"SET", // () -> LESSON | HOMEWORK
	"NAME", // SET LESSON lesson_name -> () -> ...
	"LINK",
	"WEEK", // SET LESSON lesson_name -> () -> NOT | week (3 letters)
	"NOT",
	"CONTEXT",
	"DATE",
	"CREATION",
	"TERM TO",
	"DONE",
	"CLEAR",
	"CREATE",
	"ERASE"
};
