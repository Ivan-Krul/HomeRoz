#pragma once
#include <vector>
#include "homework.h"
#include "lesson.h"
class HomeMGR
{
	std::vector<Lesson> lessons_;
	std::vector<std::vector<Homework>> homeworks_;
public:
	size_t SizeLessons();
	size_t SizeHomeworks(size_t lesson_index);
	Lesson GetLesson(size_t index);
	Homework GetHomework(size_t lesson_index, size_t homework_index);
	void PushLesson();
	void PushHomework(size_t lesson_index);
	void PopLesson(size_t index);
	void PopHomework(size_t lesson_index, size_t homework_index);
	void SetLesson(size_t index, Lesson lesson);
	void SetHomework(size_t lesson_index, size_t homework_index, Homework homework);
	void SetLessonName(size_t lesson_index, std::string name);
	void SetLessonLink(size_t lesson_index, std::string link);
	void SetHomeworkContext(size_t lesson_index, size_t homework_index, std::string context);
	void SetHomeworkDateFrom(size_t lesson_index, size_t homework_index, date_week::Date date);
	void SetHomeworkDateTo(size_t lesson_index, size_t homework_index, date_week::Date date);
	void SetHomeworkDone(size_t lesson_index, size_t homework_index, bool done);
};

