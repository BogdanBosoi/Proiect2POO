#include "pch.h"
#include "StudentRole.hpp"
#include "Register.hpp"


StudentRole::StudentRole() :Role(Role::STUDENT_ROLE) {
}

std::vector<Grade*> StudentRole::getGrades()
{
	return mGrades;
}

void StudentRole::addGrade(Grade * grade)
{
	mGrades.push_back(grade);
}

void StudentRole::setStudyGroup(int sArg) {
	mStudyGroup = sArg;
}