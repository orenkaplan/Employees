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
			intMySize = mnuMyUI->getListSize();
			mnuMyUI->pplList->prsTempList = new Person*[intMySize + 1];
			switch (mnuMyUI->getCreateType())
			{
			case 'e':
				mnuMyUI->pplList->prsTempList[intMySize] = new Employee;
				break;
			case 'E':
				mnuMyUI->getData(true);
				mnuMyUI->pplList->prsTempList[intMySize] =
					new Employee(mnuMyUI->getCName(), mnuMyUI->getCSalary(), mnuMyUI->getCType(), mnuMyUI->getCActive());
				break;
			case 'c':
				mnuMyUI->pplList->prsTempList[intMySize] = new Candidate;
				break;
			case 'C':
				mnuMyUI->getData(true, true);
				mnuMyUI->pplList->prsTempList[intMySize] =
					new Candidate(mnuMyUI->getCName(), mnuMyUI->getCType(), mnuMyUI->getCActive(), mnuMyUI->getCFit(), mnuMyUI->getCStatus());
				break;
			default:
				break;
			}
			intMySize++;
			mnuMyUI->pplList->addPrs(); //move this function here because of the new declarations
		}
		system("cls");
		mnuMyUI->mnuInit();
	}
	delete mnuMyUI;
    return 0;
};
