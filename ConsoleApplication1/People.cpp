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
			Employee & empTemp = dynamic_cast<Employee&>(*prsList[i]);
			Candidate & cndTemp = dynamic_cast<Candidate&>(*prsList[i]);
			if (&cndTemp == nullptr)
			{
				empTemp.show;
			}
			else
			{
				cndTemp.show;
			}
		}
		else
		{
			cout << "No peron recorded." << endl;
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
			set(i);
			break;
		}
	}
	intLastTouched = -1;
};

bool People::isEmpty()
{
	return getSize == 0 || getCount == 0;
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
		lngSerialList[i] = *prsList[i]->getSerial;
		blEmpty[i] = *prsList[i]->isInitialized;
	}
	set(intSize);
	intCount++;
};

void addPerson(Employee & empB)
{
	People pplTemp;
	pplTemp.prsTempList = new Person*[pplTemp.getSize + 1];
	pplTemp.prsTempList[pplTemp.getSize + 1] = new Employee;
	*pplTemp.prsTempList[pplTemp.getSize + 1] = empB;
	pplTemp.addPrs(pplTemp.prsTempList);
	delete[] pplTemp.prsTempList;
};

void addPerson(Candidate & cndB)
{
	People pplTemp;
	pplTemp.prsTempList = new Person*[pplTemp.getSize + 1];
	pplTemp.prsTempList[pplTemp.getSize + 1] = new Candidate;
	*pplTemp.prsTempList[pplTemp.getSize + 1] = cndB;
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

void remPerson(Employee & empB)
{
	People pplTemp;
	Employee * empTemp = &empB;
	Person * prsTempEmployee = dynamic_cast<Person*>(empTemp);
	for (int i = 0; i < pplTemp.getSize; i++)
	{
		if (pplTemp.prsList[i] == prsTempEmployee)
		{
			pplTemp.remPerson(i);
			break;
		}
	}
};

void remPerson(Candidate & cndB)
{
	People pplTemp;
	Candidate * cndTemp = &cndB;
	Person * prsTempCandidate = dynamic_cast<Person*>(cndTemp);
	for (int i = 0; i < pplTemp.getSize; i++)
	{
		if (pplTemp.prsList[i] == prsTempCandidate)
		{
			pplTemp.remPerson(i);
			break;
		}
	}
	delete cndTemp;
	delete prsTempCandidate;
};

void People::remPerson(long lngExistingSerial)
{
	for (int i = 0; i < intSize; i++)
	{
		if (*prsList[i]->getSerial == lngExistingSerial)
		{
			remPerson(i);
			break;
		}
	}
};

ostream & operator << (ostream & ostMyStream, const People & pplB)
{
	if (!pplB.isEmpty)
	{
		ostMyStream << "The HR database lists " << pplB.getCount << " people in a database of size " << pplB.getSize << "." << endl
			<< "The last slot in the database to be manipulated is " << pplB.getLastTouchedIndex << ".";
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

bool operator== (Candidate & cndB, Employee & empB)
{
	Employee * empTemp = &empB;
	Candidate * cndTemp = &cndB;
	Person * prsTempEmployee = dynamic_cast<Person*>(empTemp);
	Person * prsTempCandidate = dynamic_cast<Person*>(cndTemp);
	Employee * empTempCandidate = dynamic_cast<Employee*>(cndTemp);
	bool blRetVal = prsTempCandidate->getSerial == prsTempEmployee->getSerial &&
		prsTempCandidate->isActive == prsTempEmployee->isActive &&
		prsTempCandidate->getName == prsTempEmployee->getName &&
		empTempCandidate->getType == empB.getType &&
		empTempCandidate->getSalary == empB.getSalary;
	delete empTemp;
	delete cndTemp;
	delete prsTempEmployee;
	delete prsTempCandidate;
	delete empTempCandidate;
	return blRetVal;
};

bool operator== (Employee & empB, Candidate & cndB)
{
	Employee * empTemp = &empB;
	Candidate * cndTemp = &cndB;
	Person * prsTempEmployee = dynamic_cast<Person*>(empTemp);
	Person * prsTempCandidate = dynamic_cast<Person*>(cndTemp);
	Employee * empTempCandidate = dynamic_cast<Employee*>(cndTemp);
	bool blRetVal = 
		prsTempEmployee->getSerial == prsTempCandidate->getSerial && 
		prsTempEmployee->isActive == prsTempCandidate->isActive && 
		prsTempEmployee->getName == prsTempCandidate->getName &&
		empB.getType == empTempCandidate->getType &&
		empB.getSalary == empTempCandidate->getSalary;
	delete empTemp;
	delete cndTemp;
	delete prsTempEmployee;
	delete prsTempCandidate;
	delete empTempCandidate;
	return blRetVal;
};


People::People()
{
	prsList = new Person*[];
	lngSerialList = new long[];
	blEmpty = new bool[];
	set((int)-1);
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
