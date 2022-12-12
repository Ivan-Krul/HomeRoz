#pragma once
#include "iinputmodule.h"
#include "irendermodule.h"
#include "table.h"
class Executor
{
	IInputModule* mInputModule;
	IRenderModule* mRenderModule;
	Table mTable;
public:
	Executor(IInputModule* inputModule, IRenderModule* renderModule);
	void Update();

};

