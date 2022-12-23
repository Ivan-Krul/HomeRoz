#pragma once
#include <vector>
#include "homework.h"
#include "lesson.h"
class HomeMGR
{
	std::vector<Lesson> lessons_;
	std::vector<std::vector<Homework>> homeworks_;
private:
	bool CheckHomework_(size_t lesson_index, size_t homework_index);
public:
	size_t SizeLessons();
	size_t SizeHomeworks(size_t lesson_index);
	Lesson* GetLesson(size_t index);
	Homework* GetHomework(size_t lesson_index, size_t homework_index);
	void PushLesson();
	void Clear();
	bool PushHomework(size_t lesson_index);
	bool PopLesson(size_t index);
	bool PopHomework(size_t lesson_index, size_t homework_index);
	bool SetLesson(size_t index, Lesson lesson);
	bool SetHomework(size_t lesson_index, size_t homework_index, Homework homework);
	bool SetLessonName(size_t lesson_index, std::string name);
	bool SetLessonLink(size_t lesson_index, std::string link);
	bool SetHomeworkContext(size_t lesson_index, size_t homework_index, std::string context);
	bool SetHomeworkDateFrom(size_t lesson_index, size_t homework_index, date_week::Date date);
	bool SetHomeworkDateTo(size_t lesson_index, size_t homework_index, date_week::Date date);
	bool SetHomeworkDone(size_t lesson_index, size_t homework_index, bool done);
};

