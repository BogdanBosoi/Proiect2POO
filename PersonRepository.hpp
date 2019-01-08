#pragma once
#include "Repository.hpp"
#include "Person.hpp"


class PersonRepository : public Repository<Person> {
public:
	Person* findByCNP(std::string CNP) {
		for (int i = 0; i < mEntities.size(); i++) {

			if (mEntities[i]->getCNP() == CNP)
				return mEntities[i];
		}
		return 0;
	}
	Person* findByFullName(std::string lastName, std::string firstName) {

		
		for (int i = 0; i < mEntities.size(); i++) {

			
			if (mEntities[i]->getLastName() == lastName && mEntities[i]->getFirstName() == firstName)
				return mEntities[i];
		}

		
		return 0;

	}
	bool areTeachers() {
		for (int i = 0; i < mEntities.size(); i++)
		{
			std::vector<Role *>tempRoles;
			tempRoles = mEntities[i]->getRoles();
			if (tempRoles[tempRoles.size() - 1]->getType() == Role::TEACHER_ROLE)
				return 1;
		}
		return 0;
	}

};




