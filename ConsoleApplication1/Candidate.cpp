#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Candidate.h"
#include "People.h"


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
	strRetVal = strRetVal + "candidate " + this->getName() + ", number " + to_string(this->getSerial());
	if (this->doesFit())
	{
		strRetVal = strRetVal + " fits ";
	}
	else
	{
		strRetVal = strRetVal + " doesn't fit ";
	}
	strRetVal = strRetVal + " the position and is";
	if (!this->isActive())
	{
		strRetVal = strRetVal + "n't";
	}
	strRetVal = strRetVal + " active in status " + this->getStatus() + ".";
	return strRetVal;
};

void Candidate::show()
{
	cout << *this << endl;
};

void Candidate::setStatus(char chrNewStatus)
{
	*intStatus = this->intStat(chrNewStatus);
};

char Candidate::getStatus()
{
	return this->chrStat(*intStatus);
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
	return this->getSerial() != NULL && this->getName() != to_string(NULL) && this->isActive() != NULL
		&& this->getType() != NULL && this->getSalary() != NULL
		&& this->getStatus() != NULL && this->doesFit() != NULL;
};

void Candidate::terminate()
{
	this->changeFits(false);
	this->setActive(false);
};

void Candidate::activate()
{
	this->changeFits(true);
	this->setActive(true);
};

ostream & operator << (ostream & ostMyStream, const Candidate & cndB)
{
	ostMyStream << const_cast<Candidate&>(cndB).getString();
	return ostMyStream;
};

void Candidate::operator= (Candidate & cndB)
{
	this->setSerial(cndB.getSerial());
	this->setActive(cndB.isActive());
	this->setName(cndB.getName());
	this->setType(cndB.getType());
	this->setSalary(cndB.getSalary());
	this->changeFits(cndB.doesFit());
	this->setStatus(cndB.getStatus());
};

/* void operator<= (Person & prsB, Candidate & cndB)
{
	prsB.setSerial(cndB.getSerial());
	prsB.setActive(cndB.isActive());
	prsB.setName(cndB.getName());
}; */

bool Candidate::operator== (Candidate & cndB)
{
	return this->getSerial() == cndB.getSerial() && this->isActive() == cndB.isActive() && this->getName() == cndB.getName()
		&& this->getType() == cndB.getType() && this->getSalary() == cndB.getSalary()
		&& this->doesFit() == cndB.doesFit() && this->getStatus() == cndB.getStatus();
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
	this->setSerial(pplGet.getNewSerial());
	this->setSalary(NULL);
	this->setType(NULL);
	this->changeFits(NULL);
	this->setStatus(NULL);
	addPerson(*this);
};

Candidate::~Candidate()
{
	remPerson(*this);
	this->setSerial(NULL);
	this->setName(NULL);
	this->setActive(NULL);
	this->setType(NULL);
	this->setSalary(NULL);
	delete intStatus;
	delete blFits;
};