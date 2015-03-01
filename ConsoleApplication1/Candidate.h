#pragma once
#include "Employee.h"
#include "People.h"


class Candidate :
	public Employee
{
private:
	int * intStatus;
	bool * blFits;

public:
	void show();
	int getStatus();
	bool doesFit();
	void setStatus(char chrNewStatus);
	void changeFits(bool blValue);
	int intStat(char chrConvStat);
	char chrStat(int intConvStat);
	virtual bool isInitialized();
	void activate();
	void terminate();
	long operator<< (Candidate & cndB);
	long operator>> (Candidate & cndB);
	void operator= (Candidate & cndB);
	bool operator== (Candidate & cndB);
	bool operator== (Employee & empB);
	Candidate();
	Candidate(string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat);
	Candidate(Candidate & cndB);
	~Candidate();
	friend void employ(Candidate & cndFitsAs, Employee & empNewEmployee);
};

