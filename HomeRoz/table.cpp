#include "table.h"
std::string Table::mWriteStrBinaryFin(std::ifstream& fin)
{
	std::string str;
	size_t size;
	fin.read((char*)size, sizeof(size));
	str.resize(size);
	fin.read((char*)str.c_str(), size);
	return str;
}
Date Table::mWriteDateBinaryFin(std::ifstream& fin)
{
	Date date;
	unsigned short day;
	Date::Month month;
	fin.read((char*)day, sizeof(day));
	fin.read((char*)month, sizeof(month));
	date.setDay(day);
	date.setMonth(month);
	return date;
}
void Table::SenseControl(UserActions action)
{
	mCurrentAction = action;
}
void Table::Execute()
{
	switch (mCurrentAction)
	{
	case Table::UserActions::move_up:
		mConMoveUp();
		break;
	case Table::UserActions::move_down:
		mConMoveDown();
		break;
	case Table::UserActions::move_right:
		mConMoveRight();
		break;
	case Table::UserActions::move_left:
		mConMoveLeft();
		break;
	case Table::UserActions::input:
		break;
	case Table::UserActions::input_buffer:
		break;
	case Table::UserActions::create_lesson:
		mConCreateLesson();
		break;
	case Table::UserActions::create_homework:
		mConCreateHomework();
		break;
	case Table::UserActions::erase_lesson:
		mConEraseLesson();
		break;
	case Table::UserActions::erase_homework:
		mConEraseHomework();
		break;
	case Table::UserActions::select_homework:
		mConSelectHomework();
		break;
	case Table::UserActions::save:
		mConSave();
		break;
	case Table::UserActions::load:
		mConLoad();
		break;
	default:
		mConNothing();
		break;
	}
}

