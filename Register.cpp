#include "pch.h"
#include "Register.hpp"
#include "Role.hpp"
#include "StudentRole.hpp"
#include "Person.hpp"
#include <vector>


Register* Register::mRegister;
std::vector<Person*> Register::mStudents;

Register* Register::getInstance()
{
	if (mRegister == 0) {
		mRegister = new Register();
	}
	return mRegister;
}

void Register::addStudent(Person* newStudent)
{
	std::vector<Role*> newStudentRoles = newStudent->getRoles();
	for (int i = 0; i < newStudentRoles.size(); i++) {
		if (newStudentRoles[i]->getType() == Role::STUDENT_ROLE)
			mStudents.push_back(newStudent);
	}

}


std::vector<Grade*> Register::getStudentGradesByFullName(std::string firstName, std::string lastName)
{
	
	for (int i = 0; i < mStudents.size(); i++) {
	
		if (mStudents[i]->getLastName() == lastName && mStudents[i]->getFirstName() == firstName) {
			
			
			std::vector<Role*> personRoles = mStudents[i]->getRoles();
			
			for (int j = 0; j < personRoles.size(); j++) {
				
				
				if (personRoles[j]->getType() == Role::STUDENT_ROLE) {
					StudentRole* studentRole = static_cast<StudentRole*>(personRoles[j]);
					return studentRole->getGrades();
				}
			}
		}
	}

	
}





