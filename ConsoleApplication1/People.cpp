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

int People::getCount()
{
	return intCount;
}

int People::getLastTouchedIndex()
{
	return intLastTouched;
}

void People::set(int intNewIndex)
{
	intLastTouched = intNewIndex;
}

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
}

bool People::isEmpty()
{
	return getSize == 0 || getCount == 0;
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
	intCount++;
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
	set(intIndex);
	intCount--;
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
	set((int)-1);
	intCount = -1;
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
