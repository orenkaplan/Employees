#pragma once
#include "People.h"
#include "Person.h"
#include "Employee.h"

#include <string>
#include <iostream>


class Candidate:
	public virtual Employee, public virtual Person
{
private:
	int * intStatus;
	bool * blFits;
	virtual std::string getString();
	char chrStat(int intConvStat);
	long getSalary();
	char getType();
	void setType(char chrNewType);
	void setSalary(long lngNewSalary);

public:
	void show();
	char getStatus();
	bool doesFit();
	void setStatus(char chrNewStatus);
	void changeFits(bool blValue);
	int intStat(char chrConvStat);
	void activate();
	void terminate();
	virtual bool isInitialized();
	void operator= (Candidate & cndB);
	Candidate();
	Candidate(std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat);
	Candidate(Candidate & cndB);
	~Candidate();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Candidate & cndB);
	friend bool employ(Candidate & cndFitsAs, Employee & empNewEmployee);
	friend bool operator== (Candidate & cndA, Candidate & cndB);
	friend bool operator== (Candidate & cndB, Person & prsB);
	friend bool operator== (Person & prsB, Candidate & cndB);
	friend bool operator== (Employee & empB, Candidate & cndB);
	friend bool operator== (Candidate & cndB, Employee & empB);
};