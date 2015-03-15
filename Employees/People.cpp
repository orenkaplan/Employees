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

// Initialize global and static variables
// Person *People::prsList = NULL;
// Person *People::prsTempList = NULL;
Person * prsList[10];
Person * prsTempList[10];
long *People::lngSerialList[10] = {};
bool *People::blEmpty[10] = {};
int People::intSize = 0;
int People::intCount = 0;
int People::intLastTouched = 0;

void remPerson(int intIndex, bool blDelete)
{
	*People::lngSerialList[intIndex] = -1;
	*People::blEmpty[intIndex] = true;
	People::intLastTouched = intIndex;
	People::intCount--;
	if (blDelete)
	{
		delete prsList[intIndex];
	}
};

void People::addPrs(char chrCreateType, int intMySize,
	std::string strName, char chrType, bool blActive,
	long lngSalary,
	char chrStatus, bool blFits)
{
/* 	if (getSize() > 0)
	{
		for (int i = 0; i < getSize(); i++)
		{
			*prsTempList[i] = *prsList[i];
		}
	}
	prsList = new Person*[getSize()];
	lngSerialList = new long[getSize()];
	blEmpty = new bool[getSize()];
	for (int i = 0; i < getSize(); i++)
	{
		if (dynamic_cast<Employee *>(prsTempList[i]))
		{
			prsList[i] = new Employee;
		}
		else if (dynamic_cast<Candidate *>(prsTempList[i]))
		{
			prsList[i] = new Candidate;
		}
		*prsList[i] = *prsTempList[i];
		lngSerialList[i] = prsList[i]->getSerial();
		blEmpty[i] = prsList[i]->isInitialized();
	}
	setLastTouched(getSize()); */
	//			mnuMyUI->pplList->prsTempList = new Person*[intMySize + 1];
	switch (chrCreateType)
	{
	case 'e':
		prsList[intMySize] = new Employee(*this);
		break;
	case 'E':
//		mnuMyUI->getData(true);
		prsList[intMySize] = new Employee(*this, strName, lngSalary, chrType, blActive);
		break;
	case 'c':
		prsList[intMySize] = new Candidate(*this);
		break;
	case 'C':
//		mnuMyUI->getData(true, true);
		prsList[intMySize] = new Candidate(*this, strName, chrType, blActive, blFits, chrStatus);
		break;
	default:
		break;
	}
/*	if (intMySize > 0)
	{
		for (int i = 0; i < intMySize; i++)
		{
			if (dynamic_cast<Employee *>(mnuMyUI->pplList->prsList[i]))
			{
				mnuMyUI->pplList->prsTempList[i] = new Employee;
			}
			else if (dynamic_cast<Candidate *>(mnuMyUI->pplList->prsList[i]))
			{
				mnuMyUI->pplList->prsTempList[i] = new Candidate;
			}
			*mnuMyUI->pplList->prsTempList[i] = *mnuMyUI->pplList->prsList[i];
		}
	}
	intMySize++;
	mnuMyUI->pplList->prsList = new Person*[intMySize];
	mnuMyUI->pplList->lngSerialList = new long[intMySize];
	mnuMyUI->pplList->blEmpty = new bool[intMySize];
	for (int i = 0; i < intMySize; i++)
	{
		if (dynamic_cast<Employee *>(mnuMyUI->pplList->prsTempList[i]))
		{
			mnuMyUI->pplList->prsList[i] = new Employee;
		}
		else if (dynamic_cast<Candidate *>(mnuMyUI->pplList->prsTempList[i]))
		{
			mnuMyUI->pplList->prsList[i] = new Candidate;
		}
		*mnuMyUI->pplList->prsList[i] = *mnuMyUI->pplList->prsTempList[i];
	}
	mnuMyUI->pplList->setLastTouched(intMySize - 1); */
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
		if (!*blEmpty[i])
		{
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
	prsList[getIndex(lngExistingSerial)]->show();
};

void People::setLastTouched(long lngTouchedSerial)
{
	setLastTouched(getIndex(lngTouchedSerial));
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
//	**prsTempList = **pplB.prsTempList;
};

bool People::operator== (People & pplB)
{
//	return **prsTempList == **pplB.prsTempList;
	return true;
};


People::People()
{
//	prsList = new Person*[]; null initiallization
//	lngSerialList = new long[]; null initiallization
//	blEmpty = new bool[]; null initiallization
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

People::People(People & pplB)
{
	*this = pplB;
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
//		delete[] prsList;
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