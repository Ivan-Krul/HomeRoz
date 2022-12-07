#pragma once
#include "homeworkselect.h"
__interface IRenderModule
{
	void getHomeworkSelect(HomeworkSelect hwselect);
	void getInput(std::string input);
	void getLineChoose(Table::LineChoose lineChoose);
	void getIterLesson(std::list<Lesson>::iterator lesson);
	void getIterHomework(std::list<Homework>::iterator homework);
	void Render();
};
