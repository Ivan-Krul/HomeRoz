#pragma once
#include <stack>

#include "Window.h"
#include "queryhomeroz.h"

class WindowManager
{
	con_window_manager::Window wnd_;
	std::stack<size_t> cur_pos_y_; // Hirearchy of cursor position
	size_t cur_pos_x_;
public:
	void Render(QueryHR& qhr);
};

