#include "windowmanager.h"

#include <string>
#include <vector>
#include <array>

void WindowManager::Render(QueryHR& qhr)
{
	auto lesson_size = std::stoull(qhr.Query("SIZE OF LESSON"));
	auto pos_x = cur_pos_x_;
	auto lessonstr = std::vector<std::string>(lesson_size);
	auto max_space_lesson = std::array<uint8_t, 3>();
	auto max_space_homework = std::array<uint8_t, 4>();

	for (size_t l = 0; l < lesson_size; l++)
	{
		lessonstr[l] = qhr.Query("OUTPUT LESSON 0");
		auto beginind = size_t();
		auto flagtype = 0;

		for (size_t s = 0; s < lessonstr.size(); s++) // Search all tabs, it's because I separated output typed by tab symbol
		{
			if (lessonstr[l][s] == '\t')
			{
				max_space_lesson[flagtype] = __max(lessonstr[l].substr(beginind, s).size(), max_space_lesson[flagtype]);
				s++;
				flagtype++;
				beginind = s;
			}
		}
	}

	wnd_.update({ static_cast<short>(pos_x) , static_cast<short>(cur_pos_y_.top()) });
}
