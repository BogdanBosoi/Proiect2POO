#pragma once
#include "Room.hpp"
#include "Person.hpp"
#include <string>
#include <iostream>

class Activity {
public:
	
	Activity(Room* mLocation,Person* mOwner,std::string mDescription);
	Room* getLocation();
	void setLocation(Room*);
	Person* getOwner();
	void setOwner(Person*);
	std::string getDescription();
	void setDescription(std::string);
	friend std::ostream & operator << (std::ostream & out, Activity *);

protected:
	Room* mLocation;
	Person* mOwner;
	std::string mDescription;
};

