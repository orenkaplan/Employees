#pragma once
#include "People.h"

#include <string>

// no static because only one instance

class myMenu
{
private:
	/* static */ People * pplList;
	/* static */ std::string strOption[10];
	/* static */ int intMenuStatus;
	/* static */ int intMenuSelection;
	/* static */ char chrCreatePerson;
	/* static */ std::string strName;
	/* static */ bool blActive;
	/* static */ char chrType;
	/* static */ long lngSalary;
	/* static */ char chrStatus;
	/* static */ bool blFits;

protected:
	int getMenuStatus();

public:
	char getCreateType();
	int getSelection();
	std::string getCName();
	bool getCActive();
	char getCType();
	long getCSalary();
	char getCStatus();
	bool getCFit();
	void mnuAct();
	void mnuInit();
	myMenu();
	~myMenu();
};