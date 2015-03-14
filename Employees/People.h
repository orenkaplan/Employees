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
//	Person * prsList[10];
//	Person * prsTempList[10];
	static  long * lngSerialList[10];
	static  bool * blEmpty[10];
	void setLastTouched(int intNewIndex);
	friend void remPerson(int intIndex);
	void addPrs(char chrCreateType, int intMySize,
		std::string strName, char chrType, bool blActive,
		long lngSalary = 0,
		char chrStatus = '\n', bool blFits = false);
	void show(char chrType = '\0');
	void show(long lngExistingSerial);
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
	void operator= (People & pplB);
	bool operator== (People & pplB);
	People();
	People(People & pplB);
	~People();
	friend int getIndex(long lngSerialToGet);
	friend std::ostream & operator<< (std::ostream & ostMyStream, const People & pplB);
};
