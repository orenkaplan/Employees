// Employees.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "myMenu.h"

using namespace std;


int main()
{
	System::Console::Clear;
	cout << "Welcome to Gil's HR application." << endl;
	myMenu * mnuInterface = new myMenu;

	delete mnuInterface;
    return 0;
}
