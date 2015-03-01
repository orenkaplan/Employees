#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Candidate.h"
#include "People.h"


using namespace std;


void Candidate::show()
{
	Candidate & cndTemp = *this;
	switch (cndTemp.getType)
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
			cout << "Bad candidate type." << endl << "Please start over and report to author." << endl;
			return;
	}
	cout << "candidate " << getName << ", number " << getSerial;
	if (*blFits)
	{
		cout << " fits ";
	}
	else
	{
		cout << " doesn't fit ";
	}
	cout << " the position and is";
	if (!isActive)
	{
		cout << "n't";
	}
	cout << " active in status " << chrStat(*intStatus) << "." << endl;
}

void Candidate::setStatus(char chrNewStatus)
{
	*intStatus = intStat(chrNewStatus);
}

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
}

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
}

bool Candidate::isInitialized()
{
	Candidate & cndThis = *this;
	return getSerial != NULL && getName != NULL && isActive != NULL
		&& getType != NULL && getSalary != NULL
		&& cndThis.getStatus > -1 && doesFit != NULL;
}

void Candidate::terminate()
{
	changeFits(false);
	set(false);
}

void Candidate::activate()
{
	changeFits(true);
	set(true);
}

long Candidate::operator<< (Candidate & cndB)
{
	long lngRetVal;
	Candidate & cndTemp = *this;
	lngRetVal = cndTemp.getSerial;
	lngRetVal << *cndB.getSerial;
	return lngRetVal;
}

long Candidate::operator>> (Candidate & cndB)
{
	long lngRetVal;
	Candidate & cndTemp = *this;
	lngRetVal = cndTemp.getSerial;
	lngRetVal >> *cndB.getSerial;
	return lngRetVal;
}

void Candidate::operator= (Candidate & cndB)
{
	set(*cndB.getSerial);
	set(*cndB.isActive);
	set(*cndB.getName);
	set(*cndB.getType);
	setSalary(*cndB.getSalary);
	changeFits(*cndB.doesFit);
	setStatus(*cndB.getStatus);
}

bool Candidate::operator== (Candidate & cndB)
{
	return getSerial == *cndB.getSerial && isActive == *cndB.isActive && getName == *cndB.getName
		&& getType == *cndB.getType && getSalary == *cndB.getSalary
		&& doesFit == *cndB.doesFit && getStatus == *cndB.getStatus;
}

bool Candidate::operator== (Employee & empB)
{
	return getSerial == *empB.getSerial && isActive == *empB.isActive && getName == *empB.getName
		&& getType == *empB.getType && getSalary == *empB.getSalary;
}


Candidate::Candidate()
{
	People pplGet;
	set(pplGet.getNewSerial);
	setName("");
	set('t');
	set(false);
	changeFits(false);
	setStatus('d');
	pplGet.addPerson(*this);
}

Candidate::Candidate(string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat)
{
	People pplGet;
	set(pplGet.getNewSerial);
	setName(strNewName);
	set(chrNewType);
	set(blIsActive);
	changeFits(blDoesFit);
	setStatus(chrNewStat);
	pplGet.addPerson(*this);
}

Candidate::Candidate(Candidate & cndB)
{
	People pplGet;
	set(pplGet.getNewSerial);
	pplGet.addPerson(*this);
}

Candidate::~Candidate()
{
	People pplDel;
	set((long)-1);
	setName("");
	set(false);
	set('\0');
	setSalary(-1);
	delete intStatus;
	delete blFits;
	pplDel.remPerson(*this);
}