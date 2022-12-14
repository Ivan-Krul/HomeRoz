#include "homeworkselect.h"
std::list<std::pair<Lesson, std::list<Homework>>>::iterator HomeworkSelect::mFindLesson(Lesson& lesson)
{
	auto pair = mHomeworkList.begin();
	for (pair; pair != mHomeworkList.end(); pair++)
		if (pair->first.getName() == lesson.getName())
			return pair;
	return mHomeworkList.begin();
}
std::list<Homework>::iterator HomeworkSelect::mFindHomeworks(Homework& hw)
{
	auto pair = mFindLesson(*hw.getLesson());
	auto hwlist = pair->second.begin();
	for (hwlist = pair->second.begin(); hwlist != pair->second.end(); hwlist++)
		if (hwlist->getContex() == hw.getContex())
			return hwlist;
	return pair->second.begin();
}
std::list<Homework> HomeworkSelect::getHomeworkList(Lesson lesson)
{
	auto hwlist = mFindLesson(lesson);
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
	mHomeworkList.push_back({ lesson, std::list<Homework>() });
}
void HomeworkSelect::EraseLesson(Lesson lesson)
{
	auto hwlist = mFindLesson(lesson);
	mHomeworkList.erase(hwlist);
}
void HomeworkSelect::AddHomework(Homework homework)
{
	auto list = mFindLesson(*homework.getLesson());
	list->second.push_back(homework);
}
void HomeworkSelect::EraseHomework(Homework homework)
{
	auto hwlist = mFindLesson(*homework.getLesson());
	auto hw = mFindHomeworks(homework);
	hwlist->second.erase(hw);
}
