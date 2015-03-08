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
		switch (getMenuStatus())
		{
			case 0: // Main Menu
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
						strOption[i] = "";
						break;
				}
				if (strOption[i] == "")
				{
					break;
				}
			}
				break;
			case 1:
			case 3: // Add Employee Menu & Add Candidate Menu
				mnuInitAdd(i);
				break;
			case 2:
			case 4:
			{

			}
				break;
			case 5:
				break;
			default:
				break;
		}
		if (strOption[i] == "")
		{
			cout << "Bad Index when building menu." << endl << "Restart and contact author." << endl;
			break;
		}
		if (i != 0)
		{
			cout << strOption[i] << endl;
			if (i == 9)
			{
				cout << strOption[0] << endl << endl << "Please type your choice and then type <enter>\\<return>: ";
				cin >> intMenuSelection;
				while (getSelection() < 0 || getSelection() > 9 || cin.fail())
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
	lngCSalary = NULL;
	lngCSerial = NULL;
	chrStatus = NULL;
	blFits = NULL;
	bool blPause = false;
	switch (getMenuStatus())
	{
		case 0:
		{
			switch (getSelection())
			{
				case 1: // Add Employee
					intMenuStatus = 1;
					break;
				case 2: // Add Candidate
					intMenuStatus = 3;
					break;
				case 3: // Change Employee
					intMenuStatus = 5;
					break;
				case 4: // Change Candidate
					intMenuStatus = 6;
					break;
				case 5: // Remove Employee
					intMenuStatus = 7;
					break;
				case 6: // Remove Candidate
					intMenuStatus = 8;
					break;
				case 7: // Show Employee
				{
					intMenuStatus = 9;
				}
					break;
				case 8: // Show Candidate
				{
					intMenuStatus = 10;
				}
				case 9: // Show full HR list
					blPause = mnuShow();
					break;
				case 0: // Show HR database statistics
					blPause = mnuShowStats();
					break;
				default:
					break;
			}
		}
			break;
		case 1: // Add Employee Menu
		case 3: // Add Candidate Menu
			blPause = mnuActAdd();
			break;
		case 2: // Select Employee Menu
		case 4: // Select Candidate Menu
			blPause = mnuActSelect();
			break;
		default:
			break;
	}
	if (blPause)
	{
		cin.get();
	}
};

void myMenu::mnuInitSelect(int intIndex)
{
	string strCap = NULL;
	string strLow = NULL;
	switch (getMenuStatus())
	{
		case 2:
			strCap = "Employee";
			strLow = "employee";
			break;
		case 4:
			strCap = "Candidate";
			strLow = "candidate";
			break;
		default:
			intIndex = -1;
			strOption[intIndex] = "";
			break;
	}
	switch (intIndex)
	{
		case 1:
			strOption[intIndex] = " ";
			break;
		case 2:
			strOption[intIndex] = to_string(intIndex - 1) + ") Select " + strCap + " Menu:";
			break;
		case 3:
			strOption[intIndex] = "--------------------";
			break;
		case 4:
			strOption[intIndex] = to_string(intIndex - 3) + ") Enter known serial number of a " + strLow;
			break;
		case 5:
			strOption[intIndex] = to_string(intIndex - 3) + ") Show " + strLow + " list";
			break;
		case 6:
			strOption[intIndex] = to_string(intIndex - 3) + ") Show full HR list";
			break;
		case 7:
			strOption[intIndex] = to_string(intIndex - 3) + ") Show HR database statistics";
			break;
		case 8:
			strOption[intIndex] = " ";
			break;
		case 9:
			strOption[intIndex] = to_string(intIndex) + ") Back to previous menu";
			break;
		case 0:
			strOption[intIndex] = to_string(intIndex) + ") Back to main menu";
			break;
		default:
			strOption[intIndex] = "";
			break;
	}
};

bool myMenu::mnuActSelect()
{
	bool blRetVal = false;
	switch (getSelection())
	{
	case 1: // Enter known Serial Number
		lngCSerial = getSerial();
		if (getCSerial() == -1)
		{
			intMenuSelection = getCSerial();
		}
		else
		{
			switch (getMenuStatus())
			{
			case 2:
			case 11:
				getData();
				chrCreatePerson = 'E';
				break;
			case 4:
			case 12:
				getData(false, true);
				chrCreatePerson = 'C';
				break;
			default:
				break;
			}
		}
		break;
	case 2: // Show employee list
		switch (getMenuStatus())
		{
		case 2:
		case 11:
			blRetVal = mnuShow('e');
			break;
		case 4:
		case 12:
			blRetVal = mnuShow('c');
			break;
		default:
			break;
		}
		break;
	case 3: // Show full HR list
		blRetVal = mnuShow();
		break;
	case 4: // Show HR database statistics
		blRetVal = mnuShowStats();
		break;
	case 9: // Back to previous menu
		switch (getMenuStatus())
		{
		case 2:
		case 4:
			intMenuStatus--;
			break;
		case 11:
		case 13:
		case 15:
			intMenuStatus = 5;
				break;
		case 12:
		case 14:
		case 16:
			intMenuStatus = 6;
			break;
		default:
			break;
		}
		break;
	case 0: // Back to main menu
		intMenuStatus = 0;
		break;
	default:
		break;
	}
	return blRetVal;
};

void myMenu::mnuInitAdd(int intIndex)
{
	string strCap = NULL;
	string strLow = NULL;
	switch (getMenuStatus())
	{
		case 1:
			strCap = "Employee";
			strLow = "employee";
			break;
		case 3:
			strCap = "Candidate";
			strLow = "candidate";
			break;
		default:
			intIndex = -1;
			strOption[intIndex] = "";
			return;
	}
	switch (intIndex)
	{
		case 1:
			strOption[intIndex] = " ";
			break;
		case 2:
			strOption[intIndex] = to_string(intIndex - 1) + ") Add " + strCap + " Menu:";
			break;
		case 3:
			strOption[intIndex] = "--------------------";
			break;
		case 4:
			strOption[intIndex] = to_string(intIndex - 3) + ") Add 'empty' " + strLow;
			break;
		case 5:
			strOption[intIndex] = to_string(intIndex - 3) + ") Add " + strLow + " with initialization data";
			break;
		case 6:
			strOption[intIndex] = to_string(intIndex - 3) + ") Select " + strLow + " to copy";
			break;
		case 7:
			strOption[intIndex] = to_string(intIndex - 3) + ") Show full HR list";
			break;
		case 8:
			strOption[intIndex] = to_string(intIndex - 3) + ") Show HR database statistics";
			break;
		case 9:
			strOption[intIndex] = " ";
			break;
		case 0:
			strOption[intIndex] = to_string(intIndex) + ") Back to main menu";
			break;
		default:
			strOption[intIndex] = "";
			break;
	}
};

bool myMenu::mnuActAdd()
{
	bool blRetVal = false;
	switch (getSelection())
	{
	case 1: // Add 'empty' employee
		switch (getMenuStatus())
		{
		case 1:
			chrCreatePerson = 'e';
			break;
		case 3:
			chrCreatePerson = 'c';
			break;
		default:
			break;
		}
		break;
	case 2: // Add employee with initialization data
		switch (getMenuStatus())
		{
		case 1:
			chrCreatePerson = 'E';
			break;
		case 3:
			chrCreatePerson = 'C';
			break;
		default:
			break;
		}
		break;
	case 3: // Select employee to copy
		switch (getMenuStatus())
		{
		case 1:
			intMenuStatus = 2;
			break;
		case 3:
			intMenuStatus = 4;
			break;
		default:
			break;
		}
		break;
	case 4: // Show full HR list
		blRetVal = mnuShow();
		break;
	case 5: // Show HR database statistics
		blRetVal = mnuShowStats();
		break;
	case 0: // Back to main menu
		intMenuStatus = 0;
		break;
	default:
		break;
	}
	return blRetVal;
};

bool myMenu::mnuShow()
{
	system("cls");
	pplList->show();
	return true;
};

bool myMenu::mnuShow(char chrType)
{
	system("cls");
	pplList->show(chrType);
	return true;
};

bool myMenu::mnuShowStats()
{
	cout << pplList << endl;
	return true;
};

long myMenu::getSerial()
{
	long lngRetVal = NULL;
	cout << endl << "Please type the Serial and then type <enter>\\<return>: ";
	cin >> lngRetVal;
	while (lngRetVal <= 0 || lngRetVal == NULL || cin.fail())
	{
		// if not a numeric character or string
		// clear the failure and pull off the non-numeric character or string
		if (cin.fail())
		{
			cin.clear();
			string  strErr;
			cin >> strErr;
			if (isExit(strErr))
			{
				lngRetVal = -1;
				break;
			}
		}
		cout << "Invalid choice, try again:";
		cin >> lngRetVal;
	}
	return lngRetVal;
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
	return lngCSalary;
};

long myMenu::getCSerial()
{
	return lngCSerial;
};

void myMenu::getData(bool blFromUser, bool blCandidate)
{
	if (blFromUser)
	{
		string strTemp = NULL;
		if (blCandidate)
		{
			strTemp = "candidate";
		}
		else
		{
			strTemp = "employee";
		}
		cout << endl << "Please type the " + strTemp + " name and then <enter>\\<return>: ";
		strName = "";
		cin >> strName;
		if (isExit(strName))
		{
			return;
		}
		cout << endl << "The name entered is " + getCName() + "." << endl << endl
			<< "Is the " + strTemp + " active? (y/n and then <enter>\\<return>): ";
		string strTmp = NULL;
		cin >> strTmp;
		while (strTmp.front() != 'y' && strTmp.front() != 'Y' &&
			strTmp.front() != 'n' && strTmp.front() != 'N')
		{
			if (isExit(strTmp))
			{
				return;
			}
			cout << endl << "Invalid choice (y/n), try again: ";
			cin >> strTmp;
		}
		blActive = strTmp.front() == 'y' || strTmp.front() == 'Y';
		if (blActive)
		{
			strTmp = "active";
		}
		else
		{
			strTmp = "inactive";
		}
		cout << endl << getCName() + " is " + strTmp + "." << endl << endl
			<< "What is the " + strTemp + "'s discussed employment type?" << endl
			<< "(G)lobal/(H)ourly/(T)emporary and then <enter>\\<return>): ";
		cin >> strTmp;
		while (strTmp.front() != 'g' && strTmp.front() != 'G' &&
			strTmp.front() != 'h' && strTmp.front() != 'H' &&
			strTmp.front() != 't' && strTmp.front() != 'T')
		{
			if (isExit(strTmp))
			{
				return;
			}
			cout << endl << "Invalid choice (g/h/t), try again: ";
			cin >> strTmp;
		}
		transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);
		chrType = strTmp.front();
		if (blActive)
		{
			strTmp = "active";
		}
		else
		{
			strTmp = "inactive";
		}
		switch (getCStatus())
		{
			case 'g':
				strTmp = strTmp + " global ";
			case 'h':
				strTmp = strTmp + " hourly ";
			case 't':
				strTmp = strTmp + " temporary ";
			default:
			{
				cout << "Bad type getting input from user." << endl << "Restart and contact author." << endl;
				intMenuSelection = -1;
				return;
			}
				break;
		}
		cout << endl << getCName() + " is an " + strTmp + strTemp + "." << endl << endl;
		if (blCandidate)
		{
			cout << "What is the " + strTemp + "'s current status?" << endl
				<< "(C)andidate/(R)esume/(I)nterview/(P)assed: ";
			cin >> strTmp;
			while (strTmp.front() != 'c' && strTmp.front() != 'C' &&
				strTmp.front() != 'r' && strTmp.front() != 'R' &&
				strTmp.front() != 'i' && strTmp.front() != 'I' &&
				strTmp.front() != 'p' && strTmp.front() != 'P')
			{
				if (isExit(strTmp))
				{
					return;
				}
				cout << endl << "Invalid choice (c/r/i/p), try again: ";
				cin >> strTmp;
			}
			transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);
			chrStatus = strTmp.front();
			switch (getCStatus())
			{
			case 'c':
				strTmp = strTemp;
				break;
			case 'r':
				strTmp = "resume";
				break;
			case 'i':
				strTmp = "interview";
				break;
			case 'p':
				strTmp = "passed";
			default:
				break;
			}
			cout << "The selected status for " + strName + " is '" + strTmp + "'." << endl << endl
				<< "Does the " + strTemp + " fit the position? (y/n and then <enter>\\<return>):";
			cin >> strTmp;
			while (strTmp.front() != 'y' && strTmp.front() != 'Y' &&
				strTmp.front() != 'n' && strTmp.front() != 'N')
			{
				if (isExit(strTmp))
				{
					return;
				}
				cout << endl << "Invalid choice (y/n), try again: ";
				cin >> strTmp;
			}
			blFits = strTmp.front() == 'y' || strTmp.front() == 'Y';
		}
		else
		{
			cout << "What is the " + strTemp + "'s discussed salary?" << endl
				<< "(type in NIS and then <enter>\\<return>): ";
			cin >> lngCSalary;
			while (lngCSalary <= 0 || lngCSalary == NULL || cin.fail())
			{
				cin.clear();
				cin >> strTmp;
				if (isExit(strTmp))
				{
					return;
				}
				cout << endl << "Invalid choice (integers only), try again: ";
				cin >> lngCSalary;
			}
		}
	}
	else
	{
		int intIndex = pplList->getIndex(getCSerial());
		strName = pplList->getCName(intIndex);
		blActive = pplList->getCActive(intIndex);
		chrType = pplList->getCType(intIndex);
		lngCSalary = pplList->getSerialSalary(intIndex);
		chrStatus = pplList->getCStatus(intIndex);
		blFits = pplList->getCFit(intIndex);
	}
};

char myMenu::getCStatus()
{
	return chrStatus;
};

bool myMenu::getCFit()
{
	return blFits;
};

bool myMenu::isExit(string strInput)
{
	transform(strInput.begin(), strInput.end(), strInput.begin(), ::tolower);
	bool blRetVal = strInput == "x" || strInput == "q" || strInput == "exit" || strInput == "quit";
	if (blRetVal)
	{
		intMenuSelection = -1;
	}
	return blRetVal;
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
