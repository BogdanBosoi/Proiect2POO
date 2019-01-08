#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include "Role.hpp"

class Person {
public:
	Person();
	Person(std::string FirstName, std::string LastName, std::string CNP , std::string Email = "");
	
	std::string getFirstName();
	void setFirstName(std::string);
	std::string getLastName();
	void setLastName(std::string);
	std::string getCNP();
	void setCNP(std::string);
	std::string getEmail();
	void setEmail(std::string);
	std::vector<Role*> getRoles();
	void addRole(Role::RoleType roleType);

	friend std::istream& operator >> (std::istream& in,  Person & pArg);
	friend std::ostream& operator << (std::ostream& out, const Person& pArg);

protected:
	std::string mFirstName;
	std::string mLastName;
	std::string mCNP;
	std::string mEmail;
	std::vector<Role*> mRoles;
};