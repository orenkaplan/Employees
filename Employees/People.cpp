#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <typeinfo>

#include "People.h"
#include "Employee.h"
#include "Candidate.h"


using namespace std;


// Initialize static variables
Person * People::prsList[10] = {};
long * People::lngSerialList[10] = {};
bool * People::blEmpty[10] = {};
int People::intSize = 0;
int People::intCount = 0;
int People::intLastTouched = 0;

void remPerson(int intIndex, bool blDelete)
{
	*People::lngSerialList[intIndex] = -1;
	*People::blEmpty[intIndex] = true;
	People::intLastTouched = intIndex;
	People::intCount--;
	if (blDelete) // don't loop destructors
	{
		delete People::prsList[intIndex];
	}
};

void People::addPrs(char chrCreateType, int intMySize,
	std::string strName, char chrType, bool blActive,
	long lngSalary,
	char chrStatus, bool blFits)
{
	switch (chrCreateType)
	{
		case 'e':
			prsList[intMySize] = new Employee(*this);
			break;
		case 'E':
			prsList[intMySize] = new Employee(*this, strName, lngSalary, chrType, blActive);
			break;
		case 'c':
			prsList[intMySize] = new Candidate(*this);
			break;
		case 'C':
			prsList[intMySize] = new Candidate(*this, strName, chrType, blActive, blFits, chrStatus);
			break;
		default:
			break;
	}
	*lngSerialList[intMySize] = prsList[intMySize]->getSerial();
	*blEmpty[intMySize] = !prsList[intMySize]->isInitialized();
	if (getSize() == -1 && intCount == -1)
	{
		intSize = 1;
		intCount = 1;
	}
	else
	{
		intSize++;
		intCount++;
	}
};

void People::setLastTouched(int intNewIndex)
{
	intLastTouched = intNewIndex;
};

void People::show(char chrType)
{
	bool blShow = false;
	string strType = "";
	switch (chrType)
	{
		case 'e':
			strType = "employee";
			break;
		case 'c':
			strType = "candidate";
			break;
		case '\0':
			strType = "person";
			break;
		default:
			cout << "Type Error.\nStart over and report to author.\n\n";
			return;
			break;
	}
	for (int i = 0; i < getSize(); i++)
	{
		if (!*blEmpty[i])
		{
			switch (chrType)
			{
				case 'e':
					blShow = prsList[i]->getStatus() == '\0';
					break;
				case 'c':
					blShow = prsList[i]->getStatus() != '\0';
					break;
				case '\0':
					blShow = true;
					break;
				default:
					cout << "Type Error.\nStart over and report to author.\n\n";
					break;
			}
			if (blShow)
			{
				prsList[i]->show();
			}
		}
		else
		{
			cout << "No " + strType + " recorded.\n";
		}
	}
};

void People::show(long lngExistingSerial)
{
	int intIndex = getIndex(lngExistingSerial);
	if (intIndex != -1)
	{
		prsList[intIndex]->show();
	}
	else
	{
		cout << "No person recorded by that Serial Number.\nTry again.\n\n";
	}
};

void People::setLastTouched(long lngTouchedSerial)
{
	int intIndex = getIndex(lngTouchedSerial);
	if (intIndex != -1)
	{
		setLastTouched(intIndex);
	}
	else
	{
		cout << "No person recorded by that Serial Number.\nTry again.\n\n";
	}
};

void People::setLastInstance()
{
	blLastInstance = true;
};

int People::getSize()
{
	return intSize;
};

int People::getCount()
{
	return intCount;
};

int People::getLastTouchedIndex()
{
	return intLastTouched;
};

bool People::isEmpty()
{
	return getSize() == 0 || getCount() == 0;
};

long People::getNewSerial()
{
	long lngNewSerial = 1;
	int intListSize = 0;
	if (getSize() > -1)
	{
		intListSize = getSize();
	}
	for (int i = 0; i < intListSize; i++)
	{
		if (lngNewSerial <= *lngSerialList[i])
		{
			lngNewSerial = *lngSerialList[i] + 1;
		}
	}
	return lngNewSerial;
};

std::string People::getCName(int intIndex)
{
	return prsList[intIndex]->getName();
};

bool People::getCActive(int intIndex)
{
	return prsList[intIndex]->isActive();
};

char People::getCType(int intIndex)
{
	return prsList[intIndex]->getType();
};

long People::getSerialSalary(int intIndex, bool blGetSerial)
{
	if (blGetSerial)
	{
		return prsList[intIndex]->getSerial();
	}
	else
	{
		return prsList[intIndex]->getSalary();
	}
};

char People::getCStatus(int intIndex)
{
	return prsList[intIndex]->getStatus();
};

bool People::getCFit(int intIndex)
{
	return prsList[intIndex]->doesFit();
};

void People::setCName(int intIndex, std::string strNewName)
{
	prsList[intIndex]->setName(strNewName);
};

void People::setCActive(int intIndex, bool blNewActive)
{
	prsList[intIndex]->setActive(blNewActive);
};

void People::setCType(int intIndex, char chrNewType)
{
	prsList[intIndex]->setType(chrNewType);
};

void People::setCSerial(int intIndex, long lngNewSerial)
{
	prsList[intIndex]->setSerial(lngNewSerial);
};

void People::setCSalary(int intIndex, long lngNewSalary)
{
	prsList[intIndex]->setSalary(lngNewSalary);
};

void People::setCStatus(int intIndex, char chrNewStatus)
{
	prsList[intIndex]->setStatus(chrNewStatus);
};

void People::setCFit(int intIndex, bool blNewFit)
{
	prsList[intIndex]->changeFits(blNewFit);
};

void People::operator= (People & pplB)
{

};

bool People::operator== (const People & pplB)
{
	return true;
};


People::People()
{
	for (int i = 0; i < 10; i++)
	{
		prsList[i] = nullptr;
		lngSerialList[i] = new long;
		blEmpty[i] = new bool;
	}
	if (intSize != -1 && intCount != -1 && intLastTouched != -1)
	{
		setLastTouched(-1);
		intCount = -1;
		intSize = -1;
	}
};

People::People(const People & pplB)
{
	*this = const_cast<People&>(pplB);
};

People::~People()
{
	if (blLastInstance) // only try deleting when last existing instance
	{
		if (getSize() > 0)
		{
			for (int i = 0; i < getSize(); i++)
			{
				if (!*blEmpty[i])
				{
					remPerson(i);
				}
				delete lngSerialList[i];
				delete blEmpty[i];
			}
		}
		intSize = 0;
	}
};


int getIndex(long lngSerialToGet)
{
	int intRetVal = -1;
	for (int i = 0; i < People::intSize; i++)
	{
		if (*People::lngSerialList[i] == lngSerialToGet)
		{
			intRetVal = i;
			break;
		}
	}
	return intRetVal;
};

ostream & operator << (ostream & ostMyStream, const People & pplB)
{
	if (!const_cast<People&>(pplB).isEmpty())
	{
		ostMyStream << "The HR database lists " << const_cast<People&>(pplB).getCount() << " people in a database of size "
			<< const_cast<People&>(pplB).getSize() << "." << endl << "The last slot in the database to be manipulated is "
			<< const_cast<People&>(pplB).getLastTouchedIndex() << ".";
	}
	else
	{
		ostMyStream << "The HR database is empty." << endl;
	}
	return ostMyStream;
};