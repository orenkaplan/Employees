#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#if !defined(Employee_h)
#include "Employee.h"
#endif
#if !defined(People_h)
#include "People.h"
#endif


using namespace std;


long Employee::getSalary()
{
	return *lngSalary;
};

char Employee::getType()
{
	return *chrType;
};

string Employee::getString()
{
	string strRetVal = "";
	switch (*this->getType)
	{
	case 'g':
		strRetVal = "Global ";
		break;
	case 't':
		strRetVal = "Temporary ";
		break;
	case 'h':
		strRetVal = "Hourly ";
		break;
	default:
		cout << "Bad candidate type." << endl << "Please start over and report to author." << endl;
		return strRetVal;
	}
	strRetVal = strRetVal + "employee " + *this->getName + ", number " + getSerial + " is";
	if (!isActive)
	{
		strRetVal = strRetVal + "n't";
	}
	strRetVal = strRetVal + " active.";
	return strRetVal;
};

void Employee::show()
{
	cout << *this << endl;
};

void Employee::setType(char chrNewType)
{
	*chrType = chrNewType;
};;

void Employee::setSalary(long lngNewSalary)
{
	*lngSalary = lngNewSalary;
};

bool Employee::isInitialized()
{
	return getSerial != NULL && getName != NULL && isActive != NULL
		&& getType !=NULL && getSalary != NULL;
};

void Employee::terminate()
{
	setActive(false);
};

void Employee::activate(long lngNewSalary)
{
	setActive(true);
	setSalary(lngNewSalary);
};

ostream & operator << (ostream & ostMyStream, const Employee & empB)
{
	ostMyStream << empB.getString;
	return ostMyStream;
};

void Employee::operator= (Employee & empB)
{
	setSerial(empB.getSerial);
	setActive(empB.isActive);
	setName(empB.getName);
	setType(empB.getType);
	setSalary(empB.getSalary);
};

bool Employee::operator== (Employee & empB)
{
	return getSerial == empB.getSerial && isActive == empB.isActive && getName == empB.getName
		&& getType == empB.getType && getSalary == empB.getSalary;
};

bool operator== (Employee & empB, Person & prsB)
{
	return empB.getSerial == prsB.getSerial && empB.isActive == prsB.isActive && empB.getName == prsB.getName;
};

bool operator== (Person & prsB, Employee & empB)
{
	return prsB.getSerial == empB.getSerial && prsB.isActive == empB.isActive && prsB.getName == empB.getName;
};


Employee::Employee()
{
	People pplGet;
	setSerial(pplGet.getNewSerial);
	setSalary(NULL);
	setType(NULL);
	addPerson(*this);
}

Employee::~Employee()
{
	remPerson(*this->getSerial);
	setSerial(NULL);
	setName(NULL);
	setActive(NULL);
	delete lngSalary;
	delete chrType;
};
