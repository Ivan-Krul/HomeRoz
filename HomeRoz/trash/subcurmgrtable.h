#pragma once
#include "homeworkselect.h"
namespace table
{
	enum class LineChooser
	{
		home = 0,
		lesson_name,
		link,
		weeks,
		homework_context,
		from_date,
		to_date,
		done
	};
	class SubCurMgrTable
	{
		typedef unsigned short ushort;
		ushort max_x_ = 0;
		ushort pos_x_ = 0;
		ushort max_lesson_y_ = 0;
		ushort max_homework_y_ = 0;
		ushort pos_homework_y_ = 0;
		ushort pos_lesson_y_ = 0;
		bool is_hwselect_mode_ = false;
	public:
		LineChooser ConvertXToLnChs();
		unsigned short getPosX();
		unsigned short getPosY();
		void IncX();
		void DecX();
		void IncY();
		void DecY();
		void SwitchHWSelect();
		void WriteMaxSizes(HomeworkSelect hw_select);
	};
}