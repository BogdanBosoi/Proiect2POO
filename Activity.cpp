#include "pch.h"
#include "Activity.hpp"
#include <typeinfo>
Activity::Activity(Room* mLocation, Person* mOwner, std::string mDescription) :
	mLocation(mLocation),
	mOwner(mOwner),
	mDescription(mDescription) 
{

}

Room * Activity::getLocation()
{
	return mLocation;
}

void Activity::setLocation(Room* location)
{
	mLocation = location;
}

Person * Activity::getOwner()
{
	return mOwner;
}

void Activity::setOwner(Person *owner)
{
	mOwner = owner;
}

std::string Activity::getDescription()
{
	return mDescription;
}

void Activity::setDescription(std::string description) 
{
	mDescription = description;
}

std::ostream & operator<<(std::ostream & out, Activity * activity) {
	out << activity->getDescription();
	return out;
}
