#pragma once
#include "Person.h"
#include "People.h"

#include <string>
#include <iostream>


class Employee:
	public virtual Person
{
protected:
	long * lngSalary;
	char * chrType;

public:
	virtual std::string getString();
	virtual void show();
	virtual long getSalary();
	virtual char getType();
	virtual char getStatus();
	virtual bool doesFit();
	virtual void setType(char chrNewType);
	virtual void setSalary(long lngNewSalary);
	virtual void setStatus(char chrNewStatus);
	virtual void changeFits(bool blValue);
	virtual void activate(long lngNewSalary);
	virtual void terminate();
	virtual bool isInitialized();
	void operator= (Employee & empB);
	Employee();
	Employee(const People & pplGet);
	Employee(const People & pplGet, std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive);
	Employee(const People & pplGet, const Employee & empB);
	virtual ~Employee();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Employee & empB);
	friend bool operator== (const Employee & empA, const Employee & empB);
	friend bool operator== (const Employee & empB, const Person & prsB);
	friend bool operator== (const Person & prsB, const Employee & empB);
};