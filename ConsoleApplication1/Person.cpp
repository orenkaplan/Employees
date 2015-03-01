#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;


long Person::getSerial()
{
	return *lngSerial;
}

string Person::getName()
{
	return *strName;
}

bool Person::isActive()
{
	return *blActive;
}

bool Person::isInitialized()
{
	return lngSerial != NULL && strName != NULL && blActive != NULL;
}

void Person::show()
{
	// Pure Virtual - not relevant
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
	*lngSerial = *prsB.lngSerial;
	*blActive = *prsB.blActive;
	*strName = *prsB.strName;
}

bool Person::operator== (Person & prsB)
{
	return *blActive == *prsB.blActive && *strName == *prsB.strName;
}

void Person::setActive(bool blValue)
{
	*blActive = blValue;
}

void Person::set(string strNewName)
{
	*strName = strNewName;
}


Person::Person()
{

}

Person::Person(string strNewName, bool blIsActive)
{

}

Person::Person(Person & prsB)
{

}

Person::~Person()
{

}
