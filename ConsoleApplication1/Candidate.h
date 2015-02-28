#pragma once
#include "Employee.h"
#include "People.h"


class Candidate :
	protected Employee
{
public:
	Candidate();
	Candidate(string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, int intNewStat);
	Candidate(Candidate &obj);
	~Candidate();
	void show();
	void get(char chrWhatToGet);
	void set(char chrNewStatus);
	int intStat(char chrConvStat);
	char chrStat(int intConvStat);
	void terminate();
	void activate();
	long operator<< (Candidate & cndB);
	long operator>> (Candidate & cndB);
	void operator= (Candidate & cndB);
	bool operator== (Candidate & cndB);
	friend void employ(Candidate & cndFitsAs, Employee & empNewEmployee);

private:
	int * intStatus;
	bool * blFits;
};

