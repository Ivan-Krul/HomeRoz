#pragma once
#include <fstream>
#include <string>
#include "homeworkselect.h"
namespace table
{
	class SubFileTable
	{
		HomeworkSelect hw_select_;
	public:
		void Save(std::string dir);
		void Load(std::string dir);
		HomeworkSelect getHWSelect();
		void setHWSelect(HomeworkSelect hw_select);
		// UNDONE: Made methodes and their realisation
	};
}