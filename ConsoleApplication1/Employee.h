#pragma once
#include "Person.h"
#include "People.h"

#include <string>
#include <iostream>

//forward declaration
//	class Person;

class Employee:
	public virtual Person
{
protected:
	long * lngSalary;
	char * chrType;
	virtual std::string getString();

public:
	virtual void show();
	long getSalary();
	char getType();
	void setType(char chrNewType);
	void setSalary(long lngNewSalary);
	void activate(long lngNewSalary);
	virtual void terminate();
	virtual bool isInitialized();
	virtual void operator= (Employee & empB);
	Employee();
	Employee(std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive);
	Employee(Employee & empB);
	virtual ~Employee();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Employee & empB);
//	friend void operator<= (Person & prsB, Employee & empB);
	friend bool operator== (Employee & empA, Employee & empB);
	friend bool operator== (Employee & empB, Person & prsB);
	friend bool operator== (Person & prsB, Employee & empB);
};