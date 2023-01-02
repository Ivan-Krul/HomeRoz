#pragma once
#include <string>

namespace additional_string_lib
{
	static inline bool CanBeNumber(char sym)
	{
		char expr = sym - '0';
		return 0 <= expr && expr < 10 ;
	}
	static inline bool CanBeBigLetter(const char sym)
	{
		char expr = sym - 'A';
		return 0 <= expr && expr < 26;
	}
	static inline bool CanBeSmallLetter(const char sym)
	{
		char expr = sym - 'a';
		return 0 <= expr && expr < 26;
	}
	static inline bool CanBeSpace(const char sym)
	{
		return sym == ' ' || sym == '\n' || sym == '\t' || sym == '\r';
	}
	static inline char MakeCharToNumber(const char sym)
	{
		return CanBeNumber(sym) ? sym - '0' : 0;
	}
	static inline bool CanBeLetter(const char sym)
	{
		return CanBeBigLetter(sym) || CanBeSmallLetter(sym);
	}
	static inline char MakeLetterToNumber(const char sym)
	{
		if (CanBeSmallLetter(sym))
			return sym - 'a';
		else if (CanBeBigLetter(sym))
			return sym - 'A';
		else return 0;
	}
	static inline std::string SeparateStr(std::string& str, size_t begin = 0)
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
	static inline std::string ShiftStr(std::string& str, size_t begin = 0)
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
	static inline std::string SplitStr(std::string& str, size_t begin = 0)
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
