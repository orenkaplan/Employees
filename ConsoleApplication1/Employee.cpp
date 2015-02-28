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
		{
			*lngGot = *lngSalary;
			strGot = NULL;
		}
			break;
		case 't':
		{
			*strGot = *chrType;
			lngGot = NULL;
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
	switch (*chrType)
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
	cout << "employee " << *strName << ", number " << *lngSerial << " is";
	if (!*blActive)
	{
		cout << "n't";
	}
	cout << " active." << endl;
}

void Employee::set(string strNewName)
{
	*strName = strNewName;
}

void Employee::set(char chrNewType)
{
	*chrType = chrNewType;
}

void Employee::set(long lngNewSalary)
{
	*lngSalary = lngNewSalary;
}

void Employee::terminate()
{
	*blActive = false;
}

void Employee::activate(long lngNewSalary)
{
	*blActive = true;
	set(lngNewSalary);
}

long Employee::operator<< (Employee & empB)
{
	long lngRetVal;
	lngRetVal = *lngSerial;
	lngRetVal << *empB.lngSerial;
	return lngRetVal;
}

long Employee::operator>> (Employee & empB)
{
	long lngRetVal;
	lngRetVal = *lngSerial;
	lngRetVal >> *empB.lngSerial;
	return lngRetVal;
}

void Employee::operator= (Employee & empB)
{
	*blActive = *empB.blActive;
	*strName = *empB.strName;
	*chrType = *empB.chrType;
	*lngSalary = *empB.lngSalary;
}

bool Employee::operator== (Employee & empB)
{
	return *blActive == *empB.blActive && *strName == *empB.strName
		&& *chrType == *empB.chrType && *lngSalary == *empB.lngSalary;
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
