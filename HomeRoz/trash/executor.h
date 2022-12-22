#pragma once
#include "iinputmodule.h"
#include "irendermodule.h"
#include "table.h"
class Executor
{
	IInputModule* mInputModule;
	IRenderModule* mRenderModule;
	Table mTable;
	bool mIsPrevInput = false;
	bool mIsInput = false;
public:
	Executor(IInputModule* inputModule, IRenderModule* renderModule);
	void Input();
	void Update();
};

