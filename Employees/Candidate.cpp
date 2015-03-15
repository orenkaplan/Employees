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
	cout << /* *this */ getString() << endl;
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
	return getSerial() != -1 && getName() != to_string(NULL) /* && isActive() != NULL */
		&& getType() != '\0' /* && getSalary() != -1 */
		&& getStatus() != '\0' /* && doesFit() != NULL */;
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


Candidate::Candidate(People & pplGet)
{
	chrType = new char;
	blFits = new bool;
	setSerial(pplGet.getNewSerial());
	setSalary(-1);
	setType('\0');
	changeFits(NULL);
	setStatus('\0');
};

Candidate::Candidate(People & pplGet, std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat)
{
	intStatus = new int;
	blFits = new bool;
	setSerial(pplGet.getNewSerial());
	setName(strNewName);
	setType(chrNewType);
	setActive(blIsActive);
	changeFits(blDoesFit);
	setStatus(chrNewStat);
};

Candidate::Candidate(People & pplGet, Candidate & cndB)
{
	intStatus = new int;
	blFits = new bool;
	*this = cndB;
	setSerial(pplGet.getNewSerial());
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


ostream & operator << (ostream & ostMyStream, Candidate & cndB)
{
	ostMyStream << cndB.getString();
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
