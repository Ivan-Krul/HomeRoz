#pragma once
#include "homeworkselect.h"
#include "ext/Window.h"
__interface IRenderModule
{
	void getHomeworkSelect(HomeworkSelect hwselect);
	void getInput(std::string input);
	void getLineChoose(Table::LineChoose lineChoose);
	void getIterLesson(std::list<Lesson>::iterator lesson);
	void getIterHomework(std::list<Homework>::iterator homework);
	void getInputCurPos(size_t curpos);
	void HearBufferingInput(bool word);
	void HearAwaitingInput(bool word);
	void HearHWSelectMode(bool word);
	Window& Render();
};
