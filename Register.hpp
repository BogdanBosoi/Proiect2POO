#pragma once
#include "Person.hpp"
#include "Grade.hpp"
#include <vector>

class Register {

public:
	static Register* getInstance();
	static void addStudent(Person*);
	static std::vector<Grade*> getStudentGradesByFullName(std::string,std::string);

private:
	Register() {};
	static Register* mRegister;
	static std::vector<Person*> mStudents;
};




