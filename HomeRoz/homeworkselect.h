#pragma once
#include "lesson.h"
#include "homework.h"
#include <list>
#include <map>
#include <string>
class HomeworkSelect
{
	std::map<Lesson, std::list<Homework>> mHomeworkList;
public:
	std::list<Homework> getHomeworkList(Lesson lesson);
	std::list<Lesson> getLessonList();
	void AddLesson(Lesson lesson);
	void EraseLesson(Lesson lesson);
	void AddHomework(Homework homework);
	void EraseHomework(Homework homework);
};

