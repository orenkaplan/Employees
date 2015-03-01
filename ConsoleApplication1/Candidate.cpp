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
	switch (getType)
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

void Candidate::set(char chrNewStatus)
{
	*intStatus = intStat(chrNewStatus);
}

int Candidate::intStat(char chrConvStat)
{

}

char Candidate::chrStat(int intConvStat)
{

}

void Candidate::terminate()
{
	*blFits = false;
	*blActive = *blFits;
}

void Candidate::activate()
{
	*blActive = true;
	*blFits = *blActive;
}

long Candidate::operator<< (Candidate & cndB)
{
	long lngRetVal;
	lngRetVal = *lngSerial;
	lngRetVal << *cndB.lngSerial;
	return lngRetVal;
}

long Candidate::operator>> (Candidate & cndB)
{
	long lngRetVal;
	lngRetVal = *lngSerial;
	lngRetVal >> *cndB.lngSerial;
	return lngRetVal;
}

void Candidate::operator= (Candidate & cndB)
{
	*blActive = *cndB.blActive;
	*strName = *cndB.strName;
	*chrType = *cndB.chrType;
	*lngSalary = *cndB.lngSalary;
	*blFits = *cndB.blFits;
	*intStatus = *cndB.intStatus;
}

bool Candidate::operator== (Candidate & cndB)
{
	return *blActive == *cndB.blActive && *strName == *cndB.strName
		&& *chrType == *cndB.chrType && *lngSalary == *cndB.lngSalary
		&& *blFits == *cndB.blFits && *intStatus == *cndB.intStatus;
}


Candidate::Candidate()
{

}

Candidate::Candidate(string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, int intNewStat)
{

}

Candidate::Candidate(Candidate & cndB)
{
	People pplGet;
	lngSerial = pplGet.getNewSerial;
	*this = cndB;
	
}

Candidate::~Candidate()
{

}
