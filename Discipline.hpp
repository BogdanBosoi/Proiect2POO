#pragma once
#include <string>
#include "Activity.hpp"
#include <vector>

class Discipline {
public:

	Discipline();
	Discipline(std::string);

	std::string getName();
	void setName(std::string);

private:
	std::string mName;
	std::vector<Activity*> mActivities;
};