#include "pch.h"
#include "Person.hpp"
#include "StudentRole.hpp"
#include "TeacherRole.hpp"
#include <string>

Person::Person() {}

Person::Person(std::string FirstName, std::string LastName, std::string CNP, std::string Email):
	mFirstName(FirstName),mLastName(LastName),mCNP(CNP),mEmail(Email)
{
}

std::string Person::getFirstName()
{
	return mFirstName;
}

void Person::setFirstName(std::string FirstName) {
	mFirstName = FirstName;
}

std::string Person::getLastName() {
	return mLastName;
}

void Person::setLastName(std::string LastName) {
	mLastName = LastName;
}

std::string Person::getCNP() {
	return mCNP;
}

void Person::setCNP(std::string CNP) {
	mCNP = CNP;
}

std::string Person::getEmail() {
	return mEmail;
}

void Person::setEmail(std::string Email) {
	mEmail = Email;
}

std::vector<Role*> Person::getRoles() {
	return mRoles;
}

void Person::addRole(Role::RoleType roleType) {
	
	if (roleType == Role::STUDENT_ROLE) {
		mRoles.push_back(new StudentRole());
	}
	
	if (roleType == Role::TEACHER_ROLE) {
		mRoles.push_back(new TeacherRole());
	}

}

std::istream& operator >> (std::istream& in, Person& pArg) {
	in >> pArg.mFirstName >> pArg.mLastName >> pArg.mCNP >> pArg.mEmail;
	return in;
}

std::ostream& operator << (std::ostream& out, const Person& pArg) {
	out << pArg.mFirstName << " " << pArg.mLastName << " " << pArg.mCNP << " " << pArg.mEmail << std::endl;
	return out;
}













