#include "subcurmgrtable.h"
namespace table
{
	LineChooser SubCurMgrTable::ConvertXToLnChs()
	{
		return LineChooser();
	}
	unsigned short SubCurMgrTable::getPosX()
	{
		return pos_x_;
	}
	unsigned short SubCurMgrTable::getPosY()
	{
		return is_hwselect_mode_ ? pos_homework_y_ : pos_lesson_y_;
	}
	void SubCurMgrTable::IncX()
	{
		if (pos_x_ + 1 <= max_x_)
			pos_x_++;
	}
	void SubCurMgrTable::DecX()
	{
		if (pos_x_ != 0)
			pos_x_--;
	}
	void SubCurMgrTable::IncY()
	{
		if (is_hwselect_mode_)
			if (pos_homework_y_ + 1 <= max_homework_y_)
				pos_homework_y_++;
		else
			if (pos_lesson_y_ + 1 <= max_lesson_y_)
				pos_lesson_y_++;
	}
	void SubCurMgrTable::DecY()
	{
		if (is_hwselect_mode_)
			if (pos_homework_y_ - 1 != 0)
				pos_homework_y_--;
		else
			if (pos_lesson_y_ - 1 != 0)
				pos_lesson_y_--;
	}
	void SubCurMgrTable::SwitchHWSelect()
	{
		is_hwselect_mode_ = !is_hwselect_mode_;
	}
	void SubCurMgrTable::WriteMaxSizes(HomeworkSelect hw_select)
	{
		auto lessons = hw_select.getLessonList();
		if (!(max_lesson_y_ = lessons.size()))
			return;
		auto lesson = lessons.begin();
		ushort y = 0;
		for ((lesson, y); lesson != lessons.end() && y != pos_homework_y_; (y++, lesson++));
		auto homeworks = hw_select.getHomeworkList(*lesson);
		max_homework_y_ = homeworks.size();
	}
}

