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
	cout << getString() << '\n';
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
};

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
	return getSerial() != -1 && getName() != to_string(NULL)
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

Employee::Employee(const People & pplGet)
{
	lngSalary = new long;
	chrType = new char;
	setSerial(const_cast<People&>(pplGet).getNewSerial());
	setSalary(-1);
	setType('\0');
}

Employee::Employee(const People & pplGet, std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive)
{
	lngSalary = new long;
	chrType = new char;
	setSerial(const_cast<People&>(pplGet).getNewSerial());
	setName(strNewName);
	setSalary(lngNewSalary);
	setType(chrNewType);
	setActive(blIsActive);
}

Employee::Employee(const People & pplGet, const Employee & empB)
{
	lngSalary = new long;
	chrType = new char;
	*this = const_cast<Employee&>(empB);
	setSerial(const_cast<People&>(pplGet).getNewSerial());
};

Employee::~Employee()
{
	int intIndex = getIndex(getSerial());
	if (intIndex != -1)
	{
		remPerson(intIndex);
	}
	setSerial(-1);
	setName(to_string(NULL));
	setActive(NULL);
	delete lngSalary;
	delete chrType;
};


ostream & operator << (ostream & ostMyStream, const Employee & empB)
{
	ostMyStream << const_cast<Employee&>(empB).getString();
	return ostMyStream;
};

bool operator== (const Employee & empA, const Employee & empB)
{
	return const_cast<Employee&>(empA).getSerial() == const_cast<Employee&>(empB).getSerial()
		&& const_cast<Employee&>(empA).isActive() == const_cast<Employee&>(empB).isActive()
		&& const_cast<Employee&>(empA).getName() == const_cast<Employee&>(empB).getName()
		&& const_cast<Employee&>(empA).getType() == const_cast<Employee&>(empB).getType()
		&& const_cast<Employee&>(empA).getSalary() == const_cast<Employee&>(empB).getSalary();
};

bool operator== (const Employee & empB, const Person & prsB)
{
	return const_cast<Employee&>(empB).getSerial() == const_cast<Person&>(prsB).getSerial()
		&& const_cast<Employee&>(empB).isActive() == const_cast<Person&>(prsB).isActive()
		&& const_cast<Employee&>(empB).getName() == const_cast<Person&>(prsB).getName();
};

bool operator== (const Person & prsB, const Employee & empB)
{
	return const_cast<Employee&>(empB) == const_cast<Person&>(prsB);
};