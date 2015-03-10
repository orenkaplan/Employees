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
Person **People::prsList = NULL;
Person **People::prsTempList = NULL;
long *People::lngSerialList = NULL;
bool *People::blEmpty = NULL;
int People::intSize = 0;
int People::intCount = 0;
int People::intLastTouched = 0;

void People::remPerson(int intIndex)
{
	lngSerialList[intIndex] = -1;
	blEmpty[intIndex] = true;
	setLastTouched(intIndex);
	intCount--;
	delete prsList[intIndex];
};

void People::addPrs()
{
	if (getSize() > 0)
	{
		for (int i = 0; i < getSize(); i++)
		{
			*prsTempList[i] = *prsList[i];
		}
	}
	intSize++;
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
	setLastTouched(getSize());
	intCount++;
};

void People::setLastTouched(int intNewIndex)
{
	intLastTouched = intNewIndex;
};

void People::show()
{
	for (int i = 0; i < intSize; i++)
	{
		if (!blEmpty[i])
		{
			prsList[i]->show();
		}
		else
		{
			cout << "No person recorded." << endl;
		}
	}
};

void People::show(char chrType)
{
	string strType = "";
	for (int i = 0; i < intSize; i++)
	{
		strType = typeid(prsList[i]).name();
		transform(strType.begin(), strType.end(), strType.begin(), ::tolower);
		if (!blEmpty[i])
		{
			if (chrType == strType.front())
			{
				prsList[i]->show();
			}
		}
		else
		{
			cout << "No " + strType + " recorded." << endl;
		}
	}
};

bool People::show(long lngExistingSerial)
{
	prsList[getIndex(lngExistingSerial)]->show();
	return true;
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
	long lngNewSerial = 0;
	for (int i = 0; i < intSize; i++)
	{
		if (lngNewSerial <= lngSerialList[i])
		{
			lngNewSerial = lngSerialList[i] + 1;
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

void People::remPerson(long lngExistingSerial)
{
	for (int i = 0; i < intSize; i++)
	{
		if (prsList[i]->getSerial() == lngExistingSerial)
		{
			remPerson(i);
			break;
		}
	}
};

void People::operator= (People & pplB)
{
	**prsTempList = **pplB.prsTempList;
};

bool People::operator== (People & pplB)
{
	return **prsTempList == **pplB.prsTempList;
};


People::People()
{
	prsList = new Person*[];
	lngSerialList = new long[];
	blEmpty = new bool[];
	setLastTouched(-1);
	intCount = -1;
	intLastTouched = -1;
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
				delete prsList[i];
			}
		}
		intSize = 0;
		delete[] prsList;
		delete[] lngSerialList;
		delete[] blEmpty;
	}
};


int People::getIndex(long lngSerialToGet)
{
	int intRetVal = -1;
	for (int i = 0; i < getSize(); i++)
	{
		if (lngSerialList[i] == lngSerialToGet)
		{
			intRetVal = i;
			break;
		}
	}
	return intRetVal;
};

void remEmployee(Employee & empB)
{
	People pplTemp;
	pplTemp.remPerson(pplTemp.getIndex(empB.getSerial()));
};

void remCandidate(Candidate & cndB)
{
	People pplTemp;
	pplTemp.remPerson(pplTemp.getIndex(cndB.getSerial()));
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