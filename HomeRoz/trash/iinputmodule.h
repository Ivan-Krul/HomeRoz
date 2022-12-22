#pragma once
#include "table.h"
__interface IInputModule
{
	void getIsHWSelect(bool hwselect);
	void SenseKeyboard();
	void StartTypeInput(std::string& input);
	void Type();
	size_t getCurInput();
	Table::UserActions GiveCommand();
	std::string& ReturnInput();
};