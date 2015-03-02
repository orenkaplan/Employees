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
};

string Person::getName()
{
	return *strName;
};;

bool Person::isActive()
{
	return *blActive;
};

bool Person::isInitialized()
{
	return getSerial != NULL && getName != NULL && isActive != NULL;
};

void Person::show()
{
	// Pure Virtual - not relevant
};

ostream & operator << (ostream & ostMyStream, const Person & prsB)
{
	// Pure Virtual - not relevant
};

void Person::operator= (Person & prsB)
{
	set(*prsB.getSerial);
	set(*prsB.isActive);
	setName(*prsB.getName);
};

bool Person::operator== (Person & prsB)
{
	return getSerial == *prsB.getSerial && isActive == *prsB.isActive && getName == *prsB.getName;
};

void Person::set(long lngNewSerial)
{
	*lngSerial = lngNewSerial;
};

void Person::set(bool blValue)
{
	*blActive = blValue;
};

void Person::setName(string strNewName)
{
	*strName = strNewName;
};


Person::Person()
{
	lngSerial = new long;
	strName = new string;
	blActive = new bool;
	set((long)0);
	set("");
	set(false);
};

Person::Person(Person & prsB)
{
	*this = prsB;
};

Person::~Person()
{
	delete lngSerial;
	delete strName;
	delete blActive;
};
