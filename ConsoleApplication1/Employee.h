#pragma once
//This is the same as 
// #ifndef Employee_h
//#define Employee_h
//#endif

#include <string>
#include <iostream>
#include "Person.h"
#include "People.h"



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
	virtual bool operator== (Employee & empB);

	Employee();

	Employee(std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive)
	{
		setName(strNewName);
		setSalary(lngNewSalary);
		setType(chrNewType);
		setActive(blIsActive);
	};

	Employee(Employee & empB) 
	{
		long lngTemp;
		lngTemp = this->getSerial();
		*this = empB;
		this->setSerial(lngTemp);
	};

	virtual ~Employee();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Employee & empB);
	class Person;
	friend bool operator== (Employee & empB, Person & prsB);
	friend bool operator== (Person & prsB, Employee & empB);
};