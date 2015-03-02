#if !defined(Employee_h)


#pragma once
#if !defined(Person_h)
#include "Person.h"
#endif
#if !defined(Candidate_h)
#include "Candidate.h"
#endif

#if !defined(string)
#include <string>
#endif
#if !defined(ostream)
#include <iostream>
#endif


#define Employee_h

class Employee:
	public Person
{
private:
	long * lngSalary;
	char * chrType;

public:
	virtual void show();
	long getSalary();
	char getType();
	virtual std::string getString();
	virtual void set(char chrNewType);
	void setSalary(long lngNewSalary);
	virtual bool isInitialized();
	virtual void terminate();
	virtual void activate(long lngNewSalary);
	virtual void operator= (Employee & empB);
	virtual bool operator== (Employee & empB);
	virtual bool operator== (Candidate & cndB);
	Employee();
	Employee(std::string strNewName, long lngNewSalary, char chrNewType, bool blIsActive);
	Employee(Employee &obj);
	virtual ~Employee();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Employee & empB);
};


#endif