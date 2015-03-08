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
	cout << "Welcome to Gil's HR application." << endl << endl;
	myMenu * mnuMyUI = new myMenu;
	while (mnuMyUI->getSelection() != -1)
	{
		mnuMyUI->mnuAct();
		if (mnuMyUI->getSelection() == -1)
		{
			break;
		}
		switch (mnuMyUI->getCreateType())
		{
			case 'e':
			{
				Employee * empNew = new Employee;
			}
				break;
			case 'E':
			{
				Employee * empInit =
					new Employee(mnuMyUI->getCName(), mnuMyUI->getCSalary(), mnuMyUI->getCType(), mnuMyUI->getCActive());
			}
				break;
			case 'c':
			{
				Candidate * cndNew = new Candidate;
			}
				break;
			case 'C':
			{
				Candidate * cndInit =
					new Candidate(mnuMyUI->getCName(), mnuMyUI->getCType(), mnuMyUI->getCActive(), mnuMyUI->getCFit(), mnuMyUI->getCStatus());
			}
				break;
			default:
				break;
		}
		system("cls");
		mnuMyUI->mnuInit();
	}
	delete mnuMyUI;
    return 0;
};
