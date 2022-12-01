#include "homeworkselect.h"
auto HomeworkSelect::getHomework(std::string nameLesson)
{
	auto hwlist = mHomeworkList.find(nameLesson);
	return hwlist->second;
}
void HomeworkSelect::AddLesson(Lesson lesson)
{
	mHomeworkList.insert({lesson.getName(), std::list<Homework>()});
}
void HomeworkSelect::EraseLesson(Lesson lesson)
{
	auto hwlist = mHomeworkList.find(lesson.getName());
	mHomeworkList.erase(hwlist);
}
void HomeworkSelect::AddHomework(Homework homework)
{
	auto list = mHomeworkList.find(homework.getLesson()->getName());
	list->second.push_back(homework);
}
void HomeworkSelect::EraseHomework(Homework homework)
{
		auto hwlist = mHomeworkList.find(homework.getLesson()->getName());
		for (auto hw = hwlist->second.begin(); hw != hwlist->second.end(); hw++)
		{
			if (*hw == homework)
			{

			}
		}
		mHomeworkList.find(homework.getLesson()->getName())(homework);
}
