#if !defined(Person_h)

#pragma once
#if !defined(string)
#include <string>
#endif
#if !defined(ostream)
#include <iostream>
#endif


#define Person_h
class Person
{
private:
	long * lngSerial;
	std::string * strName;
	bool * blActive;
	void set(long lngNewSerial);

public:
	virtual void show() = 0;
	long getSerial();
	std::string getName();
	bool isActive();
	virtual bool isInitialized();
	virtual void operator= (Person & prsB);
	virtual bool operator== (Person & prsB);
	virtual void set(bool blValue);
	virtual void setName(std::string strNewName);
	Person();
	Person(Person & prsB);
	virtual ~Person();
	friend std::ostream & operator << (std::ostream & ostMyStream, const Person & prsB);
};


#endif