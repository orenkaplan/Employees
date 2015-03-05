// Employees.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "myMenu.h"


using namespace std;


int main()
{
	cout << "Welcome to Gil's HR application." << endl << endl;
	myMenu * mnuBackEnd = new myMenu;
	while (mnuBackEnd->getSelection() != -1)
	{
		system("cls");
		mnuBackEnd->MenuInit();
	}
	delete mnuBackEnd;
    return 0;
};
