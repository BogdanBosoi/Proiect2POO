// Proiect2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Menu.hpp"

int main()
{

	Menu *mainMenu = Menu::getInstance();
	/*
	Teacher t("", "", "");
	std::cin >> t;
	std::cout << t;

	int n;
	std::vector<Person> v;
	std::cin >> n;
	
	*/
	
	/*

	for (int i = 0; i < n; i++) {
		Teacher aux("","","");
		std::cin >> aux;
		v.push_back(aux);
	}
	
	for (int i = 0; i < n; i++) {
		std::cout << v.back;
	}

	
	for (int i = 0; i < n; i++) {
		Person aux("","","");
		std::cin >> aux;
		v.push_back(aux);
	}

	Person p1("alex", "popescu", "1231241");
	std::vector<Person*> persons;
	std::vector<Room*> rooms;
	std::vector<Activity*> activities;

	rooms.push_back(new Room("Sala 3"));
	persons.push_back(new Person("Popescu", "Alex", "12314"));
	activities.push_back(new Activity(rooms[0],persons[0],"asdasd"));
	persons[0]->addRole(Role::STUDENT_ROLE);

	RoomRepository roomRepository;
	Room* r1 = new Room("sala 31");
	roomRepository.add(new Room("sala 5"));
	roomRepository.add(new Room("sala 1"));
	roomRepository.add(r1);
	roomRepository.add(new Room("sala a"));
	roomRepository.add(new Room("sala C"));
	roomRepository.print();
	std::cout << std::endl;
	std::cout << std::endl;
	roomRepository.remove(r1);
	roomRepository.print();
	std::cout << std::endl << std::endl;

	PersonRepository personRepo;
	personRepo.add(new Person("Mihnea", "fff", "1234"));
	personRepo.add(new Person("Alex", "zzz", "4312"));
	personRepo.add(new Person("Mihai", "xcz", "132312"));
	personRepo.add(new Person("Silviu", "sf", "32432"));
	personRepo.add(new Person("Mircea", "fs", "5463"));
	personRepo.print();
	std::cout << "Persona cu cnp-ul 1234 este " << *personRepo.findByCNP("1234");
	std::cout << std::endl << std::endl;



	// Creez un nou registru si adaug cateva persone cu rol 
	// de studenti , pentru testare
	Discipline* programare = new Discipline("Programare");
	Discipline* analiza = new Discipline("Analiza");
	Discipline* poo = new Discipline("Poo");

	Grade* programareGrade = new Grade(10,programare);
	Grade* analizaGrade = new Grade(9,analiza);
	Grade* pooGrade = new Grade(10,poo);


	Register* mRegister = Register::instance();
	Person* p0 = new Person("Bogdan", "Dumitru", "12345");
	Person* p2 = new Person("Alex", "Popescu", "42345");
	Person* p3 = new Person("Anca", "Ionescu", "63345");
	Person* p4 = new Person("Maria", "Tanase", "87345");

	p0->addRole(Role::STUDENT_ROLE);
	p2->addRole(Role::STUDENT_ROLE);
	p3->addRole(Role::STUDENT_ROLE);
	p4->addRole(Role::STUDENT_ROLE);
	
	mRegister->addStudent(p0);
	mRegister->addStudent(p2);
	mRegister->addStudent(p3);
	mRegister->addStudent(p4);
	
	StudentRole* sr = static_cast<StudentRole*>(p0->getRoles().at(0));
	sr->addGrade(programareGrade);
	sr->addGrade(analizaGrade);
	sr->addGrade(pooGrade);

	std::vector<Grade*> grades = mRegister->getStudentGradesByFullName("Bogdan", "Dumitru");
	std::cout << grades[0]->getDiscipline()->getName() << " "<< grades[0]->getGrade() << std::endl;
	std::cout << grades[1]->getDiscipline()->getName() << " " << grades[1]->getGrade() << std::endl;
	std::cout << grades[2]->getDiscipline()->getName() << " " << grades[2]->getGrade() << std::endl;
	*/
/*
	Person* supreme = new Person("Alex","Alexandrescu","1234567");
	Room* sala1 = new Room("Sala 1");
	Room* sala2 = new Room("Sala 2");
	Room* sala3 = new Room("Sala 3");
	Room* sala4 = new Room("Sala 4");
	Room* sala5 = new Room("Sala 5");

	Activity* cursAnaliza = new Activity(sala1, supreme, "Curs Analiza");
	Activity* cursUso = new Activity(sala2, supreme, "Curs Uso");
	Activity* cursPC = new Activity(sala3, supreme, "Curs PC");
	Activity* cursGeo = new Activity(sala4, supreme, "Curs Geometrie");
	Activity* cursMs = new Activity(sala5, supreme, "Curs Mate Speciala");

	Discipline* analiza = new Discipline("analiza");
	Discipline* uso = new Discipline("uso");
	Discipline* pc = new Discipline("programare");
	Discipline* geo = new Discipline("geometire");
	Discipline* ms = new Discipline("matamatici speciale");

	ActivityRepository* mActivityRepository = new ActivityRepository;
	mActivityRepository->add(cursAnaliza);
	mActivityRepository->add(cursUso);
	mActivityRepository->add(cursPC);
	mActivityRepository->add(cursGeo);
	mActivityRepository->add(cursMs);

	Person* s1 = new Person("mihai", "marius", "1243");
	Person* s2 = new Person("lary", "king", "6443");
	Person* s3 = new Person("dark", "knight", "9999");
	Person* s4 = new Person("razvan", "tnk", "5423");
	Person* s5 = new Person("gigi", "alex", "1275");
	Person* s6 = new Person("paul", "pogba", "7642");

	s1->addRole(Role::STUDENT_ROLE);
	s2->addRole(Role::STUDENT_ROLE);
	s3->addRole(Role::STUDENT_ROLE);
	s4->addRole(Role::STUDENT_ROLE);
	s5->addRole(Role::STUDENT_ROLE);
	s6->addRole(Role::STUDENT_ROLE);

	StudentRole* sr = static_cast<StudentRole*>(s1->getRoles().at(0));
	sr->addGrade(new Grade(10, analiza));
	sr->addGrade(new Grade(9, uso));
	sr->addGrade(new Grade(10, ms));
	sr->addGrade(new Grade(9, pc));
	sr->addGrade(new Grade(9, geo));

	Register* mRegister = Register::instance();
	mRegister->addStudent(s1);
	mRegister->addStudent(s2);
	mRegister->addStudent(s3);
	mRegister->addStudent(s4);
	mRegister->addStudent(s5);

	std::vector<Grade*> grades = mRegister->getStudentGradesByFullName("mihai", "marius");

	for (int i = 0; i < grades.size(); i++)
		std::cout << grades[i]->getDiscipline()->getName() << " " << grades[i]->getGrade() << std::endl;
*/
return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
