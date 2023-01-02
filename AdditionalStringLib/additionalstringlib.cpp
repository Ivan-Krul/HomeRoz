#include "additionalstringlib.h"

namespace additional_string_lib
{
	inline bool CanBeNumber(char sym)
	{
		char expr = sym - '0';
		return 0 <= expr && expr < 10;
	}
	inline bool CanBeBigLetter(const char sym)
	{
		char expr = sym - 'A';
		return 0 <= expr && expr < 26;
	}
	inline bool CanBeSmallLetter(const char sym)
	{
		char expr = sym - 'a';
		return 0 <= expr && expr < 26;
	}
	inline bool CanBeSpace(const char sym)
	{
		return sym == ' ' || sym == '\n' || sym == '\t' || sym == '\r';
	}
	inline char MakeCharToNumber(const char sym)
	{
		return CanBeNumber(sym) ? sym - '0' : 0;
	}
	inline bool CanBeLetter(const char sym)
	{
		return CanBeBigLetter(sym) || CanBeSmallLetter(sym);
	}
	inline char MakeLetterToNumber(const char sym)
	{
		if (CanBeSmallLetter(sym))
			return sym - 'a';
		else if (CanBeBigLetter(sym))
			return sym - 'A';
		else return 0;
	}
	inline std::string SeparateStr(std::string& str, size_t begin)
	{
		size_t end = begin;
		while (end < str.size())
		{
			if (CanBeSpace(str[end]))
				break;
			end++;
		}
		return str.erase(begin, end);
	}
	inline std::string ShiftStr(std::string& str, size_t begin)
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
	inline std::string SplitStr(std::string& str, size_t begin)
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
