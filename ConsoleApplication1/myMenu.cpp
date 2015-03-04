#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#if !defined(myMenu_h)
#include "myMenu.h"
#endif
#if !defined(People_h)
#include "People.h"
#endif


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
						strOption[i] = to_string(i) + "Show HR database statistics";
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
		if (i != 0)
		{
			cout << strOption[i] << endl;
			if (i == 9)
			{
				cout << strOption[0] << endl << endl << "Please type your choice and then type <enter>\<return>: ";
				cin >> *intMenuSelection;
				while (*intMenuSelection < 0 || *intMenuSelection > 9 || cin.fail())
				{
					// if not a numeric character or string
					// clear the failure and pull off the non-numeric character or string
					if (cin.fail())
					{
						cin.clear();
						string  strErr;
						cin >> strErr;
						transform(strErr.begin(), strErr.end(), strErr.begin(), ::tolower);
						if (strErr == "x" || strErr == "q" || strErr == "exit" || strErr == "quit")
						{
							*intMenuSelection = -1;
						}
					}
					cout << "Invalid choice, try again:";
					cin >> *intMenuSelection;
				}
			}
		}
		else
		{
			cout << " Gil's HR database menu:" << endl
				<< "-------------------------" << endl << endl;
		}
	}
};

int myMenu::getSelection()
{
	return *intMenuSelection;
};


myMenu::myMenu()
{
	class People;
	pplList = new People;
	strOption = new string[9];
	intMenuStatus = new int;
	*intMenuStatus = 0;
	MenuInit;
};


myMenu::~myMenu()
{
	delete strOption;
	delete pplList;
	delete intMenuStatus;
};
