#pragma once
#include "People.h"


class Person
{
protected:
	long * lngGot;
	string * strGot;
	long * lngSerial;
	string * strName;
	bool * blActive;
	void chooseGet(char chrWTG);

public:
	Person();
	Person(string strNewName, bool blIsActive);
	Person(Person & prsB);
	virtual ~Person();
	virtual void show() = 0;
	virtual void get(char chrWhatToGet);
	virtual bool isInitialized();
	virtual long operator<< (Person & prsB);
	virtual long operator>> (Person & prsB);
	virtual void operator= (Person & prsB);
	virtual bool operator== (Person & prsB);
	virtual void set(bool blValue);
};

