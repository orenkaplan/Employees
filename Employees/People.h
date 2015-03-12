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
	static int intSize;
	static int intCount;
	static int intLastTouched;
	bool blLastInstance = false;

public:
	static Person ** prsList;
	static Person ** prsTempList;
	static long * lngSerialList;
	static bool * blEmpty;
	void setLastTouched(int intNewIndex);
	void remPerson(int intIndex);
	void addPrs();
	void show(char chrType = '\0');
	bool show(long lngExistingSerial);
	void setLastTouched(long lngTouchedSerial);
	void setLastInstance();
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
	void setCName(int intIndex, std::string strNewName);
	void setCActive(int intIndex, bool blNewActive);
	void setCType(int intIndex, char chrNewType);
	void setCSerial(int intIndex, long lngNewSerial);
	void setCSalary(int intIndex, long lngNewSalary);
	void setCStatus(int intIndex, char chrNewStatus);
	void setCFit(int intIndex, bool blNewFit);
	void remPerson(long lngExistingSerial);
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People & pplB);
	~People();
	int getIndex(long lngSerialToGet);
	friend void remEmployee(Employee & empB);
	friend void remCandidate(Candidate & cndB);
	friend std::ostream & operator<< (std::ostream & ostMyStream, const People & pplB);
};
