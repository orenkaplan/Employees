#pragma once
#include "People.h"
//#include "Person.h"
//#include "Employee.h"
//#include "Candidate.h"

#include <string>

// forward declerations
//class Person;
//class Employee;
//class Candidate;
//class People;

class myMenu
{
private:
	static People * pplList;
	static std::string * strOption;
	static int * intMenuStatus;
	static int * intMenuSelection;

public:
	int getSelection();
	void MenuInit();
	myMenu();
	~myMenu();
};