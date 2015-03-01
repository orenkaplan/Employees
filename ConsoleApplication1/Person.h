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
	virtual long operator<< (Person & prsB);
	virtual long operator>> (Person & prsB);
	virtual void operator= (Person & prsB);
	virtual bool operator== (Person & prsB);
	void setActive(bool blValue);
	void set(string strNewName);
	Person();
	Person(string strNewName, bool blIsActive);
	Person(Person & prsB);
	virtual ~Person();
};

