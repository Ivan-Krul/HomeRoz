#include "tableinp.h"
void TableInp::mPutCharInInput()
{
	if (_kbhit())
	{
		if (mIsInsertMode)
		{
			if (mIsInsertMode && mInputCurPos + 1 < mpInput->size())
				mpInput[mInputCurPos] = _getch();
			else
				mpInput->append((char*)_getch());
		}
		else
			mpInput->insert(mInputCurPos, (char*)_getch());
	}
	mInputCurPos++;
}
void TableInp::getIsHWSelect(bool hwselect)
{
	mIsHWSelect = hwselect;
}
void TableInp::SenseKeyboard()
{
  if (mIsInput)
	Type();
	if (GetAsyncKeyState(VK_UP))
		mSavedAction = Table::UserActions::move_up;
	if (GetAsyncKeyState(VK_DOWN))
		mSavedAction = Table::UserActions::move_down;
	if (GetAsyncKeyState(VK_LEFT))
		mSavedAction = Table::UserActions::move_left;
	if (GetAsyncKeyState(VK_RIGHT))
		mSavedAction = Table::UserActions::move_right;
	if(GetAsyncKeyState(VK_RETURN))
		if(GetAsyncKeyState(VK_CONTROL))
			mSavedAction = Table::UserActions::input_buffer;
		else
			mSavedAction = Table::UserActions::input;
	if (GetAsyncKeyState(VK_CONTROL))
	{
		if (GetAsyncKeyState('S'))
			mSavedAction = Table::UserActions::save;
		if (GetAsyncKeyState('O'))
			mSavedAction = Table::UserActions::load;
		if (GetAsyncKeyState('N'))
			if (mIsHWSelect)
				mSavedAction = Table::UserActions::create_homework;
			else
				mSavedAction = Table::UserActions::create_lesson;
		if (GetAsyncKeyState('X'))
			if (mIsHWSelect)
				mSavedAction = Table::UserActions::erase_homework;
			else
				mSavedAction = Table::UserActions::erase_lesson;
		if (GetAsyncKeyState('H'))
			mSavedAction = Table::UserActions::select_homework;
	}
}
Table::UserActions TableInp::GiveCommand()
{
	return mSavedAction;
}
void TableInp::StartTypeInput(std::string& input)
{
	mIsInput = true;
	*mpInput = input;
	mInputCurPos = 0;
}
void TableInp::Type()
{
	if (mSavedAction != Table::UserActions::input_buffer || mSavedAction != Table::UserActions::input)
		return;
	if (GetAsyncKeyState(VK_RETURN))
		DoneInput();
	else if (GetAsyncKeyState(VK_BACK))
	{
		mpInput->erase(mInputCurPos);
		mInputCurPos--;
	}
	else if (GetAsyncKeyState(VK_LEFT) && mInputCurPos != 0)
		mInputCurPos--;
	else if (GetAsyncKeyState(VK_RIGHT) && mInputCurPos != mpInput->size() - 1)
		mInputCurPos++;
	else if (GetAsyncKeyState(VK_INSERT))
		mIsInsertMode = !mIsInsertMode;
	else if (GetAsyncKeyState(VK_DELETE))
	{
		if (mpInput->size() < mInputCurPos + 1)
			mpInput->erase(mInputCurPos + 1);
	}
	else if (GetAsyncKeyState(VK_HOME))
		mInputCurPos = 0;
	else if (GetAsyncKeyState(VK_END))
		mInputCurPos = mpInput->size() - 1;
	else
		mPutCharInInput();
}
void TableInp::DoneInput()
{
	mIsInput = false;
}
std::string& TableInp::ReturnInput()
{
	return *mpInput;
}
size_t TableInp::getCurInput() {
  return mInputCurPos;
}
