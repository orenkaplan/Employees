#if !defined(People_h)


#pragma once
#if !defined(Person_h)
#include "Person.h"
#endif

#if !defined(Employee_h)
#include "Employee.h"
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


#define People_h

class People:
	private Person
{
protected:
	long * lngGot;

private:
	static Employee ** empList;
	Employee ** empTempList;
	static long * lngSerialList;
	static bool * blEmpty;
	static int intSize;
	static int intCount;
	static int intLastTouched;
	void addPerson(Employee **& empTempList);
	void remPerson(int intIndex);
	virtual void set(int intNewIndex);

public:
	virtual void show();
	void setLastTouched(long lngTouchedSerial);
	int getSize();
	int getCount();
	int getLastTouchedIndex();
	bool isEmpty();
	long getNewSerial();
	void addPrs(Employee **& empTempList);
	void addPerson(Employee & empB);
	void addPerson(Candidate & cndB);
	void remPerson(int intIndex);
	void remPerson(Employee & empB);
	void remPerson(Candidate & cndB);
	void remPerson(long lngExistingSerial);
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People & pplB);
	~People();
	friend std::ostream & operator << (std::ostream & ostMyStream, const People & pplB);
};


#endif