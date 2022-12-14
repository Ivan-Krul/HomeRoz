#include <iostream>

#include "date.h"
#include "lesson.h"
#include "homework.h"
#include "homeworkselect.h"

int main() {
	Date date;
	date.SetCurrentTime();
	std::cout << date.FormatToString() << std::endl;

	Week week = WeekSetCurrentTime();
	std::cout << WeekToString(week) << std::endl;

	Lesson lesson;
	lesson.setName("Pravo");
	lesson.PushWeek(week);
	std::cout << lesson.FormatToString() << std::endl;

	Homework hw;
	hw.setContex("watch 5 video");
	hw.setLesson(&lesson);
	hw.setFromDate(date);
	hw.setToDate(date);
	//hw.MarkDone();
	std::cout << hw.FormatToString() << std::endl;
	Homework HW;

	HomeworkSelect hwselect;
	{
		
		HW.setContex("context");
		HW.setLesson(&lesson);
		HW.setFromDate(date);
		Date dat(Date::Month::january,10);
		HW.setToDate(dat);
		hwselect.AddLesson(lesson);
		hwselect.AddHomework(hw);
		hwselect.AddHomework(HW);
	}

	{
		auto list = hwselect.getLessonList();
		std::cout << "Lessons\n";
		for (auto& iter : list)
			std::cout << iter.FormatToString() << std::endl;
		std::cout << "Homeworks of Lesson\n";
		auto hwlist = hwselect.getHomeworkList(lesson);
		for (auto& iter : hwlist)
			std::cout << iter.FormatToString() << std::endl;
	}
	hwselect.EraseHomework(HW);
	hwselect.EraseHomework(hw);
	hwselect.EraseLesson(lesson);
	std::cout << "Size of deleted = " << hwselect.getLessonList().size() << std::endl;
}
