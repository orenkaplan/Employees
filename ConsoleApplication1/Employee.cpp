#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "Employee.h"


using namespace std;


void Employee::selectGet(char chrWTG)
{
	switch (chrWTG)
	{
		case 'p':
			lngGot = lngSalary;
			break;
		case 't':
			{
				strGot = chrType;
			}
			break;
		default:
			chooseGet(chrWTG);
	}
}

void Employee::get(char chrWhatToGet)
{
	selectGet(chrWhatToGet);
}

void Employee::show()
{
	switch (chrType)
	{
		case 'g':
			cout << "Global ";
			break;
		case 't':
			cout << "Temporary ";
			break;
		case 'h':
			cout << "Hourly ";
			break;
		default:
			cout << "Bad employee type." << endl << "Please start over and report to author." << endl;
			return;
	}
	cout << "employee " << strName << ", number " << lngSerial << " is";
	if (!blActive)
	{
		cout << "n't";
	}
	cout << " active." << endl;
}

void Employee::set(string strNewName)
{
	strName = strNewName;
}

void Employee::set(char chrNewType)
{
	chrType = chrNewType;
}

void Employee::set(long lngNewSalary)
{
	lngSalary = lngNewSalary;
}

void Employee::terminate()
{
	blActive = false;
}

void Employee::activate(long lngNewSalary)
{
	blActive = true;
	set(lngNewSalary);
}

long Employee::operator<< (Employee & empB)
{
	long lngResponse;
	empB.get('s');
	lngResponse = lngSerial;
	lngResponse << empB.lngGot;
	empB.get(' ');
	return lngResponse;
}

void Employee::operator= (Employee & empB)
{
	empB.get('a');
	blActive = empB.lngGot;
	empB.get('n');
	strName = empB.strGot;
	empB.get('t');
	chrType = empB.strGot;
	empB.get('p');
	lngSalary = empB.lngGot;
	empB.get(' ');
	get(' ');
}


Employee::Employee()
{

}

Employee::Employee(string strNewName, char chrNewType, bool blIsActive)
{

}

Employee::Employee(Employee &obj)
{

}

Employee::~Employee()
{

}
