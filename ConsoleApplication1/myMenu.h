#pragma once
#include "Person.h"
#include "Employee.h"
#include "Candidate.h"
#include "People.h"


class myMenu
{
private:
	static People * pplList;
	static string * strOption;
	static int * intMenuStatus;
	static int * intMenuSelection;

public:
	void MenuInit();
	myMenu();
	~myMenu();
};

