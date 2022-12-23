#pragma once
#include <iostream>
#include "irender.h"
class ConsoleRender : public IRender
{
public:
	void GetHomeMGR(HomeMGR& homemgr);
	void Render();
};

