#include "queryhomeroz.h"

TokenIndex QueryHomeRoz::SearchToken_(std::string str)
{
	for (size_t i = 0; i < cs_list_of_token_.size(); i++)
		if (cs_list_of_token_[i] == str)
			return static_cast<TokenIndex>(i);
	return TokenIndex::nothing;
}

std::string QueryHomeRoz::Query(std::string query)
{
	std::string output;
	auto separated = additional_string_lib::SplitStr(query);
	TokenIndex token_ind;
	if (!size_t(token_ind = SearchToken_(separated)))
	{
		output = "INVALID QUERY TOKEN";
		goto Answer;
	}
	switch (token_ind)
	{
		case TokenIndex::nothing:
			break;
		case TokenIndex::size_of:
			separated = additional_string_lib::SplitStr(query);
			switch (token_ind = SearchToken_(separated))
			{
				case TokenIndex::lesson:
					break;
				case TokenIndex::homework:
					break;
				case TokenIndex::size_of_in:
					break;
				default:
					break;
			}
			break;
		case TokenIndex::output:
			separated = additional_string_lib::SplitStr(query);
			break;
		case TokenIndex::set:
			separated = additional_string_lib::SplitStr(query);
			break;
		case TokenIndex::clear:
			mgr_.Clear();
			break;
		case TokenIndex::create:
			separated = additional_string_lib::SplitStr(query);
			break;
		case TokenIndex::erase:
			separated = additional_string_lib::SplitStr(query);
			break;
		default:
			goto NotValid;
			break;
	}
	if (token_ind == TokenIndex::nothing
		|| token_ind == TokenIndex::set
		|| token_ind == TokenIndex::clear
		|| token_ind == TokenIndex::create
		|| token_ind == TokenIndex::erase)
	{
		output = "SUCCESS";
		goto Answer;
	}
NotValid:
	output = "QUERY TOKEN EXIST BUT NOT VALID";
	goto Answer;
Answer:
	return output;
}
