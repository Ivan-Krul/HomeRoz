#include "queryhomeroz.h"

#include "additionalstringlib.h"

namespace query_home_roz
{
	TokenIndex QueryHomeRoz::SearchToken_(std::string str) const
	{
		if(str.empty())
			return TokenIndex::nothing;
		for (size_t i = 0; i < cs_list_of_token_.size(); i++)
			if (cs_list_of_token_[i] == str)
				return static_cast<TokenIndex>(i);
		return TokenIndex::nothing;
	}

	std::string QueryHomeRoz::ExecuteSizeOf_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query); // SIZE OF ()
		TokenIndex token_ind;
		if((token_ind = SearchToken_(separated)) != TokenIndex::of)
			return cs_invalid_token_msg;
		separated = additional_string_lib::SplitStr(query);
		switch (token_ind = SearchToken_(separated))
		{
			case TokenIndex::lesson:
				return std::to_string(mgr_.SizeLessons());
			case TokenIndex::homework:
				separated = additional_string_lib::SplitStr(query); // OF HOMEWORK ()
				if ((token_ind = SearchToken_(separated)) == TokenIndex::in)
				{
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK IN ...
					size_t index = std::stoi(separated);
					return std::to_string(mgr_.SizeHomeworks(index));
				}
				return cs_not_valid_token_msg + ": SIZE OF HOMEWORK (IN) [lesson index]";
			default:
				return cs_not_valid_token_msg + ": SIZE OF (LESSON | HOMEWORK)";
		}
	}

	std::string QueryHomeRoz::OutputLesson_(Lesson& lesson)
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
				if ((token_ind = SearchToken_(separated)) == TokenIndex::in)
				{
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK IN ...
					size_t index = std::stoi(separated);
					mgr_.PushHomework(index);
					return cs_success_msg;
				}
				return cs_not_valid_token_msg + ": CREATE HOMEWORK (IN) [lesson index]";
			default:
				return cs_not_valid_token_msg + ": CREATE (LESSON | HOMEWORK)";
		}
		return cs_success_msg;
	}

	size_t QueryHomeRoz::SeparateNumber(std::string& query)
	{
		return std::stoull(additional_string_lib::SplitStr(query));
	}

	std::string QueryHomeRoz::ExecuteErase_(std::string& query)
	{
		auto separated = additional_string_lib::SplitStr(query);
		TokenIndex token_ind;
		switch (token_ind = SearchToken_(separated))
		{
			case TokenIndex::lesson:
				mgr_.PopLesson(SeparateNumber(query));
				return cs_success_msg;
			case TokenIndex::homework:
				{
					size_t indexH = SeparateNumber(query);
					separated = additional_string_lib::SplitStr(query); // OF HOMEWORK ()
					if ((token_ind = SearchToken_(separated)) == TokenIndex::in)
					{
						mgr_.PopHomework(SeparateNumber(query), indexH); // OF HOMEWORK IN ...
						return cs_success_msg;
					}
					return cs_not_valid_token_msg + ": ERASE HOMEWORK [homework index] (IN) [lesson index]";
				}
			default:
				return cs_not_valid_token_msg + ": ERASE (LESSON | HOMEWORK)";
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
				return OutputLesson_(*mgr_.GetLesson(SeparateNumber(query)));
			case TokenIndex::homework:
				{
					size_t indexH = SeparateNumber(query); // OF HOMEWORK ()
					separated = additional_string_lib::SplitStr(query);  // OF HOMEWORK ... ()
					if ((token_ind = SearchToken_(separated)) == TokenIndex::in)
						return OutputHomework_(*mgr_.GetHomework(SeparateNumber(query), indexH)); // OF HOMEWORK IN ...
					return cs_not_valid_token_msg + ": OUTPUT HOMEWORK [homework index] (IN) [lesson index]";
				}
			default:
				return cs_not_valid_token_msg + ": OUTPUT (LESSON | HOMEWORK)";
		}
	}

	date_week::Week QueryHomeRoz::ConvertToWeek_(std::string str)
	{
		if (str == "Mon")
			return date_week::Week::monday;
		else if (str == "Tue")
			return date_week::Week::tuesday;
		else if (str == "Wed")
			return date_week::Week::wednesday;
		else if (str == "Thu")
			return date_week::Week::thursday;
		else if (str == "Fri")
			return date_week::Week::friday;
		else if (str == "Sat")
			return date_week::Week::saturday;
		else if (str == "Sun")
			return date_week::Week::sunday;
		else
			return date_week::Week();
	}

	std::string QueryHomeRoz::ExecuteSetLesson_(std::string& query)
	{
		TokenIndex token_ind;
		size_t indexL = SeparateNumber(query);
		switch (token_ind = SearchToken_(additional_string_lib::SplitStr(query)))
		{
			case query_home_roz::TokenIndex::set_name:
				mgr_.SetLessonName(indexL, additional_string_lib::SplitStr(query));
				return cs_success_msg;
			case query_home_roz::TokenIndex::set_link:
				mgr_.SetLessonLink(indexL, additional_string_lib::SplitStr(query));
				return cs_success_msg;
			case query_home_roz::TokenIndex::set_week:
				{
					auto separated = additional_string_lib::SplitStr(query);
					if ((token_ind = SearchToken_(separated)) == TokenIndex::set_week_not)
					{
						// with NOT
						auto week = ConvertToWeek_(additional_string_lib::SplitStr(query));
						auto iter = std::find(mgr_.GetLesson(indexL)->BeginWeeks(), mgr_.GetLesson(indexL)->EndWeeks(), week);
						mgr_.GetLesson(indexL)->PopWeek(iter);
						return cs_success_msg;
					}
					mgr_.GetLesson(indexL)->PushWeek(ConvertToWeek_(separated));
					return cs_success_msg;
				}
			default:
				return cs_not_valid_token_msg + ": SET LESSON [lesson index] (NAME | LINK | WEEK)";
		}
	}

	std::string QueryHomeRoz::ExecuteSetHomework_(std::string& query)
	{
		size_t indexH = SeparateNumber(query); // SET HOMEWORK ()
		auto separated = additional_string_lib::SplitStr(query); // SET HOMEWORK [] ()
		TokenIndex token_ind = SearchToken_(separated); // No changes there
		separated = additional_string_lib::SplitStr(query);
		if (SearchToken_(separated) != TokenIndex::in) // SET HOMEWORK [] {} ()
			return cs_not_valid_token_msg;
		size_t indexL = SeparateNumber(query); // SET HOMEWORK [] {} IN ()
		separated = additional_string_lib::SplitStr(query);
		switch (token_ind) // SET HOMEWORK [] {} IN [] ...
		{
			case TokenIndex::set_context:
				mgr_.SetHomeworkContext(indexL, indexH, separated);
				return cs_success_msg;
			case TokenIndex::set_date:
				{
					token_ind = SearchToken_(separated);
					date_week::Date d;
					separated = additional_string_lib::SplitStr(query);
					d.SetMonth(std::stoi(additional_string_lib::SplitStr(query)));
					d.SetDay(std::stoi(separated));
					switch (token_ind)
					{
						case TokenIndex::set_date_creation:
							mgr_.SetHomeworkDateFrom(indexL, indexH, d);
							return cs_success_msg;
						case TokenIndex::set_date_term:
							mgr_.SetHomeworkDateTo(indexL, indexH, d);
							return cs_success_msg;
						default:
							return cs_not_valid_token_msg + ": SET HOMEWORK [homework index] DATE IN [lesson index] (CREATION | TERM) [day] [month(in number)]";
					}
				}
			case TokenIndex::set_done:
				mgr_.SetHomeworkDone(indexL, indexH, separated == "true");
				return cs_success_msg;
			default:
				return cs_not_valid_token_msg + ": SET HOMEWORK [homework index] (CONTEXT | DATE | DONE) IN [lesson index] [value]";
		}
	}

	const std::string QueryHomeRoz::Query(std::string query)
	{
		TokenIndex token_ind;
		try
		{
			if (!size_t(token_ind = SearchToken_(additional_string_lib::SplitStr(query))))
				return cs_invalid_token_msg;
			switch (token_ind)
			{
				case TokenIndex::size:
					return ExecuteSizeOf_(query);
				case TokenIndex::output:
					return ExecuteOutput_(query);
				case TokenIndex::set:
					if ((token_ind = SearchToken_(additional_string_lib::SplitStr(query))) == TokenIndex::lesson)
						return ExecuteSetLesson_(query);
					else if (token_ind == TokenIndex::homework)
						return ExecuteSetHomework_(query);
					else
						return cs_not_valid_token_msg + ": SET (LESSON | HOMEWORK)";
				case TokenIndex::clear:
					mgr_.Clear();
					return cs_success_msg;
				case TokenIndex::create:
					return ExecuteCreate_(query);
				case TokenIndex::erase:
					return ExecuteErase_(query);
				case TokenIndex::save:
					return ExecuteSave_(query);
				case TokenIndex::load:
					return ExecuteLoad_(query);
				default:
					return cs_not_valid_token_msg + ":  (SIZE | OUTPUT | SET | CLEAR | CREATE | ERASE | SAVE | LOAD)";
			}
			return cs_nothing_msg;
		}
		catch (const std::exception& exc) 
		{
			return cs_exception_msg + ": " + exc.what();
		}		
	}
}
