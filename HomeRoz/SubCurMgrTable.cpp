#include "subcurmgrtable.h"
namespace Table
{
	LineChooser SubCurMgrTable::ConvertXToLnChs()
	{
		return LineChooser();
	}
	Size SubCurMgrTable::getPosX()
	{
		return _pos_x;
	}
	Size SubCurMgrTable::getPosY()
	{
		return _pos_lesson_y;
	}
	void SubCurMgrTable::IncX()
	{
		if (_pos_x + 1 < _max_x)
			_pos_x++;
	}
	void SubCurMgrTable::DecX()
	{
		if (_pos_x != 0)
			_pos_x--;
	}
	void SubCurMgrTable::IncY()
	{
		if (_pos_lesson_y + 1 < _max_lesson_y)
			_pos_lesson_y++;
	}
	void SubCurMgrTable::DecY()
	{
		if (_pos_lesson_y != 0)
			_pos_lesson_y--;
	}
	void SubCurMgrTable::CalculateMaxSizes(HomeworkSelect hw_select_)
	{
		// TODO: Need made a realisation for calculation max size
	}
	bool SubCurMgrTable::CheckNeedUpdateMax(HomeworkSelect hw_select_)
	{
		auto lesson_list = hw_select_.getLessonList();
		auto lesson = lesson_list.begin();
		Size y = 0;
		for ((lesson,y); lesson != lesson_list.end() && y != _pos_lesson_y; (lesson++,y++));
		return hw_select_.getHomeworkList(*lesson).size() != 0;
	}
}

