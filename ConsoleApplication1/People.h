#pragma once
#if !defined(string)
#include <string>
#endif
#if !defined(ostream)
#include <iostream>
#endif

#if !defined(Candidate_h)
#include "Candidate.h"
#endif
#if !defined(Employee_h)
#include "Employee.h"
#endif
#if !defined(Person_h)
#include "Person.h"
#endif


#if !defined(People_h)
#define People_h
#endif

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
	friend bool operator== (Employee & empB, Candidate & cndB);
	friend bool operator== (Candidate & cndB, Employee & empB);
};
