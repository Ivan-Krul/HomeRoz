#pragma once
#include "table.h"
#include "ext/Window.h"
#include "irendermodule.h"
class TableRend : public IRenderModule
{
private:
	Window mWindow;
	HomeworkSelect mHomeworkSelect;
	COORD mCursorPosition;
public:
	void getHomeworkSelect(HomeworkSelect hwselect);
	void getInput(std::string input);
	void getLineChoose(Table::LineChoose lineChoose);
	void getIterLesson(std::list<Lesson>::iterator lesson);
	void getIterHomework(std::list<Homework>::iterator homework);
	void getInputCurPos(size_t curpos);
	void Render();
};

