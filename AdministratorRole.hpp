#pragma once
#include <vector>
#include "Role.hpp"
#include "Activity.hpp"
class AdministratorRole: public Role {
public:
	AdministratorRole();

private:
	std::vector < Activity* > mActivities;
};