#pragma once
#include "People.h"
#include "Employee.h"

#include <string>


class myMenu
{
private:
	std::string strOption[10];
	int intMenuStatus;
	int intMenuSelection;
	char chrCreatePerson;
	std::string strName;
	bool blActive;
	char chrType;
	long lngCSerial;
	long lngCSalary;
	char chrStatus;
	bool blFits;
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
	People * pplList;
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