#pragma once
#if !defined(People_h)
#include "People.h"
#endif
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

#if !defined(Candidate_h)
#define Candidate_h
#endif

class Candidate:
	public virtual Employee, public virtual Person
{
private:
	int * intStatus;
	bool * blFits;
	virtual std::string getString();
	char chrStat(int intConvStat);

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
	bool operator== (Candidate & cndB);
	Candidate();

	Candidate(std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat): Candidate()
	{
		setName(strNewName);
		setType(chrNewType);
		setActive(blIsActive);
		changeFits(blDoesFit);
		setStatus(chrNewStat);
	};

	Candidate(Candidate & cndB): Candidate()
	{
		long lngTemp;
		lngTemp = this->getSerial;
		*this = cndB;
		this->setSerial(lngTemp);
	};

	~Candidate();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Candidate & cndB);
	class Person;
	friend bool operator== (Candidate & cndB, Person & prsB);
};