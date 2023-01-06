#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "homemgr.h"

namespace query_home_roz
{
	enum class TokenIndex;

	class QueryHomeRoz
	{
		const std::vector<std::string> cs_list_of_token_ = {
			// Definitions
			"NOTHING",
			"LESSON",
			"HOMEWORK",
			// Size
			"SIZE", // () -> LESSON | HOMEWORK
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
			"ERASE",
			"OF",
			"SAVE",
			"LOAD"
		};
		const std::string cs_not_valid_token_msg = "query token exist but not valid";
		const std::string cs_invalid_token_msg = "invalid query token";
		const std::string cs_success_msg = "success";
		const std::string cs_nothing_msg = "nothing";
		const std::string cs_exception_msg = "exception";
	private:
		HomeMGR mgr_;
	private:
		TokenIndex SearchToken_(std::string str) const;
		std::string OutputLesson_(Lesson& lesson);
		std::string OutputHomework_(Homework hw);
		date_week::Week ConvertToWeek_(std::string str);
		size_t SeparateNumber(std::string& query);
		void WriteBinaryString(const std::string& str, std::ofstream& fs);
		std::string ReadBinaryString(const size_t size, std::ifstream& fs);
	private:
		std::string ExecuteSizeOf_(std::string& query);
		std::string ExecuteCreate_(std::string& query);
		std::string ExecuteErase_(std::string& query);
		std::string ExecuteOutput_(std::string& query);
		std::string ExecuteSetLesson_(std::string& query);
		std::string ExecuteSetHomework_(std::string& query);
		std::string ExecuteSave_(std::string& query);
		std::string ExecuteLoad_(std::string& query);
	public:
		const std::string Query(std::string query);
	};

	enum class TokenIndex
	{
		nothing = 0,
		lesson,
		homework,
		size,
		in,
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
		erase,
		of,
		save,
		load
	};
}

using QueryHR = query_home_roz::QueryHomeRoz;
