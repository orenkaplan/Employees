#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Person.h"


using namespace std;


void Person::setSerial(long lngNewSerial)
{
	*lngSerial = lngNewSerial;
};

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

void Person::setActive(bool blValue)
{
	*blActive = blValue;
};

void Person::setName(string strNewName)
{
	*strName = strNewName;
};

bool Person::isInitialized()
{
	return getSerial() != -1 && getName() != to_string(NULL) && isActive() != NULL;
};

void Person::show()
{
	// Pure Virtual - not relevant
};

void Person::operator= (Person & prsB)
{
	setSerial(prsB.getSerial());
	setActive(prsB.isActive());
	setName(prsB.getName());
};

bool Person::operator== (Person & prsB)
{
	return getSerial() == prsB.getSerial() && isActive() == prsB.isActive() && getName() == prsB.getName();
};



Person::Person()
{
	lngSerial = new long;
	strName = new string;
	blActive = new bool;
	setSerial(-1);
	setName(to_string(NULL));
	setActive(NULL);
};

Person::Person(Person & prsB) 
{
	lngSerial = new long;
	strName = new string;
	blActive = new bool;
	*this = prsB;
};

Person::~Person()
{
	delete lngSerial;
	delete strName;
	delete blActive;
};


ostream & operator << (ostream & ostMyStream, Person & prsB)
{
	return ostMyStream; // Abstract class - not relevant
};