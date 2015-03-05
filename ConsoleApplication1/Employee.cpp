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
};

char Employee::getType()
{
	return *chrType;
};

string Employee::getString()
{
	string strRetVal = "";
	switch (this->getType())
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
	strRetVal = strRetVal + "employee " + this->getName() + ", number " + to_string(this->getSerial()) + " is";
	if (!this->isActive())
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
	return this->getSerial() != NULL && this->getName() != to_string(NULL) && this->isActive() != NULL
		&& this->getType() != NULL && this->getSalary() != NULL;
};

void Employee::terminate()
{
	this->setActive(false);
};

void Employee::activate(long lngNewSalary)
{
	this->setActive(true);
	this->setSalary(lngNewSalary);
};

ostream & operator << (ostream & ostMyStream, const Employee & empB)
{
	ostMyStream << const_cast<Employee&>(empB).getString();
	return ostMyStream;
};

void Employee::operator= (Employee & empB)
{
	this->setSerial(empB.getSerial());
	this->setActive(empB.isActive());
	this->setName(empB.getName());
	this->setType(empB.getType());
	this->setSalary(empB.getSalary());
};

bool operator== (Employee & empA, Employee & empB)
{
	return empA.getSerial() == empB.getSerial() && empA.isActive() == empB.isActive() && empA.getName() == empB.getName()
		&& empA.getType() == empB.getType() && empA.getSalary() == empB.getSalary();
};

bool operator== (Employee & empB, Person & prsB)
{
	return empB.getSerial() == prsB.getSerial() && empB.isActive() == prsB.isActive() && empB.getName() == prsB.getName();
};

bool operator== (Person & prsB, Employee & empB)
{
	return empB == prsB;
};


Employee::Employee()
{
	People pplGet;
	this->setSerial(pplGet.getNewSerial());
	this->setSalary(NULL);
	this->setType(NULL);
	addEmployee(*this);
}

Employee::Employee(std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive)
{
	People pplGet;
	this->setSerial(pplGet.getNewSerial());
	this->setName(strNewName);
	this->setSalary(lngNewSalary);
	this->setType(chrNewType);
	this->setActive(blIsActive);
	addEmployee(*this);
}

Employee::Employee(Employee & empB)
{
	People pplGet;
	*this = empB;
	this->setSerial(pplGet.getNewSerial());
	addEmployee(*this);
};

Employee::~Employee()
{
	remEmployee(*this);
	this->setSerial(NULL);
	this->setName(NULL);
	this->setActive(NULL);
	delete lngSalary;
	delete chrType;
};
