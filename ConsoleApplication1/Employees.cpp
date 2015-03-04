// Employees.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#if !defined(myMenu_h)
#include "myMenu.h"
#endif


using namespace std;


int main()
{
	System::Console::Clear();
	cout << "Welcome to Gil's HR application." << endl << endl;
	myMenu * mnuBackEnd = new myMenu;
	myMenu & mnuInterface = *mnuBackEnd;
	while (mnuInterface.getSelection() != -1)
	{
		System::Console::Clear();
		mnuInterface.MenuInit();
	}
	delete mnuBackEnd;
    return 0;
};
