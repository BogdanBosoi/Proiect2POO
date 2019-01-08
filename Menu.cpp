#include "pch.h"
#include "Menu.hpp"


Menu* Menu::instance = 0;

Menu* Menu::getInstance() {
	if (instance == 0)
		instance = new Menu();
	return instance;
}

Menu::Menu(){
	update();
}

void Menu::update() {

	PersonRepository * pRepo = new PersonRepository;
	ActivityRepository * aRepo = new ActivityRepository;
	RoomRepository * rRepo = new RoomRepository;
	Register * reg = Register::getInstance();
	while (1) {
		system("cls");
		std::cout << "Choose one of the operations:\n1.Add a person.\n2.Delete a person\n3.Assign a role to a person\n4.Create a room\n5.Delete a room.\n6.Create an activity\n";
		std::cout << "7.Delete an activity\n8.Add a student to register\n9.List all persons\n10.List all activities\n11.List all rooms\n12.Add a grade to a student\n0.Exit\n";
		std::cin >> choose;



		switch (choose) {

		case 0:
			exit(0);
			break;
		case 1:
			pRepo->add(createPerson());
			break;
		case 2:
			deletePerson(pRepo, aRepo);
			break;
		case 3:
			assignRole(pRepo);
			break;

		case 4:
			rRepo->add(createRoom());
			break;

		case 5:
			deleteRoom(rRepo, aRepo);
			break;
		case 6:
			aRepo->add(createActivity(pRepo, rRepo));
			break;
		case 7:
			deleteActivity(aRepo, pRepo, rRepo);
			break;
		case 8:
			addRegister(pRepo, reg);
			break;
		case 9:
			listPersons(pRepo);
			break;
		case 10:
			listActivities(aRepo);
			break;
		case 11:
			listRooms(rRepo);
			break;
		case 12:
			addGrade(pRepo);
			break;

		}
		system("PAUSE");
	}
}

Person * Menu::createPerson() {
	Person *p = new Person;
	std::cin >> *p;
	return p;
}

void Menu::deletePerson(PersonRepository * pRepo, ActivityRepository * aRepo) {
	do {
		system("cls");
		std::cout << "Delete a person by:\n1.His name.\n2.Its numerical identification number.\n";
		std::cin >> choose;
	} while (choose == 1 || choose == 2);

	switch (choose) {
		case 1: {
			std::string fName, lName;
			std::cout << "Enter the last name:";
			std::cin >> fName;
			std::cout << "Enter the first name:";
			std::cin >> lName;
			if (pRepo->findByFullName(lName, fName) != 0) {
				std::vector <Activity*> replacement;
				replacement = aRepo ->findActivitiesByOwner(pRepo->findByFullName(lName, fName));
				if(replacement.size() != 0){ 
					std::cout << "Activities owned by this person found!\n 1.Remove them\n2.Replace the owner\n";
					int pChoose;

					pRepeat:
					std::cin >> pChoose;
					if (pChoose != 1 || pChoose != 2)
						goto pRepeat;

					switch (pChoose) {

					case 1:
						replacement.clear();
						break;
					case 2:
						if (pRepo->getSize() == 1) {
							std::cout << "There are no persons left. Proceeding to first option\n";
							replacement.clear();
							break;
						}
						else {
							do {
								std::cout << "Enter last name:";
								std::cin >> lName;
								std::cout << "Enter first name:";
								std::cin >> fName;
							} while (pRepo->findByFullName(lName, fName) == 0);
						
							for (int i = 0; i < replacement.size(); i++)
								replacement[i]->setOwner(pRepo -> findByFullName(lName, fName));
						}
					}

				}
				delete pRepo->findByFullName(lName, fName);
			}
			break;
		}
		case 2: {
			std::string NIN;
			std::cout << "Enter the numerical identification number.\n";
			std::cin >> NIN;
			if (pRepo ->findByCNP(NIN) != 0)
				delete pRepo->findByCNP(NIN);
			break;
		}
	}

}

void Menu::assignRole(PersonRepository * pRepo) {

	std::string lName, fName;
	repeatName:
	system("cls");
		std::cout << "Enter the last name of the person:";
		std::cin >> lName;
		std::cout << "Enter the first name of the person:";
		std::cin >> fName;
		if (pRepo->findByFullName(lName, fName) == 0)
			goto repeatName;
	
		Person *p = pRepo->findByFullName(lName, fName);

	repeatNumb:
		system("cls");
		std::cout << "Which role do you want to assign?\n1.Administrative\n2.Teacher\n3.Student\n4.Guest";
		std::cin >> choose;
		if (choose < 1 || choose > 4)
			goto repeatNumb;

	switch (choose) {
	case 1:
		p->addRole(Role::ADMINISTRATOR_ROLE);
		break;
	case 2:
		p->addRole(Role::TEACHER_ROLE);
		break;
	case 3: {
		int stdGroup;
		p->addRole(Role::STUDENT_ROLE);
		std::cout << "Enter study group:";
		std::cin >> stdGroup;
		StudentRole* sr = static_cast<StudentRole*>(p->getRoles().at(0));
		sr->setStudyGroup(stdGroup);
		break;
	}
	case 4:
		p->addRole(Role::GUEST_ROLE);
		break;
	}

}

Room * Menu::createRoom() {
	std::string rName;
	std::cout << "Enter the name of the room:";
	std::cin >> rName;
	Room * rArg = new Room(rName);
	return rArg;

}

void Menu::deleteRoom(RoomRepository * rRepo, ActivityRepository * aRepo) {

	system("cls");
	std::string rName;
	std::cout << "Enter the name of the room to be deleted:";
	std::cin >> rName;
	if (rRepo->findByName(rName) != 0) {

		std::vector < Activity * > replacement;
		replacement = aRepo->findActivitiesByRoom(rRepo->findByName(rName));
		if (replacement.size() != 0) {
			int pChoose;
			do {
				system("cls");
				std::cout << "There are activities which use this room.\n1.Delete them.\n2.Replace the room\n3.Abort";
				std::cin >> pChoose;
			} while (pChoose < 1 || pChoose > 3);

			switch (pChoose) {

			case 3:
				return ;
				break;
			case 2: {
				if (rRepo->getSize() == 1) {
					std::cout << "There are no other rooms. Abort or \n1.Proceeding to operation 1?\n";
					int aChoose;
					std::cin >> aChoose;
					if (aChoose == 1)
						replacement.clear();
					else
						return;
				}
				else {
					system("cls");
					std::cout << "Enter the room to replace the old one.";
					std::cin >> rName;
					for (int i = 0; i < replacement.size(); i++)
						replacement[i]->setLocation(rRepo->findByName(rName));
				}
			}
			case 1:
				replacement.clear();
				break;

			}
			

		}

	}

}

Activity * Menu::createActivity(PersonRepository * pRepo, RoomRepository * rRepo) {

	if (rRepo->getSize() == 0 || pRepo->getSize() == 0) {
		system("cls");
		std::cout << "There are not enough rooms or persons to assign to an activity\n";
		return NULL;
	}
	if (!pRepo->areTeachers()) {
		system("cls");
		std::cout << "There are no teachers to run the activities\n";
		return NULL;
	}
	std::string lName, fName, rName, desc;
	std::cout << "Choose a teacher to run the activity:\n";
	std::cout << "Enter the last name:\n";
	std::cin >> lName;
	std::cout << "Enter the first name:\n";
	std::cin >> fName;

	if (!pRepo->findByFullName(lName, fName))
		std::cout << "Invalid name!\n";

	std::cout << "Enter the name of the room:";
	std::cin >> rName;

	if (!rRepo->findByName(rName))
		std::cout << "Invalid room!\n";

	std::cout << "Enter a description for the activity:";
	std::cin >> desc;

	Activity * aArg = new Activity(rRepo->findByName(rName), pRepo->findByFullName(lName, fName), desc);
	return aArg;



}

void Menu::deleteActivity(ActivityRepository * aRepo, PersonRepository *pRepo, RoomRepository *rRepo) {

actRepeat:
	system("cls");
	std::cout << "Delete activity by:\n1.Name of the owner\n2.Name of the room\n3.Specific name and room\n";
	std::cin >> choose;
	if (choose < 1 || choose > 3)
		goto actRepeat;

	switch (choose) {
		case 1: {

			std::string lName, fName;
			std::cout << "Enter the last name:";
			std::cin >> lName;
			std::cout << "Enter the first name:";
			std::cin >> fName;

			aRepo->findActivitiesByOwner(pRepo->findByFullName(lName, fName)).clear();
			break;
		}

		case 2: {
		
			std::string rName;
			std::cout << "Enter the room name:";
			std::cin >> rName;

			aRepo->findActivitiesByRoom(rRepo->findByName(rName)).clear();

			break;
		}

		case 3: {

			std::string lName, fName, rName;
			std::cout << "Enter the last name:";
			std::cin >> lName;
			std::cout << "Enter the first name:";
			std::cin >> fName;
			std::cout << "Enter the room name:";
			std::cin >> rName;

			std::vector < Activity *> actVec;
			
			actVec = aRepo->findActivitiesByOwner(pRepo->findByFullName(lName, fName));
			for (int i = 0; i < actVec.size(); i++) {
				if (actVec[i]->getLocation()->getName() == rName) {
					actVec.erase(actVec.begin() + i);
					i--;
				}
			}
		}
	
	}



}

void Menu::addRegister(PersonRepository * pRepo, Register * reg){
	int pChoose;
	regRepeat:
	std::cout << "Add student by:\n1.Name\n2.NIC\3.Abort";
	std::cin >> pChoose;
	if (pChoose < 1 || pChoose > 3)
		goto regRepeat;
	
	switch (pChoose) {
	case 3:
		return;
		break;
	case 2: {
		std::string nic;
		std::cout << "Enter NIC:";
		std::cin >> nic;
		Person * p = pRepo->findByCNP(nic);
		std::vector <Role *> roles;
		roles = p->getRoles();
		if (p != 0 && roles[roles.size() - 1]->getType() == Role::STUDENT_ROLE)
			reg->addStudent(p);
		break;
	}
	case 1: {
		std::string lName, fName;
		std::cout << "Enter the last name:";
		std::cin >> lName;
		std::cout << "Enter the first name:";
		std::cin >> fName;
		Person * p = pRepo->findByFullName(lName, fName);

		std::vector <Role *> roles;
		roles = p->getRoles();
		if (p != 0 && roles[roles.size() - 1]->getType() == Role::STUDENT_ROLE)
			reg->addStudent(p);
		break;
		}
	}

}

void Menu::listPersons(PersonRepository * pRepo) {
	pRepo->print();
}

void Menu::listActivities(ActivityRepository * aRepo) {
	aRepo->print();
}

void Menu::listRooms(RoomRepository * rRepo) {
	rRepo->print();
}

void Menu::addGrade(PersonRepository * pRepo) {
	
	std::cout << "Select the student to add grade:\n";
	std::string lName, fName;

	std::cout << "Enter last name:";
	std::cin >> lName;
	std::cout << "Enter first name:";
	std::cin >> fName;

	Person * Stud = pRepo->findByFullName(lName, fName);
	if (Stud != 0 && Stud ->getRoles().back()->getType() == Role::STUDENT_ROLE) {
		std::string disc;
		float gra;
		std::cout << "Enter the name of the discipline:";
		std::cin >> disc;
		std::cout << "Enter the grade:";
		std::cin >> gra;
		StudentRole * sr = static_cast<StudentRole*>(Stud->getRoles().at(0));
		Discipline * dis = new Discipline(disc);
		Grade * grade = new Grade(gra, dis);
		sr->addGrade(grade);

	}
	return;

}