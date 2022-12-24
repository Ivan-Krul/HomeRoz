#pragma once
#include "homemgr.h"
__interface IRender
{
	void GetHomeMGR(HomeMGR& homemgr);
	void Render(bool command_success, bool need_render = false, bool need_homework = false, size_t index_of_lesson = 0);
};