#pragma once
#include "define_table.h"
#include "homeworkselect.h"
namespace Table
{
	class SubCurMgrTable
	{
		Size _max_x = 0;
		Size _max_lesson_y = 0;
		Size _max_homework_y = 0;
		Size _pos_x = 0;
		Size _pos_lesson_y = 0;
		Size _pos_homework_y = 0;
		Size _input_pos = 0;
	public:
		LineChooser ConvertXToLnChs();
		Size getPosX();
		Size getPosY();
		void IncX();
		void DecX();
		void IncY();
		void DecY();
		void CalculateMaxSizes(HomeworkSelect hw_select_);
		bool CheckNeedUpdateMax(HomeworkSelect hw_select_);
	};
}