#pragma once
#include "People.h"
#include "Employee.h"

#include <string>

// no static because only one instance

class myMenu
{
private:
	/* static */ std::string strOption[10];
	/* static */ int intMenuStatus;
	/* static */ int intMenuSelection;
	/* static */ char chrCreatePerson;
	/* static */ std::string strName;
	/* static */ bool blActive;
	/* static */ char chrType;
	/* static */ long lngCSerial;
	/* static */ long lngCSalary;
	/* static */ char chrStatus;
	/* static */ bool blFits;
	bool isExit(std::string strInput);
	void mnuInitAdd(int intIndex);
	bool mnuActAdd();
	void mnuInitSelect(int intIndex);
	bool mnuActSelect();
	void mnuInitChange(int intIndex);
	bool mnuActChange();
	bool mnuShow(char chrType = '\0');
	bool mnuShow(long lngExistingSerial);
	bool mnuShowStats();

public:
	/* static */ People * pplList;
	void getData(bool blFromUser = false, bool blCandidate = false);
	long getSerial();
	long getCSerial();
	std::string getCName();
	bool getCActive();
	long getCSalary();
	char getCType();
	char getCStatus();
	bool getCFit();
	int getMenuStatus();
	char getCreateType();
	int getSelection();
	int getListSize();
	void mnuAct();
	void mnuInit();
	myMenu();
	~myMenu();
};