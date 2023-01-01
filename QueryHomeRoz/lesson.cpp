#include "lesson.h"
namespace query_home_roz
{
	Lesson::Lesson(std::string name, std::string link, std::vector<date_week::Week> weeks)
	{
		name_ = name;
		link_ = link;
		weeks_ = weeks;
	}

	std::vector<date_week::Week>::iterator Lesson::BeginWeeks()
	{
		return weeks_.begin();
	}

	std::vector<date_week::Week>::iterator Lesson::EndWeeks()
	{
		return weeks_.end();
	}

	size_t Lesson::SizeWeek()
	{
		return weeks_.size();
	}

	date_week::Week& Lesson::GetWeek(size_t index)
	{
		return weeks_[index];
	}

	std::string Lesson::GetName()
	{
		return name_;
	}

	std::string Lesson::GetLink()
	{
		return link_;
	}

	void Lesson::SetName(std::string name)
	{
		name_ = name;
	}

	void Lesson::SetLink(std::string link)
	{
		link_ = link;
	}

	void Lesson::PushWeek(date_week::Week week)
	{
		weeks_.push_back(week);
	}

	void Lesson::PopWeek(std::vector<date_week::Week>::iterator iter)
	{
		weeks_.erase(iter);
	}
}
