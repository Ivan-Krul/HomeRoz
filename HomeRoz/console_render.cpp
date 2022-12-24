#include "console_render.h"

void ConsoleRender::GetHomeMGR(HomeMGR& homemgr)
{
	homemgr_ = &homemgr;
}

void ConsoleRender::Render(bool command_success, bool need_render, bool need_homework, size_t index_of_lesson)
{
	if (need_render)
	{
		if (need_homework)
		{
			Homework* hw;
			std::vector<size_t> max_char;
			size_t s = 0;
			for (size_t c = 0; c < 4; c++)
			{
				for (size_t i = 0; i < homemgr_->SizeHomeworks(index_of_lesson); i++)
				{
					hw = homemgr_->GetHomework(index_of_lesson, i);
					if (hw)
					{
						switch (c)
						{
							case 0:
								s = __max(s, hw->GetContex().size());
								break;
							case 1:
								s = __max(s, )
								break;
							case 2:
								break;
							case 3:
								break;
						}
					}
				}
				max_char.push_back(s);
			}

			for (size_t i = 0; i < homemgr_->SizeHomeworks(index_of_lesson); i++)
			{
				hw = homemgr_->GetHomework(index_of_lesson, i);
				if (hw) 
				{
					
				}
				else
					std::cout << "Corruption!";
				std::cout << std::endl;
			}
		}
	}
	if (command_success)
		std::cout << "Success\n";
	else
		std::cout << "Denied\n";
}
