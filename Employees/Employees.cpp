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
			if (intMySize > 0)
			{
				for (int i = 0; i < intMySize; i++)
				{
					if (dynamic_cast<Employee *>(mnuMyUI->pplList->prsList[i]))
					{
						mnuMyUI->pplList->prsTempList[i] = new Employee;
					}
					else if (dynamic_cast<Candidate *>(mnuMyUI->pplList->prsList[i]))
					{
						mnuMyUI->pplList->prsTempList[i] = new Candidate;
					}
					*mnuMyUI->pplList->prsTempList[i] = *mnuMyUI->pplList->prsList[i];
				}
			}
			intMySize++;
			mnuMyUI->pplList->prsList = new Person*[intMySize];
			mnuMyUI->pplList->lngSerialList = new long[intMySize];
			mnuMyUI->pplList->blEmpty = new bool[intMySize];
			for (int i = 0; i < intMySize; i++)
			{
				if (dynamic_cast<Employee *>(mnuMyUI->pplList->prsTempList[i]))
				{
					mnuMyUI->pplList->prsList[i] = new Employee;
				}
				else if (dynamic_cast<Candidate *>(mnuMyUI->pplList->prsTempList[i]))
				{
					mnuMyUI->pplList->prsList[i] = new Candidate;
				}
				*mnuMyUI->pplList->prsList[i] = *mnuMyUI->pplList->prsTempList[i];
				mnuMyUI->pplList->lngSerialList[i] = mnuMyUI->pplList->prsList[i]->getSerial();
				mnuMyUI->pplList->blEmpty[i] = mnuMyUI->pplList->prsList[i]->isInitialized();
			}
			mnuMyUI->pplList->setLastTouched(intMySize -1);
			mnuMyUI->pplList->addPrs();
		}
		system("cls");
		mnuMyUI->mnuInit();
	}
	delete mnuMyUI;
    return 0;
};
