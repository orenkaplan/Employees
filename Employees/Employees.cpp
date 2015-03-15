// Employees.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "myMenu.h"
#include "Employee.h"
#include "Candidate.h"


using namespace std;


int main()
{
	cout << "Welcome to Gil's HR application.\n\n";
	myMenu * mnuMyUI = new myMenu;
	int intMySize;
	while (mnuMyUI->getSelection() != -1)
	{
		mnuMyUI->mnuAct();
		if (mnuMyUI->getSelection() == -1)
		{
			continue;
		}
		if (mnuMyUI->getCreateType() != '\0')
		{
			if (mnuMyUI->getListSize() == -1)
			{
				intMySize = 0;
			}
			else
			{
				intMySize = mnuMyUI->getListSize();
			}
			switch (mnuMyUI->getCreateType())
			{
				case 'E':
					if (mnuMyUI->getMenuStatus() == 1) // Get initialization data for new Employee
					{
						mnuMyUI->getData(true);
					}
					else if (mnuMyUI->getMenuStatus() == 2) // Get selected Employee to copy
					{
						mnuMyUI->getData();
					}
					break;
				case 'C':
					if (mnuMyUI->getMenuStatus() == 3) // Get initialization data for new Candidate
					{
						mnuMyUI->getData(true, true);
					}
					else if (mnuMyUI->getMenuStatus() == 4) // Get selected Candidate to copy
					{
						mnuMyUI->getData(false, true);
					}
					break;
				default:
					break;
			} // Create person with data aquired
			mnuMyUI->pplList->addPrs(mnuMyUI->getCreateType(), intMySize,
				mnuMyUI->getCName(), mnuMyUI->getCType(), mnuMyUI->getCActive(),
				mnuMyUI->getCSalary(),
				mnuMyUI->getCStatus(), mnuMyUI->getCFit());
			mnuMyUI->pplList->setLastTouched(intMySize);
		}
		system("cls");
		mnuMyUI->mnuInit();
	}
	delete mnuMyUI;
    return 0;
};
