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

	Candidate(std::string strNewName, char chrNewType, bool blIsActive, bool blDoesFit, char chrNewStat) : Candidate()
	{
		setName(strNewName);
		setType(chrNewType);
		setActive(blIsActive);
		changeFits(blDoesFit);
		setStatus(chrNewStat);
	};

	Candidate(Candidate & cndB) : Candidate()
	{
		long lngTemp;
		lngTemp = this->getSerial();
		*this = cndB;
		this->setSerial(lngTemp);
	};

	~Candidate();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Candidate & cndB);
// forward declarations
	class Person;
//	friend void operator=> (Person & prsB, Candidate & cndB);
	friend bool operator== (Candidate & cndB, Person & prsB);
	friend bool operator== (Person & prsB, Candidate & cndB);
	friend bool operator== (Employee & empB, Candidate & cndB);
	friend bool operator== (Candidate & cndB, Employee & empB);
};