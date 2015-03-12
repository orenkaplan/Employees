#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "Employee.h"


using namespace std;


string Employee::getString()
{
	string strRetVal = "";
	switch (getType())
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
		cout << "Bad employee type.\nPlease start over and report to author.\n";
		return strRetVal;
	}
	strRetVal = strRetVal + "employee " + getName() + ", number " + to_string(getSerial()) + " is";
	if (!isActive())
	{
		strRetVal = strRetVal + "n't";
	}
	strRetVal = strRetVal + " active.";
	return strRetVal;
};

void Employee::show()
{
	cout << /* *this */ getString() << '\n';
};

long Employee::getSalary()
{
	return *lngSalary;
};

char Employee::getType()
{
	return *chrType;
};

char Employee::getStatus()
{
	return '\0';
};

bool Employee::doesFit()
{
	return NULL;
};

void Employee::setType(char chrNewType)
{
	*chrType = chrNewType;
};;

void Employee::setSalary(long lngNewSalary)
{
	*lngSalary = lngNewSalary;
};

void Employee::setStatus(char chrNewStatus)
{
	return;
};

void Employee::changeFits(bool blValue)
{
	return;
};

void Employee::activate(long lngNewSalary)
{
	setActive(true);
	setSalary(lngNewSalary);
};

void Employee::terminate()
{
	setActive(false);
};

bool Employee::isInitialized()
{
	return getSerial() != -1 && getName() != to_string(NULL) /* && isActive() != NULL */
		&& getType() != '\0' && getSalary() != -1;
};

void Employee::operator= (Employee & empB)
{
	setSerial(empB.getSerial());
	setActive(empB.isActive());
	setName(empB.getName());
	setType(empB.getType());
	setSalary(empB.getSalary());
};


Employee::Employee()
{
	lngSalary = new long;
	chrType = new char;
	setSerial(-1);
	setSalary(-1);
	setType('\0');
}

Employee::Employee(People & pplGet)
{
	lngSalary = new long;
	chrType = new char;
	setSerial(pplGet.getNewSerial());
	setSalary(-1);
	setType('\0');
}

Employee::Employee(People & pplGet, std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive)
{
	lngSalary = new long;
	chrType = new char;
	setSerial(pplGet.getNewSerial());
	setName(strNewName);
	setSalary(lngNewSalary);
	setType(chrNewType);
	setActive(blIsActive);
}

Employee::Employee(People & pplGet, Employee & empB)
{
	lngSalary = new long;
	chrType = new char;
	*this = empB;
	setSerial(pplGet.getNewSerial());
};

Employee::~Employee()
{
	remPerson(getIndex(getSerial()));
	setSerial(-1);
	setName(to_string(NULL));
	setActive(NULL);
	delete lngSalary;
	delete chrType;
};


ostream & operator << (ostream & ostMyStream, Employee & empB)
{
	ostMyStream << empB.getString();
	return ostMyStream;
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