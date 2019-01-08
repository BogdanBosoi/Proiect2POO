#pragma once

#include <iostream>
#include "PersonRepository.hpp"
#include "ActivityRepository.hpp"
#include "RoomRepository.hpp"
#include "Register.hpp"
#include "StudentRole.hpp"

class Menu
{
private:
	static Menu* instance;
	int choose;
	Menu();

public:
	Person* createPerson();
	void deletePerson(PersonRepository * pRepo, ActivityRepository * aRepo);
	void assignRole(PersonRepository * pRepo);
	Room * createRoom();
	void deleteRoom(RoomRepository * rRepo, ActivityRepository * aRepo);
	void addRegister(PersonRepository * pRepo, Register * reg);
	Activity * createActivity(PersonRepository * pRepo, RoomRepository * rRepo);
	void deleteActivity(ActivityRepository * aRepo, PersonRepository * pRepo, RoomRepository * rRepo);
	void listActivities(ActivityRepository * rRepo);
	void listPersons(PersonRepository * pRepo);
	void listRooms(RoomRepository *rRepo);
	void addGrade(PersonRepository * pRepo);
	void update();
	static Menu* getInstance();
};

