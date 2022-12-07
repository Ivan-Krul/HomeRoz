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
	void Render();
};

