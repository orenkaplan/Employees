#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "myMenu.h"
#include "People.h"


using namespace std;

// uncomment if static
//People *myMenu::pplList = NULL;
//std::string myMenu::strOption[] = {};
//int myMenu::intMenuStatus = NULL;
//int myMenu::intMenuSelection = NULL;

void myMenu::mnuInit()
{
	for (int i = 0; i <= 9; i++)
	{
		switch (this->getSelection())
		{
			case 0:
			{
				switch (i)
				{
					case 1:
						strOption[i] = to_string(i) + ") Add Employee";
						break;
					case 2:
						strOption[i] = to_string(i) + ") Add Candidate";
						break;
					case 3:
						strOption[i] = to_string(i) + ") Change Employee";
						break;
					case 4:
						strOption[i] = to_string(i) + ") Change Candidate";
						break;
					case 5:
						strOption[i] = to_string(i) + ") Remove Employee";
						break;
					case 6:
						strOption[i] = to_string(i) + ") Remove Candidate";
						break;
					case 7:
						strOption[i] = to_string(i) + ") Show Employee";
						break;
					case 8:
						strOption[i] = to_string(i) + ") Show Candidate";
						break;
					case 9:
						strOption[i] = to_string(i) + ") Show full HR list";
						break;
					case 0:
						strOption[i] = to_string(i) + ") Show HR database statistics";
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
			case 1:
			{
				switch (i)
				{
				case 1:
					strOption[i] = " ";
					break;
				case 2:
					strOption[i] = to_string(i - 1) + ") Add Employee Menu:";
					break;
				case 3:
					strOption[i] = "--------------------";
					break;
				case 4:
					strOption[i] = to_string(i - 3) + ") Add 'empty' employee";
					break;
				case 5:
					strOption[i] = to_string(i - 3) + ") Add employee with initialization data";
					break;
				case 6:
					strOption[i] = to_string(i - 3) + ") Select employee to copy";
					break;
				case 7:
					strOption[i] = to_string(i - 3) + ") Show full HR list";
					break;
				case 8:
					strOption[i] = to_string(i - 3) + ") Show HR database statistics";
					break;
				case 9:
					strOption[i] = " ";
					break;
				case 0:
					strOption[i] = to_string(i) + ") Back to main menu";
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
			case 2:
				break;
			case 3:
				break;
			case 4:
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
				cout << strOption[0] << endl << endl << "Please type your choice and then type <enter>\\<return>: ";
				cin >> intMenuSelection;
				while (this->getSelection() < 0 || this->getSelection() > 9 || cin.fail())
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
							intMenuSelection = -1;
							break;
						}
					}
					cout << "Invalid choice, try again:";
					cin >> intMenuSelection;
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

void myMenu::mnuAct()
{
	chrCreatePerson = '\0';
	strName = (string)NULL;
	blActive = NULL;
	chrType = NULL;
	lngSalary = NULL;
	chrStatus = NULL;
	blFits = NULL;
	bool blPause = false;
	switch (this->getMenuStatus())
	{
		case 0:
		{
			switch (this->getSelection())
			{
				case 1:
				{
					intMenuStatus = 1;
				}
					break;
				case 2:
				{
					intMenuStatus = 1;
				}
					break;
				case 3:
				{
					intMenuStatus = 1;
				}
					break;
				case 4:
				{
					intMenuStatus = 1;
				}
					break;
				case 5:
				{
					intMenuStatus = 1;
				}
					break;
				case 6:
				{
					intMenuStatus = 1;
				}
					break;
				case 7:
				{
					intMenuStatus = 1;
				}
					break;
				case 8:
				{
					intMenuStatus = 1;
				}
				case 9:
				{
					system("cls");
					pplList->show();
					blPause = true;
				}
					break;
				case 0:
				{
					cout << pplList << endl;
					blPause = true;
				}
					break;
				default:
					break;
			}
		}
			break;
		case 1:
		{
			switch (this->getSelection())
			{
				case 1:
					chrCreatePerson = 'e';
					break;
				case 2:
				{
					chrCreatePerson = 'E';
				}
					break;
				case 3:
					intMenuStatus = 2;
					break;
				case 4:
				{
					system("cls");
					pplList->show();
					blPause = true;
				}
					break;
				case 5:
				{
					cout << pplList << endl;
					blPause = true;
				}
					break;
				case 0:
					intMenuStatus--;
					break;
				default:
					break;
			}
		}
			break;
		default:
			break;
	}
	if (blPause)
	{
		cin.get();
	}
};

int myMenu::getMenuStatus()
{
	return intMenuStatus;
};

int myMenu::getSelection()
{
	return intMenuSelection;
};

char myMenu::getCreateType()
{
	return chrCreatePerson;
}

string myMenu::getCName()
{
	return strName;
};

bool myMenu::getCActive()
{
	return blActive;
};

char myMenu::getCType()
{
	return chrType;
};

long myMenu::getCSalary()
{
	return lngSalary;
};

char myMenu::getCStatus()
{
	return chrStatus;
};

bool myMenu::getCFit()
{
	return blFits;
};


myMenu::myMenu()
{
	pplList = new People;
	for (int i = 0; i <= 9; i++)
	{
		strOption[i] = (string)NULL;
	}
	intMenuStatus = 0;
	intMenuSelection = 0;
	this->mnuInit();
};


myMenu::~myMenu()
{
	delete pplList;
};
