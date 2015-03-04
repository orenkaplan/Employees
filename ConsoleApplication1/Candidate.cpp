#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#if !defined(Candidate_h)
#include "Candidate.h"
#endif
#if !defined(People_h)
#include "People.h"
#endif


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
	strRetVal = strRetVal + "candidate " + *this->getName + ", number " + getSerial;
	if (doesFit)
	{
		strRetVal = strRetVal + " fits ";
	}
	else
	{
		strRetVal = strRetVal + " doesn't fit ";
	}
	strRetVal = strRetVal + " the position and is";
	if (!isActive)
	{
		strRetVal = strRetVal + "n't";
	}
	strRetVal = strRetVal + " active in status " + *this->getStatus + ".";
	return strRetVal;
};

void Candidate::show()
{
	cout << *this << endl;
};

void Candidate::setStatus(char chrNewStatus)
{
	*intStatus = intStat(chrNewStatus);
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
	return getSerial != NULL && getName != NULL && isActive != NULL
		&& getType != NULL && getSalary != NULL
		&& getStatus != NULL && doesFit != NULL;
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
	ostMyStream << cndB.getString;
	return ostMyStream;
};

void Candidate::operator= (Candidate & cndB)
{
	setSerial(cndB.getSerial);
	setActive(cndB.isActive);
	setName(cndB.getName);
	setType(cndB.getType);
	setSalary(cndB.getSalary);
	changeFits(cndB.doesFit);
	setStatus(cndB.getStatus);
};

bool Candidate::operator== (Candidate & cndB)
{
	return getSerial == cndB.getSerial && isActive == cndB.isActive && getName == cndB.getName
		&& getType == cndB.getType && getSalary == cndB.getSalary
		&& doesFit == cndB.doesFit && getStatus == cndB.getStatus;
};

bool operator== (Candidate & cndB, Person & prsB)
{
	return cndB.getSerial == prsB.getSerial && cndB.isActive == prsB.isActive && cndB.getName == prsB.getName;
};

bool operator== (Person & prsB, Candidate & cndB)
{
	return prsB.getSerial == cndB.getSerial && prsB.isActive == cndB.isActive && prsB.getName == cndB.getName;
};


Candidate::Candidate()
{
	People pplGet;
	setSerial(pplGet.getNewSerial);
	setSalary(NULL);
	setType(NULL);
	changeFits(NULL);
	setStatus(NULL);
	addPerson(*this);
};

Candidate::~Candidate()
{
	remPerson(*this->getSerial);
	setSerial(NULL);
	setName(NULL);
	setActive(NULL);
	setType(NULL);
	setSalary(NULL);
	delete intStatus;
	delete blFits;
};