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
			Employee & empTemp = dynamic_cast<Employee&>(*empList[i]);
			Candidate & cndTemp = dynamic_cast<Candidate&>(*empList[i]);
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
}

int People::getSize()
{
	return intSize;
}

int People::getLastTouchedIndex()
{
	return intLastTouched;
}

void People::set(int intNewIndex)
{
	intLastTouched = intNewIndex;
}

bool People::isEmpty()
{
	return intSize == 0;
}

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
}

void People::addPerson(Employee **& empTempList)
{
	for (int i = 0; i < intSize; i++)
	{
		empTempList[i] = empList[i];
	}
	intSize++;
	empList = new Employee*[intSize];
	lngSerialList = new long[intSize];
	blEmpty = new bool[intSize];
	for (int i = 0; i < intSize; i++)
	{
		Employee empTemp = *empTempList[i];
		empList[i] = empTempList[i];
		lngSerialList[i] = empTemp.getSerial;
		blEmpty[i] = empTemp.isInitialized;
	}
	set(intSize);
}

void People::addPerson(Employee & empB)
{
	empTempList = new Employee*[intSize + 1];
	empTempList[intSize + 1] = new Employee;
	*empTempList[intSize + 1] = empB;
	addPerson(empTempList);
	delete empTempList;
}

void People::addPerson(Candidate & cndB)
{
	empTempList = new Employee*[intSize + 1];
	empTempList[intSize + 1] = new Candidate;
	*empTempList[intSize + 1] = cndB;
	addPerson(empTempList);
	delete empTempList;
}

void People::remPerson(int intIndex)
{
	lngSerialList[intIndex] = -1;
	blEmpty[intIndex] = true;
	intLastTouched = intIndex;
	delete empList[intIndex];
}

void People::remPerson(Employee & empB)
{
	for (int i = 0; i < intSize; i++)
	{
		if (*empList[i] == empB)
		{
			remPerson(i);
			break;
		}
	}
}

void People::remPerson(Candidate & cndB)
{
	for (int i = 0; i < intSize; i++)
	{
		if (*empList[i] == cndB)
		{
			remPerson(i);
			break;
		}
	}
}

void People::remPerson(long lngExistingSerial)
{
	for (int i = 0; i < intSize; i++)
	{
		Employee empTemp = *empList[i];
		if (empTemp.getSerial == lngExistingSerial)
		{
			remPerson(i);
			break;
		}
	}
}

int People::operator<< (People & pplB)
{
	int intRetVal;
	intRetVal = intSize + intLastTouched;
	intRetVal << (pplB.intSize + pplB.intLastTouched);
	return intRetVal;
}

int People::operator>> (People & pplB)
{
	int intRetVal;
	intRetVal = intSize + intLastTouched;
	intRetVal >> (pplB.intSize + pplB.intLastTouched);
	return intRetVal;
}

void People::operator= (People & pplB)
{
	**empTempList = **pplB.empTempList;
}

bool People::operator== (People & pplB)
{
	return **empTempList == **pplB.empTempList;
}


People::People()
{
	empList = new Employee*[];
	lngSerialList = new long[];
	blEmpty = new bool[];
	intSize = 0;
	intLastTouched = -1;
}

People::People(People & pplB)
{
	*this = pplB;
}

People::~People()
{
	for (int i = 0; i < intSize; i++)
	{
		delete empList[i];
	}
	intSize = 0;
	delete empList;
	delete lngSerialList;
	delete blEmpty;
}
