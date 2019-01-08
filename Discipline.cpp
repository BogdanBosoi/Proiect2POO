#include "pch.h"
#include "Discipline.hpp"
#include <string>

Discipline::Discipline()
{
}

Discipline::Discipline(std::string name) : mName(name)
{

}

std::string Discipline::getName() {
	return mName;
}

void Discipline::setName(std::string disciplineName) {
	mName = disciplineName;
}

