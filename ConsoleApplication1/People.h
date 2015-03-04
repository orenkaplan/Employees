#pragma once

#include <string>
#include <iostream>


#include "Person.h"
#include "Employee.h"
#include "Candidate.h"

//forward declarations
//class Employee;
//class Candidate;

class People
{
private:
	static Person ** prsList;
	Person ** prsTempList;
	static long * lngSerialList;
	static bool * blEmpty;
	static int intSize;
	static int intCount;
	static int intLastTouched;
	void remPerson(int intIndex);
	void addPrs(Person **& prsTempList);
	virtual void set(int intNewIndex);

public:
	virtual void show();
	void setLastTouched(long lngTouchedSerial);
	int getSize();
	int getCount();
	int getLastTouchedIndex();
	bool isEmpty();
	long getNewSerial();
	void remPerson(long lngExistingSerial);
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People & pplB);
	~People();
	friend void addPerson(Employee & empB);
	friend void addPerson(Candidate & cndB);
	friend void remPerson(Employee & empB);
	friend void remPerson(Candidate & cndB);
	friend std::ostream & operator << (std::ostream & ostMyStream, const People & pplB);
};
