#pragma once
#include "lesson.h"
#include "homework.h"
#include <list>
#include <map>
#include <string>
class HomeworkSelect
{
	std::map<std::string, std::list<Homework>> mHomeworkList;
public:
	auto getHomework(std::string nameLesson);
	void AddLesson(Lesson lesson);
	void EraseLesson(Lesson lesson);
	void AddHomework(Homework homework);
	void EraseHomework(Homework homework);
};

