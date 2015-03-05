#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "People.h"


using namespace std;


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

void People::set(int intNewIndex)
{
	intLastTouched = intNewIndex;
};

void People::setLastTouched(long lngTouchedSerial)
{
	for (int i = 0; i < intSize; i++)
	{
		if (lngTouchedSerial == lngSerialList[i])
		{
			this->set(i);
			break;
		}
	}
	intLastTouched = -1;
};

bool People::isEmpty()
{
	return this->getSize() == 0 || this->getCount() == 0;
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

void People::addPrs(Person **& prsTempList)
{
	for (int i = 0; i < intSize; i++)
	{
		prsTempList[i] = prsList[i];
	}
	intSize++;
	prsList = new Person*[intSize];
	lngSerialList = new long[intSize];
	blEmpty = new bool[intSize];
	for (int i = 0; i < intSize; i++)
	{
		prsList[i] = prsTempList[i];
		lngSerialList[i] = prsList[i]->getSerial();
		blEmpty[i] = prsList[i]->isInitialized();
	}
	this->set(intSize);
	intCount++;
};

void addEmployee(Employee & empB)
{
	People pplTemp;
	int intMySize = pplTemp.getSize() + 1;
	pplTemp.prsTempList = new Person*[intMySize];
//	pplTemp.prsTempList[intMySize] = new Employee;
//	empB => *pplTemp.prsTempList[intMySize];
	pplTemp.addPrs(pplTemp.prsTempList);
	delete[] pplTemp.prsTempList;
};

void addCandidate(Candidate & cndB)
{
	People pplTemp;
	int intMySize = pplTemp.getSize() + 1;
	pplTemp.prsTempList = new Person*[intMySize];
//	pplTemp.prsTempList[intMySize] = new Candidate;
//	cndB => *pplTemp.prsTempList[intMySize];
	pplTemp.addPrs(pplTemp.prsTempList);
	delete[] pplTemp.prsTempList;
};

void People::remPerson(int intIndex)
{
	lngSerialList[intIndex] = -1;
	blEmpty[intIndex] = true;
	set(intIndex);
	intCount--;
	delete prsList[intIndex];
};

void remEmployee(Employee & empB)
{
	People pplTemp;
	for (int i = 0; i < pplTemp.getSize(); i++)
	{
		Person & prsTemp = *pplTemp.prsList[i];
		if (true /* prsTemp == empB */)
		{
			pplTemp.remPerson(i);
			break;
		}
	}
};

void remCandidate(Candidate & cndB)
{
	People pplTemp;
	for (int i = 0; i < pplTemp.getSize(); i++)
	{
		Person & prsTemp = *pplTemp.prsList[i];
		if (true /* prsTemp == cndB */)
		{
			pplTemp.remPerson(i);
			break;
		}
	}
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
	this->set((int)-1);
	intCount = -1;
	intLastTouched = -1;
};

People::People(People & pplB)
{
	*this = pplB;
};

People::~People()
{
	for (int i = 0; i < intSize; i++)
	{
		delete prsList[i];
	}
	intSize = 0;
	delete[] prsList;
	delete[] lngSerialList;
	delete[] blEmpty;
};
