#pragma once
#include "Person.h"
#include "People.h"


class Employee :
	protected Person
{
protected:
	long * lngSalary;
	char * chrType;
	void selectGet(char chrWTG);

public:
	Employee();
	Employee(string strNewName, char chrNewType, bool blIsActive);
	Employee(Employee &obj);
	virtual ~Employee();
	virtual void show();
	virtual void get(char chrWhatToGet);
	virtual void set(string strNewName);
	virtual void set(char chrNewType);
	virtual void set(long lngNewSalary);
	virtual void terminate();
	virtual void activate(long lngNewSalary);
	virtual long operator<< (Employee & empB);
	virtual long operator>> (Employee & empB);
	virtual void operator= (Employee & empB);
	virtual bool operator== (Employee & empB);
};

