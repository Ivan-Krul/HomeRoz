#pragma once
#include "iinputmodule.h"
#include <Windows.h> // to get sensors
#include <conio.h>
class TableInp : public IInputModule
{
	std::string* mpInput;
	Table::UserActions mSavedAction;
	bool mIsHWSelect = false;
	bool mIsInput = false;
	size_t mInputCurPos;
	bool mIsInsertMode = false;
private:
	void mPutCharInInput();
public:
	void getIsHWSelect(bool hwselect);
	void SenseKeyboard();
	Table::UserActions GiveCommand();
	void StartTypeInput(std::string& input);
	void Type();
	void DoneInput();
	std::string& ReturnInput();
	size_t getCurInput();
};

