#pragma once
#include "Person.h"
#include "Employee.h"
#include "Candidate.h"

class People:
	protected Person
{
protected:
	long * lngGot;

private:
	static Person * prsList;
	Person * prsTempList;
	static long * lngSerialList;
	static bool * blEmpty;
	static int intSize;
	static int intLastTouched;

public:
	virtual void show();
	virtual void get(char chrWhatToGet);
	void set(int intNewValue, char chrWhatToChange);
	static bool isEmpty();
	long getNewSerial();
	int operator<< (People & pplB);
	int operator>> (People & pplB);
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People &obj);
	~People();
};

