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
	return this->getSerial() != NULL && this->getName() != to_string(NULL) && this->isActive() != NULL;
};

void Person::show()
{
	// Pure Virtual - not relevant
};

ostream & operator << (ostream & ostMyStream, const Person & prsB)
{
	return ostMyStream; // Abstract class - not relevant
};

void Person::operator= (Person & prsB)
{
	this->setSerial(prsB.getSerial());
	this->setActive(prsB.isActive());
	this->setName(prsB.getName());
};

bool Person::operator== (Person & prsB)
{
	return this->getSerial() == prsB.getSerial() && this->isActive() == prsB.isActive() && this->getName() == prsB.getName();
};

void Person::setSerial(long lngNewSerial)
{
	*lngSerial = lngNewSerial;
};

void Person::setActive(bool blValue)
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
	this->setSerial(NULL);
	this->setName(NULL);
	this->setActive(NULL);
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

