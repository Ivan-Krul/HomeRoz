#pragma once
#include "homeworkselect.h"
#include "ext/Window.h"
__interface IRenderModule
{
	void setHomeworkSelect(HomeworkSelect hwselect);
	void setInput(std::string input);
	void setLineChoose(Table::LineChoose lineChoose);
	void setIterLesson(std::list<Lesson>::iterator lesson);
	void setIterHomework(std::list<Homework>::iterator homework);
	void setInputCurPos(size_t curpos);
	void setLatestHomework(std::list<Homework> listLatestHW);
	void HearBufferingInput(bool word);
	void HearAwaitingInput(bool word);
	void HearHWSelectMode(bool word);
	Window& Render();
	COORD getCursorCoord();
};
