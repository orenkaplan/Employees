#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "myMenu.h"


using namespace std;


void myMenu::MenuInit()
{
	for (int i = 0; i < 9; i++)
	{
		strOption[i] = to_string(i) + ") ";
		switch (*intMenuStatus)
		{
			case 0:
			{
				switch (i)
				{
					case 1:
						strOption[i] = to_string(i) + "Add Employee";
						break;
					case 2:
						strOption[i] = to_string(i) + "Add Candidate";
						break;
					case 3:
						strOption[i] = to_string(i) + "Change Employee";
						break;
					case 4:
						strOption[i] = to_string(i) + "Change Candidate";
						break;
					case 5:
						strOption[i] = to_string(i) + "Remove Employee";
						break;
					case 6:
						strOption[i] = to_string(i) + "Remove Candidate";
						break;
					case 7:
						strOption[i] = to_string(i) + "Show Employee";
						break;
					case 8:
						strOption[i] = to_string(i) + "Show Candidate";
						break;
					case 9:
						strOption[i] = to_string(i) + "Show full HR list";
						break;
					case 0:
						strOption[i] = to_string(i) + "Auto-Populate";
						break;
					default:
					{
						cout << "Bad Index when building menu." << endl << "Restart and contact author." << endl;
						strOption[i] = "";
					}
				}
				if (strOption[i] == "")
				{
					break;
				}
			}
				break;
			default:
				break;
		}
		if (strOption[i] == "")
		{
			break;
		}
	}

}


myMenu::myMenu()
{
	pplList = new People;
	strOption = new string[9];
	intMenuStatus = new int;
	*intMenuStatus = 0;
	MenuInit;
}


myMenu::~myMenu()
{
	delete strOption;
	delete pplList;
	delete intMenuStatus;
}
