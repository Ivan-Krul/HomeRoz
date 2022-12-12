#pragma once
#include "table.h"
__interface IInputModule
{
	void getIsHWSelect(bool hwselect);
	void SenseKeyboard();
	void StartTypeInput(std::string input);
	void Type();
	Table::UserActions GiveCommand();
	std::string ReturnInput();
};