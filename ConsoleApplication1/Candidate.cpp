#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Candidate.h"


using namespace std;


bool Candidate::doesFit()
{
	return *blFits;
};

void Candidate::changeFits(bool blValue)
{
	*blFits = blValue;
};

string Candidate::getString()
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
			cout << "Bad candidate type." << endl << "Please start over and report to author." << endl;
			return strRetVal;
	}
	strRetVal = strRetVal + "candidate " + getName() + ", number " + to_string(getSerial());
	if (doesFit())
	{
		strRetVal = strRetVal + " fits ";
	}
	else
	{
		strRetVal = strRetVal + " doesn't fit ";
	}
	strRetVal = strRetVal + " the position and is";
	if (!isActive())
	{
		strRetVal = strRetVal + "n't";
	}
	strRetVal = strRetVal + " active in status " + getStatus() + ".";
	return strRetVal;
};

void Candidate::show()
{
	cout << *this << endl;
};

void Candidate::setStatus(char chrNewStatus)
{
	*intStatus = intStat(chrNewStatus);
	if (getStatus() == 'p')
	{
		changeFits(true);
	}
};

long Candidate::getSalary()
{
	return NULL;
};

char Candidate::getType()
{
	return NULL;
};

char Candidate::getStatus()
{
	return chrStat(*intStatus);
};

int Candidate::intStat(char chrConvStat)
{
	int intRetVal;
	switch (chrConvStat)
	{
	case 'c':
		intRetVal = 0;
		break;
	case 'r':
		intRetVal = 1;
		break;
	case 'i':
		intRetVal = 2;
		break;
	case 'p':
		intRetVal = 3;
		break;
	default:
		intRetVal = -1;
	}
	return intRetVal;
};

char Candidate::chrStat(int intConvStat)
{
	char chrRetVal;
	switch (intConvStat)
	{
		case -1:
			chrRetVal = 'd';
			break;
		case 0:
			chrRetVal = 'c';
			break;
		case 1:
			chrRetVal = 'r';
			break;
		case 2:
			chrRetVal = 'i';
			break;
		case 3:
			chrRetVal = 'p';
			break;
		default:
			chrRetVal = '\0';
	}
	return chrRetVal;
};

bool Candidate::isInitialized()
{
	return getSerial() != NULL && getName() != to_string(NULL) && isActive() != NULL
		&& getType() != NULL && getSalary() != NULL
		&& getStatus() != NULL && doesFit() != NULL;
};

void Candidate::terminate()
{
	changeFits(false);
	setActive(false);
};

void Candidate::activate()
{
	changeFits(true);
	setActive(true);
};

ostream & operator << (ostream & ostMyStream, const Candidate & cndB)
{
	ostMyStream << const_cast<Candidate&>(cndB).getString();
	return ostMyStream;
};

void Candidate::operator= (Candidate & cndB)
{
	setSerial(cndB.getSerial());
	setActive(cndB.isActive());
	setName(cndB.getName());
	setType(cndB.getType());
	setSalary(cndB.getSalary());
	changeFits(cndB.doesFit());
	setStatus(cndB.getStatus());
};

bool employ(Candidate & cndFitsAs, Employee & empNewEmployee)
{
	bool blRetVal = false;
	if (cndFitsAs.doesFit() && cndFitsAs.isActive() && cndFitsAs.getStatus() == 'p' && cndFitsAs.getSalary() != 0)
	{
		Employee empTemp = Employee(cndFitsAs.getName(), cndFitsAs.getSalary(), cndFitsAs.getType(), cndFitsAs.isActive());
		cndFitsAs.setSerial(cndFitsAs.getSerial());
		remCandidate(cndFitsAs);
		addEmployee(empNewEmployee);
		blRetVal = true;
	}
	return blRetVal;
};

bool operator== (Candidate & cndA, Candidate & cndB)
{
	return cndA.getSerial() == cndB.getSerial() && cndA.isActive() == cndB.isActive() && cndA.getName() == cndB.getName()
		&& cndA.getType() == cndB.getType() && cndA.getSalary() == cndB.getSalary()
		&& cndA.doesFit() == cndB.doesFit() && cndA.getStatus() == cndB.getStatus();
};

bool operator== (Candidate & cndB, Person & prsB)
{
	return cndB.getSerial() == prsB.getSerial() && cndB.isActive() == prsB.isActive() && cndB.getName() == prsB.getName();
};

bool operator== (Person & prsB, Candidate & cndB)
{
	return cndB == prsB;
};

bool operator== (Candidate & cndB, Employee & empB)
{
	return cndB.getSerial() == empB.getSerial() &&
		cndB.isActive() == empB.isActive() &&
		cndB.getName() == empB.getName() &&
		cndB.getType() == empB.getType() &&
		cndB.getSalary() == empB.getSalary();
};

bool operator== (Employee & empB, Candidate & cndB)
{
	return cndB == empB;
};


Candidate::Candidate()
{
	People pplGet;
	setSerial(pplGet.getNewSerial());
	setSalary(NULL);
	setType(NULL);
	changeFits(NULL);
	setStatus(NULL);
	addCandidate(*this);
};

Candidate::Candidate(std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat)
{
	People pplGet;
	setSerial(pplGet.getNewSerial());
	setName(strNewName);
	setType(chrNewType);
	setActive(blIsActive);
	changeFits(blDoesFit);
	setStatus(chrNewStat);
	addCandidate(*this);
};

Candidate::Candidate(Candidate & cndB)
{
	People pplGet;
	*this = cndB;
	setSerial(pplGet.getNewSerial());
	addCandidate(*this);
};

Candidate::~Candidate()
{
	remCandidate(*this);
	setSerial(NULL);
	setName(NULL);
	setActive(NULL);
	setType(NULL);
	setSalary(NULL);
	delete intStatus;
	delete blFits;
};