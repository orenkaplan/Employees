#pragma once
#include "Person.h"


class Employee :
	public Person
{
protected:
	long lngSalary;
	char chrType;
	void selectGet(char chrWTG);

public:
	Employee();
	Employee(string strNewName, char chrNewType, bool blIsActive);
	Employee(Employee &obj);
	~Employee();
	virtual void show();
	virtual void get(char chrWhatToGet);
	void set(string strNewName);
	void set(char chrNewType);
	void set(long lngNewSalary);
	virtual void terminate();
	virtual void activate(long lngNewSalary);
	virtual long operator<< (Employee & empB);
	virtual void operator= (Employee & empB);
};

