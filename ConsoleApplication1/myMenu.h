#pragma once
#if !defined(Person_h)
#include "Person.h"
#endif
#if !defined(Employee_h)
#include "Employee.h"
#endif
#if !defined(Candidate_h)
#include "Candidate.h"
#endif


#if !defined(string)
#include <string>
#endif

#if !defined(myMenu_h)
#define myMenu_h
#endif

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