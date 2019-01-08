#include "pch.h"
#include "Grade.hpp"
#include "pch.h"
#include "Grade.hpp"

Grade::Grade()
{
}

Grade::Grade(float grade) :mGrade(grade)
{
}

Grade::Grade(float grade, Discipline * discipline) : mGrade(grade), mDiscipline(discipline)
{

}

float Grade::getGrade()
{
	return mGrade;
}

void Grade::setGrade(float grade) {
	mGrade = grade;
}

Discipline* Grade::getDiscipline() {
	return mDiscipline;
}

void Grade::setDiscipline(Discipline* discipline) {
	mDiscipline = discipline;
}