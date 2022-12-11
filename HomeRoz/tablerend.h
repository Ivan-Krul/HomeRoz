#pragma once
#include "table.h"
#include "ext/Window.h"
#include "irendermodule.h"
#include <list>
#include <string>
class TableRend : public IRenderModule
{
private:
	Window mWindow;
	HomeworkSelect mHomeworkSelect;
	std::string mInput;
	Table::LineChoose mCurHor;
	std::list<Lesson>::iterator mCurVertLesson;
	std::list<Homework>::iterator mCurVertHomework;
	std::list<Homework> mLatestHomework;
	size_t mCurInputPos = 0;
	bool mIsBufInput;
	bool mIsAwaitInput;
	bool mIsHWSelectInput;
	const std::string mInputSplitter = "/";
private:
	size_t mSpaceSize = 1;
private:
	COORD mCalculateCursorPos();
	COORD mCalculateCurPosNInpNSel();
	COORD mCalculateCurPosNInpYSel();
	COORD mCalculateCurPosYInpYSel();
	COORD mCalculateCurPosYInpNSel();
	std::string mCompareInput();
	std::list<std::string> mCompareToRows();
public:
	void setHomeworkSelect(HomeworkSelect hwselect);
	void setInput(std::string input);
	void setLineChoose(Table::LineChoose lineChoose);
	void setIterLesson(std::list<Lesson>::iterator lesson);
	void setIterHomework(std::list<Homework>::iterator homework);
	void setLatestHomework(std::list<Homework> listLatestHW);
	void setInputCurPos(size_t curpos);
	void HearBufferingInput(bool word);
	void HearAwaitingInput(bool word);
	void HearHWSelectMode(bool word);
	Window& Render();
	COORD getCursorCoord();
};