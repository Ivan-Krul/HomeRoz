#include "queryhomeroz.h"

namespace query_home_roz
{
	TokenIndex QueryHomeRoz::SearchToken_(std::string str) const
	{
		for (size_t i = 0; i < cs_list_of_token_.size(); i++)
			if (cs_list_of_token_[i] == str)
				return static_cast<TokenIndex>(i);
		return TokenIndex::nothing;
	}

	std::string QueryHomeRoz::ExecuteSizeOf_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query); // SIZE OF ()
		TokenIndex token_ind;

		switch (token_ind = SearchToken_(separated))
		{
			case TokenIndex::lesson:
				return std::to_string(mgr_.SizeLessons());
			case TokenIndex::homework:
				separated = additional_string_lib::SplitStr(query); // OF HOMEWORK ()
				if ((token_ind = SearchToken_(separated)) == TokenIndex::size_of_in)
				{
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK IN ...
					size_t index = std::stoi(separated);
					return std::to_string(mgr_.SizeHomeworks(index));
				}
				return cs_not_valid_token_msg;
			default:
				return cs_not_valid_token_msg;
		}
	}

	std::string QueryHomeRoz::OutputLesson_(Lesson lesson)
	{
		auto out = lesson.GetName();
		out += '\t';
		out += lesson.GetLink();
		out += '\t';
		for (size_t i = 0; i < lesson.SizeWeek(); i++)
		{
			out += date_week::WeekToString(lesson.GetWeek(i));
			out += ' ';
		}
		out.pop_back();
		return out;
	}

	std::string QueryHomeRoz::OutputHomework_(Homework hw)
	{
		auto out = hw.GetContex();
		out += '\t';
		out += std::to_string(hw.GetFromDate().GetDay());
		out += ' ';
		out += hw.GetFromDate().ConvertMonthToString();
		out += '\t';
		out += std::to_string(hw.GetToDate().GetDay());
		out += ' ';
		out += hw.GetToDate().ConvertMonthToString();
		out += '\t';
		out += hw.GetDone()
			? "done"
			: "dont";
		return out;
	}

	std::string QueryHomeRoz::ExecuteCreate_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query);
		TokenIndex token_ind;
		switch (token_ind = SearchToken_(separated))
		{
			case TokenIndex::lesson:
				mgr_.PushLesson();
				return cs_success_msg;
			case TokenIndex::homework:
				separated = additional_string_lib::SplitStr(query); // OF HOMEWORK ()
				if ((token_ind = SearchToken_(separated)) == TokenIndex::size_of_in)
				{
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK IN ...
					size_t index = std::stoi(separated);
					mgr_.PushHomework(index);
					return cs_success_msg;
				}
				return cs_not_valid_token_msg;
			default:
				return cs_not_valid_token_msg;
		}
		return cs_success_msg;
	}

	std::string QueryHomeRoz::ExecuteErase_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query);
		TokenIndex token_ind;
		switch (token_ind = SearchToken_(separated))
		{
			case TokenIndex::lesson:
				separated = additional_string_lib::SplitStr(query);
				mgr_.PopLesson(std::stoi(separated));
				return cs_success_msg;
			case TokenIndex::homework:
				{
					separated = additional_string_lib::SplitStr(query);
					size_t indexH = std::stoi(separated);
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK ()
					if ((token_ind = SearchToken_(separated)) == TokenIndex::size_of_in)
					{
						separated = additional_string_lib::SplitStr(query); // OF HOMEWORK IN ...
						mgr_.PopHomework(std::stoi(separated), indexH);
						return cs_success_msg;
					}
					return cs_not_valid_token_msg;
				}
			default:
				return cs_not_valid_token_msg;
		}
		return cs_success_msg;
	}

	std::string QueryHomeRoz::ExecuteOutput_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query);
		TokenIndex token_ind;
		switch (token_ind = SearchToken_(separated))
		{
			case TokenIndex::lesson:
				{
					separated = additional_string_lib::SplitStr(query);
					return OutputLesson_(*mgr_.GetLesson(std::stoi(separated)));
				}
			case TokenIndex::homework:
				{
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK ()
					size_t indexH = std::stoi(separated);
					separated = additional_string_lib::SplitStr(query);  // OF HOMEWORK ... ()
					if ((token_ind = SearchToken_(separated)) == TokenIndex::size_of_in)
					{
						separated = additional_string_lib::SplitStr(query); // OF HOMEWORK IN ...
						return OutputHomework_(*mgr_.GetHomework(std::stoi(separated), indexH));
					}
					return cs_not_valid_token_msg;
				}
			default:
				return cs_not_valid_token_msg;
		}
	}

	date_week::Week QueryHomeRoz::ConvertToWeek_(std::string str)
	{
		if (str == "mon")
			return date_week::Week::monday;
		else if (str == "tue")
			return date_week::Week::tuesday;
		else if (str == "wed")
			return date_week::Week::wednesday;
		else if (str == "thu")
			return date_week::Week::thursday;
		else if (str == "fri")
			return date_week::Week::friday;
		else if (str == "sat")
			return date_week::Week::saturday;
		else if (str == "sun")
			return date_week::Week::sunday;
		else
			return date_week::Week::monday;
	}

	std::string QueryHomeRoz::ExecuteSetLesson_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query);
		TokenIndex token_ind;
		size_t indexL = std::stoi(separated);
		separated = additional_string_lib::SplitStr(query);
		switch (token_ind = SearchToken_(separated))
		{
			case query_home_roz::TokenIndex::set_name:
				separated = additional_string_lib::SplitStr(query);
				mgr_.SetLessonName(indexL, separated);
				return cs_success_msg;
			case query_home_roz::TokenIndex::set_link:
				separated = additional_string_lib::SplitStr(query);
				mgr_.SetLessonLink(indexL, separated);
				return cs_success_msg;
			case query_home_roz::TokenIndex::set_week:
				separated = additional_string_lib::SplitStr(query);
				if (additional_string_lib::CanBeBigLetter(separated[0]))
				{
					// with NOT
					separated = additional_string_lib::SplitStr(query);
					if ((token_ind = SearchToken_(separated)) == TokenIndex::set_week_not)
					{
						separated = additional_string_lib::SplitStr(query);
						auto week = ConvertToWeek_(separated);
						auto iter = std::find(mgr_.GetLesson(indexL)->BeginWeeks(), mgr_.GetLesson(indexL)->EndWeeks(), week);
						mgr_.GetLesson(indexL)->PopWeek(iter);
						return cs_success_msg;
					}
					return cs_not_valid_token_msg;
				}
				mgr_.GetLesson(indexL)->PushWeek(ConvertToWeek_(separated));
				return cs_success_msg;
			default:
				return cs_not_valid_token_msg;
		}
	}

	std::string QueryHomeRoz::Query(std::string& query)
	{
		static std::string output;
		static auto separated = additional_string_lib::SplitStr(query);
		static TokenIndex token_ind;

		if (!size_t(token_ind = SearchToken_(separated)))
			return cs_invalid_token_msg;
		switch (token_ind)
		{
			case TokenIndex::nothing:
				return cs_success_msg;
			case TokenIndex::size_of:
				return ExecuteSizeOf_(query);
			case TokenIndex::output:
				ExecuteOutput_(query);
			case TokenIndex::set:
				separated = additional_string_lib::SplitStr(query);
				if ((token_ind = SearchToken_(separated)) == TokenIndex::lesson)
					return ExecuteSetLesson_(query);
				else if ((token_ind = SearchToken_(separated)) == TokenIndex::homework)
				{
					// UNDONE: Disassembly query in SET command in Homework condition
				}
				else
					return cs_not_valid_token_msg;
			case TokenIndex::clear:
				mgr_.Clear();
				return cs_success_msg;
			case TokenIndex::create:
				return ExecuteCreate_(query);
			case TokenIndex::erase:
				return ExecuteErase_(query);
			default:
				return cs_not_valid_token_msg;
		}
		return cs_nothing_msg;
	}
}
