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
	static Employee * prsList;
	Employee * prsTempList;
	static long * lngSerialList;
	static bool * blEmpty;
	static int intSize;
	static int intLastTouched;
	static void addPerson();
	static void remPerson();

public:
	virtual void show();
	virtual void get(char chrWhatToGet);
	void set(int intNewValue, char chrWhatToChange);
	static bool isEmpty();
	long getNewSerial();
	void addPerson(Employee & empB);
	void addPerson(Candidate & cndB);
	void addPerson(long lngNewSerial);
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

