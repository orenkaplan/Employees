#pragma once
#include "Employee.h"
#include "People.h"


class Candidate :
	public Employee
{
public:
	void show();
	int getStatus();
	bool doesFit();
	void setStatus(char chrNewStatus);
	void changeFits();
	int intStat(char chrConvStat);
	char chrStat(int intConvStat);
	void activate();
	long operator<< (Candidate & cndB);
	long operator>> (Candidate & cndB);
	void operator= (Candidate & cndB);
	bool operator== (Candidate & cndB);
	Candidate();
	Candidate(string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, int intNewStat);
	Candidate(Candidate & cndB);
	~Candidate();
	friend void employ(Candidate & cndFitsAs, Employee & empNewEmployee);

private:
	int * intStatus;
	bool * blFits;
};

