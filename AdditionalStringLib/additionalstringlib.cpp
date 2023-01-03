#include "additionalstringlib.h"

namespace additional_string_lib
{
	bool CanBeNumber(char sym)
	{
		char expr = sym - '0';
		return 0 <= expr && expr < 10;
	}
	bool CanBeBigLetter(const char sym)
	{
		char expr = sym - 'A';
		return 0 <= expr && expr < 26;
	}
	bool CanBeSmallLetter(const char sym)
	{
		char expr = sym - 'a';
		return 0 <= expr && expr < 26;
	}
	bool CanBeSpace(const char sym)
	{
		return sym == ' ' || sym == '\n' || sym == '\t' || sym == '\r';
	}
	char MakeCharToNumber(const char sym)
	{
		return CanBeNumber(sym) ? sym - '0' : 0;
	}
	bool CanBeLetter(const char sym)
	{
		return CanBeBigLetter(sym) || CanBeSmallLetter(sym);
	}
	char MakeLetterToNumber(const char sym)
	{
		if (CanBeSmallLetter(sym))
			return sym - 'a';
		else if (CanBeBigLetter(sym))
			return sym - 'A';
		else return 0;
	}
	std::string SeparateStr(std::string& str, size_t begin)
	{
		size_t end = begin;
		while (end < str.size())
		{
			if (CanBeSpace(str[end]))
				break;
			end++;
		}
		std::string sub = str.substr(begin, end);
		str.erase(begin, end);
		return sub;
	}
	std::string ShiftStr(std::string& str, size_t begin)
	{
		size_t end = begin;
		while (end < str.size())
		{
			if (!CanBeSpace(str[end]))
				break;
			end++;
		}
		return str.erase(begin, end - begin);
	}
	std::string SplitStr(std::string& str, size_t begin)
	{
		auto separated = SeparateStr(str, begin);
		size_t end = begin;
		while (end < str.size())
		{
			if (!CanBeSpace(str[end]))
				break;
			end++;
		}
		str.erase(begin, end - begin);
		return separated;
	}
}
