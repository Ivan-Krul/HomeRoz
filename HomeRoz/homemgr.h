#pragma once
#include <vector>
#include "homework.h"
#include "lesson.h"
class HomeMGR
{
	std::vector<Lesson> lessons_;
	std::vector<std::vector<Homework>> homeworks_;
private:
	bool CheckHomework_(const size_t lesson_index, const size_t homework_index);
public:
	constexpr size_t SizeLessons() noexcept;
	constexpr size_t SizeHomeworks(const size_t lesson_index);
	Lesson* GetLesson(const size_t index);
	Homework* GetHomework(const size_t lesson_index, const size_t homework_index);
	void PushLesson() noexcept;
	void Clear() noexcept;
	bool PushHomework(const size_t lesson_index);
	bool PopLesson(const size_t index);
	bool PopHomework(const size_t lesson_index, const size_t homework_index);
	bool SetLesson(const size_t index, const Lesson lesson);
	bool SetHomework(const size_t lesson_index, const size_t homework_index, Homework homework);
	bool SetLessonName(const size_t lesson_index, std::string name);
	bool SetLessonLink(const size_t lesson_index, std::string link);
	bool SetHomeworkContext(const size_t lesson_index, const size_t homework_index, std::string context);
	bool SetHomeworkDateFrom(const size_t lesson_index, const size_t homework_index, date_week::Date date);
	bool SetHomeworkDateTo(const size_t lesson_index, const size_t homework_index, date_week::Date date);
	bool SetHomeworkDone(const size_t lesson_index, const size_t homework_index, bool done);
};

