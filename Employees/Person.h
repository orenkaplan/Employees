#pragma once

#include <string>
#include <iostream>


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
	virtual std::string getString() = 0;
	virtual long getSalary() = 0;
	virtual char getType() = 0;
	virtual char getStatus() = 0;
	virtual bool doesFit() = 0;
	virtual void setType(char chrNewType) = 0;
	virtual void setSalary(long lngNewSalary) = 0;
	virtual void setStatus(char chrNewStatus) = 0;
	virtual void changeFits(bool blValue) = 0;
	virtual void operator= (Person & prsB);
	virtual bool operator== (const Person & prsB);
	Person();
	Person(const Person & prsB);
	virtual ~Person();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Person & prsB);
};
