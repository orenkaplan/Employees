#pragma once
#include "People.h"


class Person
{
private:
	long * lngSerial;
	string * strName;
	bool * blActive;
	void set(long lngNewSerial);

public:
	virtual void show() = 0;
	long getSerial();
	string getName();
	bool isActive();
	virtual bool isInitialized();
	virtual void operator= (Person & prsB);
	virtual bool operator== (Person & prsB);
	virtual void set(bool blValue);
	virtual void setName(string strNewName);
	Person();
	Person(Person & prsB);
	virtual ~Person();
	virtual friend ostream & operator << (ostream & ostMyStream, const Person & prsB) = 0;
};

