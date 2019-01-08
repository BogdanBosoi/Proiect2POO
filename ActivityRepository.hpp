#pragma once
#include "Repository.hpp"
#include "Activity.hpp"

class ActivityRepository : public Repository<Activity> {

public:
	std::vector<Activity*> findActivitiesByOwner(Person* pArg) {
		std::vector<Activity*> activities;

		for (int i = 0; i < mEntities.size(); i++) {

			if (mEntities[i]->getOwner()->getFirstName() == pArg->getFirstName() &&
				mEntities[i]->getOwner()->getLastName() == pArg->getLastName()) {

				activities.push_back(mEntities[i]);

			}

		}

		return activities;
	}
	std::vector<Activity*> findActivitiesByRoom(Room* rArg) {
		std::vector<Activity*> activities;

		for (int i = 0; i < mEntities.size(); i++) {

			if (mEntities[i]->getLocation() == rArg)
				activities.push_back(mEntities[i]);

		}

		return activities;
	}
	

};


