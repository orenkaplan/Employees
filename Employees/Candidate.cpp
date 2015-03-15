#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Candidate.h"


using namespace std;


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

char Candidate::chrStat(int intConvStat)
{
	char chrRetVal;
	switch (intConvStat)
	{
		case -1: // dummy
			chrRetVal = 'd';
			break;
		case 0:  // candidate
			chrRetVal = 'c';
			break;
		case 1:  // resume
			chrRetVal = 'r';
			break;
		case 2:  // interview
			chrRetVal = 'i';
			break;
		case 3:  // passed
			chrRetVal = 'p';
			break;
		default: // something is wrong
			chrRetVal = '\0';
	}
	return chrRetVal;
};

long Candidate::getSalary()
{
	return *lngSalary;
};

char Candidate::getType()
{
	return *chrType;
};

void Candidate::setType(char chrNewType)
{
	*chrType = chrNewType;
};

void Candidate::setSalary(long lngNewSalary)
{
	*lngSalary = lngNewSalary;
};

void Candidate::show()
{
	cout << getString() << endl;
};

char Candidate::getStatus()
{
	return chrStat(*intStatus);
};

bool Candidate::doesFit()
{
	return *blFits;
};

void Candidate::setStatus(char chrNewStatus)
{
	*intStatus = intStat(chrNewStatus);
	if (getStatus() == 'p')
	{
		changeFits(true);
	}
};

void Candidate::changeFits(bool blValue)
{
	*blFits = blValue;
};

int Candidate::intStat(char chrConvStat)
{
	int intRetVal;
	switch (chrConvStat)
	{
		case 'c': // candidate
			intRetVal = 0;
			break;
		case 'r': // resume
			intRetVal = 1;
			break;
		case 'i': // interview
			intRetVal = 2;
			break;
		case 'p': // passed
			intRetVal = 3;
			break;
		default:  // something's wrong
			intRetVal = -1;
			break;
	}
	return intRetVal;
};

void Candidate::activate()
{
	changeFits(true);
	setActive(true);
};

void Candidate::terminate()
{
	changeFits(false);
	setActive(false);
};

bool Candidate::isInitialized()
{
	return getSerial() != -1 && getName() != to_string(NULL)
		&& getType() != '\0'
		&& getStatus() != '\0';
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


Candidate::Candidate(const People & pplGet)
{
	chrType = new char;
	blFits = new bool;
	setSerial(const_cast<People&>(pplGet).getNewSerial());
	setSalary(-1);
	setType('\0');
	changeFits(NULL);
	setStatus('\0');
};

Candidate::Candidate(const People & pplGet, std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat)
{
	intStatus = new int;
	blFits = new bool;
	setSerial(const_cast<People&>(pplGet).getNewSerial());
	setName(strNewName);
	setType(chrNewType);
	setActive(blIsActive);
	changeFits(blDoesFit);
	setStatus(chrNewStat);
};

Candidate::Candidate(const People & pplGet, const Candidate & cndB)
{
	intStatus = new int;
	blFits = new bool;
	*this = const_cast<Candidate&>(cndB);
	setSerial(const_cast<People&>(pplGet).getNewSerial());
};

Candidate::~Candidate()
{
	int intIndex = getIndex(getSerial());
	if (intIndex != -1)
	{
		remPerson(intIndex);
	}
	setSerial(-1);
	setName(to_string(NULL));
	setActive(NULL);
	setType('\0');
	setSalary(-1);
	delete intStatus;
	delete blFits;
};


ostream & operator << (ostream & ostMyStream, const Candidate & cndB)
{
	ostMyStream << const_cast<Candidate&>(cndB).getString();
	return ostMyStream;
};

bool employ(People & pplGet, Candidate & cndFitsAs, Employee & empNewEmployee)
{
	bool blRetVal = false;
	if (cndFitsAs.doesFit() && cndFitsAs.isActive() && cndFitsAs.getStatus() == 'p' && cndFitsAs.getSalary() != 0)
	{
		pplGet.addPrs('E', pplGet.getSize() + 1,
			cndFitsAs.getName(), cndFitsAs.getType(), cndFitsAs.isActive(),
			cndFitsAs.getSalary());
		cndFitsAs.setSerial(cndFitsAs.getSerial());
		remPerson(getIndex(cndFitsAs.getSerial()), true);
		blRetVal = true;
	}
	return blRetVal;
};

bool operator== (const Candidate & cndA, const Candidate & cndB)
{
	return const_cast<Candidate&>(cndA).getSerial() == const_cast<Candidate&>(cndB).getSerial()
		&& const_cast<Candidate&>(cndA).isActive() == const_cast<Candidate&>(cndB).isActive()
		&& const_cast<Candidate&>(cndA).getName() == const_cast<Candidate&>(cndB).getName()
		&& const_cast<Candidate&>(cndA).getType() == const_cast<Candidate&>(cndB).getType()
		&& const_cast<Candidate&>(cndA).getSalary() == const_cast<Candidate&>(cndB).getSalary()
		&& const_cast<Candidate&>(cndA).doesFit() == const_cast<Candidate&>(cndB).doesFit()
		&& const_cast<Candidate&>(cndA).getStatus() == const_cast<Candidate&>(cndB).getStatus();
};

bool operator== (const Candidate & cndB, const Person & prsB)
{
	return const_cast<Candidate&>(cndB).getSerial() == const_cast<Person&>(prsB).getSerial()
		&& const_cast<Candidate&>(cndB).isActive() == const_cast<Person&>(prsB).isActive()
		&& const_cast<Candidate&>(cndB).getName() == const_cast<Person&>(prsB).getName();
};

bool operator== (const Person & prsB, const Candidate & cndB)
{
	return const_cast<Candidate&>(cndB) == prsB;
};

bool operator== (const Candidate & cndB, const Employee & empB)
{
	return const_cast<Candidate&>(cndB).getSerial() == const_cast<Employee&>(empB).getSerial() &&
		const_cast<Candidate&>(cndB).isActive() == const_cast<Employee&>(empB).isActive() &&
		const_cast<Candidate&>(cndB).getName() == const_cast<Employee&>(empB).getName() &&
		const_cast<Candidate&>(cndB).getType() == const_cast<Employee&>(empB).getType() &&
		const_cast<Candidate&>(cndB).getSalary() == const_cast<Employee&>(empB).getSalary();
};

bool operator== (const Employee & empB, const Candidate & cndB)
{
	return const_cast<Candidate&>(cndB) == const_cast<Employee&>(empB);
};
