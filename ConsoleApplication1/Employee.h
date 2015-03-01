#pragma once
#include "Person.h"
#include "People.h"


class Employee :
	public Person
{
private:
	long * lngSalary;
	char * chrType;

public:
	virtual void show();
	long getSalary();
	char getType();
	virtual void set(char chrNewType);
	void setSalary(long lngNewSalary);
	virtual bool isInitialized();
	virtual void terminate();
	virtual void activate(long lngNewSalary);
	virtual long operator<< (Employee & empB);
	virtual void operator= (Employee & empB);
	virtual bool operator== (Employee & empB);
	virtual bool operator== (Candidate & cndB);
	Employee();
	Employee(string strNewName, long lngNewSalary, char chrNewType, bool blIsActive);
	Employee(Employee &obj);
	virtual ~Employee();
};

