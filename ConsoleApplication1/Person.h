#pragma once


class Employee;
class Candidate;

class Person
{
protected:
	long * lngSerial;
	std::string * strName;
	bool * blActive;

public:
	void setSerial(long lngNewSerial);
	long getSerial();
	std::string getName();
	bool isActive();
	void setActive(bool blValue);
	void setName(std::string strNewName);
	virtual bool isInitialized();
	virtual void show() = 0;
	virtual void operator= (Person & prsB);
	virtual bool operator== (Person & prsB);
	Person();
	Person(Person & prsB);
	virtual ~Person();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Person & prsB);
	friend bool employ(Candidate & cndFitsAs, Employee & empNewEmployee);
};
