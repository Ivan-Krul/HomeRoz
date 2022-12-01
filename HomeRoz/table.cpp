#include "table.h"
void Table::SenseControl(UserActions action)
{
	if(action != UserActions::nothing)
		mCurrentAction = action;
}
void Table::mConNothing()
{
	mCurrentAction = UserActions::nothing;
}
void Table::mConMoveUp()
{
	if (mIterLesson != mLessons.begin())
		mIterLesson--;
	mConNothing();
}
void Table::mConMoveDown()
{
	if(mIterLesson != mLessons.end())
		mIterLesson++;
	mConNothing();
}
void Table::mConMoveLeft()
{
	if(mLineChoose != LineChoose::lesson)
		mLineChoose = static_cast<LineChoose>(static_cast<int>(mLineChoose) - 1);
	mConNothing();
}
void Table::mConMoveRight()
{
	if (mLineChoose != LineChoose::done)
		mLineChoose = static_cast<LineChoose>(static_cast<int>(mLineChoose) + 1);
	mConNothing();
}
void Table::mConCreateLesson()
{
	static Lesson sTemplateLesson;
	sTemplateLesson.setName("New Lesson");
	sTemplateLesson.PushWeek(WeekSetCurrentTime());
	mLessons.push_back(sTemplateLesson);
}
void Table::mConCreateHomework()
{
	static Homework sTemplateHomework;
	if (sTemplateHomework.getContex() != "New Homework")
	{
		Date date_from;
		date_from.SetCurrentTime();
		sTemplateHomework.setContex("New Homework");
		sTemplateHomework.setFromDate(date_from);
		sTemplateHomework.setToDate(date_from);
		sTemplateHomework.setLesson(&(*mIterLesson));
	}
	mHomeworks.push_back(sTemplateHomework);
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
	case Table::UserActions::create_lesson:
		mConCreateLesson();
		break;
	case Table::UserActions::create_homework:
		mConCreateHomework();
		break;
	case Table::UserActions::erase_lesson:
		break;
	case Table::UserActions::erase_homework:
		break;
	case Table::UserActions::save:
		break;
	case Table::UserActions::load:
		break;
	default:
		mConNothing();
		break;
	}
}
