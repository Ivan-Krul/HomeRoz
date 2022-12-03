#include "homeworkselect.h"
std::list<Homework> HomeworkSelect::getHomeworkList(Lesson lesson)
{
	auto hwlist = mHomeworkList.find(lesson);
	return hwlist->second;
}
std::list<Lesson> HomeworkSelect::getLessonList()
{
	std::list<Lesson> lessons;
	for (auto lesson = mHomeworkList.begin(); lesson != mHomeworkList.end(); lesson++)
		lessons.push_back(lesson->first);
	return lessons;
}
void HomeworkSelect::AddLesson(Lesson lesson)
{
	mHomeworkList.insert({lesson, std::list<Homework>()});
}
void HomeworkSelect::EraseLesson(Lesson lesson)
{
	auto hwlist = mHomeworkList.find(lesson);
	mHomeworkList.erase(hwlist);
}
void HomeworkSelect::AddHomework(Homework homework)
{
	auto list = mHomeworkList.find(*homework.getLesson());
	list->second.push_back(homework);
}
void HomeworkSelect::EraseHomework(Homework homework)
{
	auto hwlist = mHomeworkList.find(*homework.getLesson());
	for (auto hw = hwlist->second.begin(); hw != hwlist->second.end(); hw++)
	{
		if (hw->getContex() == homework.getContex())
		{
			hwlist->second.erase(hw);
			return;
		}
	}
}
