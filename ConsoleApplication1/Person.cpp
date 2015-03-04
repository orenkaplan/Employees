#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Person.h"




using namespace std;



long Person::getSerial()
{
	return *lngSerial;
};

string Person::getName()
{
	return *strName;
};;

bool Person::isActive()
{
	return *blActive;
};

bool Person::isInitialized()
{
	return this->getSerial() != NULL && this->getName() != to_string(NULL) && this->isActive() != NULL;
};

void Person::show()
{
	// Pure Virtual - not relevant
};

ostream & operator << (ostream & ostMyStream, const Person & prsB)
{
	return ostMyStream; // Pure Virtual - not relevant
};

void Person::operator= (Person & prsB)
{
	this->setSerial(prsB.getSerial());
	this->setActive(prsB.isActive());
	this->setName(prsB.getName());
};

bool Person::operator== (Person & prsB)
{
	return this->getSerial() == prsB.getSerial() && this->isActive() == prsB.isActive() && this->getName() == prsB.getName();
};

void Person::setSerial(long lngNewSerial)
{
	*lngSerial = lngNewSerial;
};

void Person::setActive(bool blValue)
{
	*blActive = blValue;
};

void Person::setName(string strNewName)
{
	*strName = strNewName;
};

/* bool employ(Candidate & cndFitsAs, Employee & empNewEmployee)
{
	bool blRetVal = false;
	Employee * empTemp = &empNewEmployee;
	Candidate * cndTemp = &cndFitsAs;
	Person * prsTempEmployee = dynamic_cast<Person*>(empTemp);
	Person * prsTempCandidate = dynamic_cast<Person*>(cndTemp);
	Employee * empTempCandidate = dynamic_cast<Employee*>(cndTemp);
	if (cndTemp.doesFit && prsTempCandidate->isActive && cndFitsAs.getStatus == 'p' && empTempCandidate->getSalary != 0)
	{
		Employee empTemp = Employee(prsTempCandidate->getName, empTempCandidate->getSalary, empTempCandidate->getType, prsTempCandidate->isActive);
		prsTempEmployee->setSerial(prsTempCandidate->getSerial);
		remPerson(cndFitsAs);
		addPerson(empNewEmployee);
		blRetVal = true;
	}
	delete empTemp;
	delete cndTemp;
	delete prsTempEmployee;
	delete prsTempCandidate;
	delete empTempCandidate;
}; */


Person::Person()
{
	lngSerial = new long;
	strName = new string;
	blActive = new bool;
	this->setSerial(NULL);
	this->setName(NULL);
	this->setActive(NULL);
};

Person::Person(Person & prsB) 
{
	*this = prsB;
};

Person::~Person()
{
	delete lngSerial;
	delete strName;
	delete blActive;
};

