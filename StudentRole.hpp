#pragma once
#include "Role.hpp"
#include "Grade.hpp"
#include "Discipline.hpp"
class StudentRole : public Role{
public:
	StudentRole();
	std::vector<Grade*> getGrades();
	void addGrade(Grade* grade);
	void setStudyGroup(int);

private:

	std::vector<Grade*> mGrades;
	std::vector<Discipline*> mDisciplines;

	int mStudyGroup;
};
