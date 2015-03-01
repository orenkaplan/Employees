#pragma once
#include "Person.h"
#include "Employee.h"
#include "Candidate.h"

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
	static int intLastTouched;
	void addPerson(Employee **& empTempList);
	void remPerson(int intIndex);

public:
	virtual void show();
	virtual void set(int intNewIndex);
	int getSize();
	int getLastTouchedIndex();
	bool isEmpty();
	long getNewSerial();
	void addPerson(Employee & empB);
	void addPerson(Candidate & cndB);
	void remPerson(Employee & empB);
	void remPerson(Candidate & cndB);
	void remPerson(long lngExistingSerial);
	int operator<< (People & pplB);
	int operator>> (People & pplB);
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People & pplB);
	~People();
};

