#pragma once
#include "table.h"
#include "ext/Window.h"
#include "irendermodule.h"
class TableRend : public IRenderModule
{
private:
	Window mWindow;
	HomeworkSelect mHomeworkSelect;
	std::string mInput;
	Table::LineChoose mCurHor;
	std::list<Lesson>::iterator mCurVertLesson;
	std::list<Homework>::iterator mCurVertHomework;
	size_t mCurInputPos = 0;
	bool mIsBufInput;
	bool mIsAwaitInput;
	bool mIsHWSelectInput;
private:
	size_t mSpaceSize = 1;
private:
	COORD mCalculateCursorPos();
	COORD mCalculateCurPosNInpNSel();
	COORD mCalculateCurPosNInpYSel();
public:
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