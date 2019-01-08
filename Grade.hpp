#pragma once
#include "Discipline.hpp"


class Grade {
public :
	
	Grade();
	Grade(float);
	Grade(float, Discipline*);

	float getGrade();
	void setGrade(float);
	Discipline* getDiscipline();
	void setDiscipline(Discipline*);

private:
	float mGrade;
	Discipline* mDiscipline;
};

