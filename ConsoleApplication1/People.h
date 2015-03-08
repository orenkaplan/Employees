#pragma once

#include <string>
#include <iostream>

#include "Person.h"

//forward declarations
class Employee;
class Candidate;

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
	virtual void show(char chrType);
	void setLastTouched(long lngTouchedSerial);
	int getSize();
	int getCount();
	int getLastTouchedIndex();
	bool isEmpty();
	long getNewSerial();
	std::string getCName(int intIndex);
	bool getCActive(int intIndex);
	char getCType(int intIndex);
	long getSerialSalary(int intIndex, bool blGetSerial = false);
	char getCStatus(int intIndex);
	bool getCFit(int intIndex);
	void remPerson(long lngExistingSerial);
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People & pplB);
	~People();
	int getIndex(long lngSerialToGet);
	friend void addEmployee(Employee & empB);
	friend void addCandidate(Candidate & cndB);
	friend void remEmployee(Employee & empB);
	friend void remCandidate(Candidate & cndB);
	friend std::ostream & operator << (std::ostream & ostMyStream, const People & pplB);
};
