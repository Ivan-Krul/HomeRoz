#pragma once
#include <string>

namespace additional_string_lib
{
	bool CanBeNumber(char sym);
	bool CanBeBigLetter(const char sym);
	bool CanBeSmallLetter(const char sym);
	bool CanBeSpace(const char sym);
	char MakeCharToNumber(const char sym);
	bool CanBeLetter(const char sym);
	char MakeLetterToNumber(const char sym);
	std::string SeparateStr(std::string& str, size_t begin = 0);
	std::string ShiftStr(std::string& str, size_t begin = 0);
	std::string SplitStr(std::string& str, size_t begin = 0);
}
//#include "additionalstringlib.cpp"