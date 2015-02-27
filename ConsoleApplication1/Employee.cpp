#include "stdafx.h"
#include <stdio.h>
#include "Employee.h"


using namespace System;


void Employee::selectGet(char chrWTG)
{
	switch (chrWTG)
	{
		case 'p':
			lngGot = lngSalary;
			break;
		case 't':
			{
				*chrGot = NULL;
				chrGot[0] = chrType;
			}
			break;
		default:
			chooseGet(chrWTG);
	}
}

void Employee::get(char chrWhatToGet)
{
	selectGet(chrWhatToGet);
}

void Employee::show()
{
	switch (chrType)
	{
		case 'g':
			Console::Write("Global ");
			break;
		case 't':
			Console::Write("Temporary ");
			break;
		case 'h':
			Console::Write("Hourly ");
			break;
		default:
			{
				Console::WriteLine("Bad employee type.");
				Console::WriteLine("Please start over and report to author.");
			}
			return;
	}
	Console::Write("employee ");
	Console::Write(chrName);
	Console::Write(", number ");
	Console::Write(lngSerial);
	Console::Write(" is ");
	if (!blActive)
	{
		Console::Write("not ");
	}
	Console::WriteLine("active.");
}

void Employee::set(char *chrNewName)
{
	*chrName = NULL;
	*chrName = *chrNewName;
}

void Employee::set(char chrNewType)
{
	chrType = chrNewType;
}

void Employee::set(long lngNewSalary)
{
	lngSalary = lngNewSalary;
}

void Employee::terminate()
{
	blActive = false;
}

void Employee::activate(long lngNewSalary)
{
	blActive = true;
	set(lngNewSalary);
}

long Employee::operator<< (Employee & empB)
{
	long lngResponse;
	empB.get('s');
	lngResponse = lngSerial;
	lngResponse << empB.lngGot;
	empB.get(' ');
	return lngResponse;
}

void Employee::operator= (Employee & empB)
{
	empB.get('a');
	blActive = empB.lngGot;
	empB.get('n');
	*chrName = NULL;
	*chrName = *empB.chrGot;
	empB.get('t');
	chrType = *empB.chrGot;
	empB.get('p');
	lngSalary = empB.lngGot;
	empB.get(' ');
	get(' ');
}


Employee::Employee()
{

}

Employee::Employee(char *chrNewName, char chrNewType, bool blIsActive)
{

}

Employee::Employee(Employee &obj)
{

}

Employee::~Employee()
{

}
