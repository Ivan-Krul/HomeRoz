#pragma once
#include <string>

namespace additional_string_lib
{
	inline bool CanBeNumber(char sym);
	inline bool CanBeBigLetter(const char sym);
	inline bool CanBeSmallLetter(const char sym);
	inline bool CanBeSpace(const char sym);
	inline char MakeCharToNumber(const char sym);
	inline bool CanBeLetter(const char sym);
	inline char MakeLetterToNumber(const char sym);
	inline std::string SeparateStr(std::string& str, size_t begin = 0);
	inline std::string ShiftStr(std::string& str, size_t begin = 0);
	inline std::string SplitStr(std::string& str, size_t begin = 0);
}
//#include "additionalstringlib.cpp"