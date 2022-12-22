#pragma once
#include "lesson.h"
#include "homework.h"
#include <list>
#include <map>
#include <string>
#include <algorithm>
class HomeworkSelect
{
	std::list<std::pair<Lesson, std::list<Homework>>> mHomeworkList;
private:
	std::list<std::pair<Lesson, std::list<Homework>>>::iterator mFindLesson(Lesson& lesson);
	std::list<Homework>::iterator mFindHomeworks(Homework& hw);
public:
	std::list<Homework> getHomeworkList(Lesson lesson);
	std::list<Lesson> getLessonList();
	void AddLesson(Lesson lesson);
	void EraseLesson(Lesson lesson);
	void AddHomework(Homework homework);
	void EraseHomework(Homework homework);
};

