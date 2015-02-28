#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;


void Person::chooseGet(char chrWTG)
{
	switch (chrWTG)
	{
		case 's':
		{
			*lngGot = *lngSerial;
			strGot = NULL;
		}
			break;
		case 'n':
		{
			*strGot = *strName;
			lngGot = NULL;
		}
			break;
		case 'a':
		{
			*lngGot = *blActive;
			strGot = NULL;
		}
			break;
		default:
		{
			strGot = NULL;
			lngGot = NULL;
		}
	}
}

void Person::get(char chrWhatToGet)
{
	chooseGet(chrWhatToGet);
}

void Person::show()
{
	cout << "Person " << *strName << ", number " << *lngSerial << " is";
	if (!*blActive)
	{
		cout << "n't";
	}
	cout << " active." << endl;
}

long Person::operator<< (Person & prsB)
{
	long lngRetVal;
	lngRetVal = *lngSerial;
	lngRetVal << *prsB.lngSerial;
	return lngRetVal;
}

long Person::operator>> (Person & prsB)
{
	long lngRetVal;
	lngRetVal = *lngSerial;
	lngRetVal >> *prsB.lngSerial;
	return lngRetVal;
}

void Person::operator= (Person & prsB)
{
	*blActive = *prsB.blActive;
	*strName = *prsB.strName;
}

bool Person::operator== (Person & prsB)
{
	return *blActive == *prsB.blActive && *strName == *prsB.strName;
}

void Person::set(bool blValue)
{
	*blActive = blValue;
}


Person::Person()
{

}

Person::Person(string strNewName, bool blIsActive)
{

}

Person::Person(Person &obj)
{

}

Person::~Person()
{

}
