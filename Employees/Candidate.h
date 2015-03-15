#pragma once
#include "People.h"
#include "Person.h"
#include "Employee.h"

#include <string>
#include <iostream>


class Candidate:
	public virtual Employee
{
private:
	int * intStatus;
	bool * blFits;
	char chrStat(int intConvStat);
	virtual long getSalary();
	virtual char getType();
	void setType(char chrNewType);
	void setSalary(long lngNewSalary);

public:
	virtual std::string getString();
	virtual void show();
	virtual char getStatus();
	virtual bool doesFit();
	virtual void setStatus(char chrNewStatus);
	virtual void changeFits(bool blValue);
	int intStat(char chrConvStat);
	virtual void activate();
	virtual void terminate();
	virtual bool isInitialized();
	void operator= (Candidate & cndB);
	Candidate(const People & pplGet);
	Candidate(const People & pplGet, std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat);
	Candidate(const People & pplGet, const Candidate & cndB);
	virtual ~Candidate();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Candidate & cndB);
	friend bool employ(People & pplGet, Candidate & cndFitsAs, Employee & empNewEmployee);
	friend bool operator== (const Candidate & cndA, const Candidate & cndB);
	friend bool operator== (const Candidate & cndB, const Person & prsB);
	friend bool operator== (const Person & prsB, const Candidate & cndB);
	friend bool operator== (const Employee & empB, const Candidate & cndB);
	friend bool operator== (const Candidate & cndB, const Employee & empB);
};