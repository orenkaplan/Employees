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

bool Employee::isInitialized()
{
	return getSerial != NULL && getName != NULL && isActive != NULL
		&& getType !=NULL && getSalary != NULL;
}

void Employee::terminate()
{
	set(false);
}

void Employee::activate(long lngNewSalary)
{
	set(true);
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

void Employee::operator= (Employee & empB)
{
	set(empB.getSerial);
	set(*empB.isActive);
	setName(*empB.getName);
	set(*empB.getType);
	setSalary(*empB.getSalary);
}

bool Employee::operator== (Employee & empB)
{
	return getSerial == *empB.getSerial && isActive == *empB.isActive && getName == *empB.getName
		&& getType == *empB.getType && getSalary == *empB.getSalary;
}

bool Employee::operator== (Candidate & cndB)
{
	Employee & empTemp = dynamic_cast<Employee&>(cndB);
	if (&empTemp == nullptr)
	{
		return false;
	}
	else
	{
		return getSerial == empTemp.getSerial && isActive == empTemp.isActive && getName == empTemp.getName
			&& getType == empTemp.getType && getSalary == empTemp.getSalary;
	}
}


Employee::Employee()
{
	People pplGet;
	set(pplGet.getNewSerial);
	setName("");
	setSalary(0);
	set('t');
	set(false);
	pplGet.addPerson(*this);
}

Employee::Employee(string strNewName, long lngNewSalary, char chrNewType, bool blIsActive)
{
	People pplGet;
	set(pplGet.getNewSerial);
	setName(strNewName);
	setSalary(lngNewSalary);
	set(chrNewType);
	set(blIsActive);
	pplGet.addPerson(*this);
}

Employee::Employee(Employee & empB)
{
	People pplGet;
	pplGet.addPerson(empB);
	set(pplGet.getNewSerial);
}

Employee::~Employee()
{
	People pplDel;
	set((long)-1);
	setName("");
	set(false);
	delete lngSalary;
	delete chrType;
	pplDel.remPerson(*this);
}
