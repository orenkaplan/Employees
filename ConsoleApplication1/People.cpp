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
			prsList[i].show;
		}
		else
		{
			cout << "No peron recorded." << endl;
		}
	}
}

void People::get(char chrWhatToGet)
{
	switch (chrWhatToGet)
	{
		case 's':
			*lngGot = intSize;
			break;
		case 'l':
			*lngGot = intLastTouched;
			break;
		default:
			lngGot = NULL;
	}
}

void People::set(int intNewValue, char chrWhatToChange)
{
	switch (chrWhatToChange)
	{
	case 's':
		intSize = intNewValue;
		break;
	case 'l':
		intLastTouched = intNewValue;
		break;
	default:
		*lngGot = -1;
	}
	lngGot = NULL;
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

void People::addPerson()
{

}

void People::addPerson(Employee & empB)
{
	prsTempList = new Employee[intSize + 1];
	for (int i = 0; i < intSize; i++)
	{
		prsTempList[i] = prsList[i];
	}
	prsTempList[intSize + 1] = empB;
	intSize++;
	prsList = new Employee[intSize];
	lngSerialList = new long[intSize];
	for (int i = 0; i < intSize; i++)
	{
		prsList[i] = prsTempList[i];
		lngSerialList[i] = *prsList[i].getSerial;

	}

}

void People::addPerson(Candidate & cndB)
{

}

void People::addPerson(long lngNewSerial)
{

}

void People::remPerson()
{

}

void People::remPerson(Person & prsB)
{

}

void People::remPerson(Employee & empB)
{

}

void People::remPerson(Candidate & cndB)
{

}

void People::remPerson(long lngExistingSerial)
{

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
	*lngGot = *pplB.lngGot;
	*prsTempList = *pplB.prsTempList;
}

bool People::operator== (People & pplB)
{
	return *lngGot == *pplB.lngGot && *prsTempList == *pplB.prsTempList;
}


People::People()
{

}

People::People(People & pplB)
{
	*this = pplB;
}

People::~People()
{

}
