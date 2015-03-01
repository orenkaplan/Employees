#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Employee.h"


using namespace std;


long Employee::getSalary()
{
	return *lngSalary;
}

char Employee::getType()
{
	return *chrType;
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
	cout << "employee " << getName << ", number " << getSerial << " is";
	if (!isActive)
	{
		cout << "n't";
	}
	cout << " active." << endl;
}

void Employee::set(char chrNewType)
{
	*chrType = chrNewType;
}

void Employee::setSalary(long lngNewSalary)
{
	*lngSalary = lngNewSalary;
}

void Employee::terminate()
{
	setActive(false);
}

void Employee::activate(long lngNewSalary)
{
	setActive(true);
	setSalary(lngNewSalary);
}

long Employee::operator<< (Employee & empB)
{
	long lngRetVal;
	Employee & empTemp = *this;
	lngRetVal = empTemp.getSerial;
	lngRetVal << *empB.getSerial;
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
