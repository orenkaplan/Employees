#if !defined(Candidate_h)


#pragma once
#if !defined(Person_h)
#include "Person.h"
#endif
#if !defined(Employee_h)
#include "Employee.h"
#endif


#if !defined(string)
#include <string>
#endif
#if !defined(ostream)
#include <iostream>
#endif


#define Candidate_h

class Candidate:
	public Person, public Employee
{
private:
	int * intStatus;
	bool * blFits;

public:
	void show();
	char getStatus();
	virtual std::string getString();
	bool doesFit();
	void setStatus(char chrNewStatus);
	void changeFits(bool blValue);
	int intStat(char chrConvStat);
	char chrStat(int intConvStat);
	virtual bool isInitialized();
	void activate();
	void terminate();
	void operator= (Candidate & cndB);
	bool operator== (Candidate & cndB);
	bool operator== (Employee & empB);
	Candidate();
	Candidate(std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat);
	Candidate(Candidate & cndB);
	~Candidate();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Candidate & cndB);
	friend void employ(Candidate & cndFitsAs, Employee & empNewEmployee);
};


#endif