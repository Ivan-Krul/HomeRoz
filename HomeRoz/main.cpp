#include <iostream>

#include "date.h"
#include "lesson.h"
#include "homework.h"
#include "homeworkselect.h"
#include "table.h"

int main() 
{
	auto separate = []() { std::cout << std::endl; };
	Date date;
	date.SetCurrentTime();
	std::cout << date.FormatToString() << std::endl;
	separate();
	Week week = WeekSetCurrentTime();
	std::cout << WeekToString(week) << std::endl;
	separate();
	Lesson lesson;
	lesson.setName("Pravo");
	lesson.PushWeek(week);
	std::cout << lesson.FormatToString() << std::endl;
	separate();
	Homework hw;
	hw.setContex("watch 5 video");
	hw.setLesson(&lesson);
	hw.setFromDate(date);
	hw.setToDate(date);
	//hw.MarkDone();
	std::cout << hw.FormatToString() << std::endl;
	Homework HW;
	separate();
	// HomeworkSelect - checked
	Table table;
	table.SenseControl(Table::UserActions::create_lesson);
	table.Execute();
	table.SenseControl(Table::UserActions::input);
	table.Execute();
	auto& inp = table.GiveInput();
	inp = "Abracadabra";
	table.CheckInput();
	auto hwselect = table.getHomeworkSelect();
	auto llist = hwselect.getLessonList();
	for (auto& iter : llist)
		std::cout << iter.FormatToString() << std::endl;
}
