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
		bool blPart = getMenuStatus() == 11 || getMenuStatus() == 12;
		int intGetSelection = getSelection();
		if ((blPart && intGetSelection == 1) || !blPart) //name
		{
			cout << "\nPlease type the " + strTemp + " name and then <enter>\\<return>: ";
			strName = "";
			cin >> strName;
			if (isExit(strName) || (blPart && intGetSelection == 1))
			{
				return;
			}
		}
		if (!blPart)
		{
			cout << "\nThe name entered is " + getCName() + ".\n\n";
		}
		string strTmp = NULL;
		if ((blPart && intGetSelection == 2) || !blPart) //active
		{
			cout << "Is the " + strTemp + " active? (y/n and then <enter>\\<return>): ";
			cin >> strTmp;
			while (strTmp.front() != 'y' && strTmp.front() != 'Y' &&
				strTmp.front() != 'n' && strTmp.front() != 'N')
			{
				if (isExit(strTmp))
				{
					return;
				}
				cout << "\nInvalid choice (y/n), try again: ";
				cin >> strTmp;
			}
			blActive = strTmp.front() == 'y' || strTmp.front() == 'Y';
			if (blPart)
			{
				return;
			}
		}
		if (!blPart)
		{
			if (blActive)
			{
				strTmp = "active";
			}
			else
			{
				strTmp = "inactive";
			}
			cout << endl << getCName() + " is " + strTmp + ".\n\n";
		}
		if ((blPart && intGetSelection == 3) || !blPart) //type
		{
			cout << "What is the " + strTemp + "'s discussed employment type?\n"
				+ "(G)lobal/(H)ourly/(T)emporary and then <enter>\\<return>): ";
			cin >> strTmp;
			while (strTmp.front() != 'g' && strTmp.front() != 'G' &&
				strTmp.front() != 'h' && strTmp.front() != 'H' &&
				strTmp.front() != 't' && strTmp.front() != 'T')
			{
				if (isExit(strTmp))
				{
					return;
				}
				cout << "\nInvalid choice (g/h/t), try again: ";
				cin >> strTmp;
			}
			transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);
			chrType = strTmp.front();
			if (blPart)
			{
				return;
			}
		}
		if (!blPart)
		{
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
					   cout << "Bad type getting input from user." << endl << "Restart and contact author.\n";
					   intMenuSelection = -1;
					   return;
			}
				break;
			}
			cout << endl << getCName() + " is an " + strTmp + strTemp + ".\n\n";
		}
		else
		{
			switch (intGetSelection)
			{
			case 4: // salary
				blCandidate = false;
			case 5: // status
			case 6: // fits
				blCandidate = true;
			default:
				break;
			}
		}
		if (blCandidate)
		{
			if ((blPart && intGetSelection == 5) || !blPart) //status
			{
				cout << "What is the " + strTemp + "'s current status?\n"
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
					cout << "\nInvalid choice (c/r/i/p), try again: ";
					cin >> strTmp;
				}
				transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);
				chrStatus = strTmp.front();
				if (blPart)
				{
					return;
				}
			}
			if (!blPart)
			{
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
				cout << "The selected status for " + strName + " is '" + strTmp + "'.\n\n";
			}
			if ((blPart && intGetSelection == 5) || !blPart)
			{
				cout << "Does the " + strTemp + " fit the position? (y/n and then <enter>\\<return>):";
				cin >> strTmp;
				while (strTmp.front() != 'y' && strTmp.front() != 'Y' &&
					strTmp.front() != 'n' && strTmp.front() != 'N')
				{
					if (isExit(strTmp))
					{
						return;
					}
					cout << "\nInvalid choice (y/n), try again: ";
					cin >> strTmp;
				}
				blFits = strTmp.front() == 'y' || strTmp.front() == 'Y';
			}
		}
		else
		{
			cout << "What is the " + strTemp + "'s discussed salary?\n"
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

void myMenu::mnuInitSelect(int intIndex)
{
	string strCapitalType = NULL;
	string strLowercaseType = NULL;
	string strCapitalAction = NULL;
	string strLowercaseAction = NULL;
	char chrN = NULL;
	switch (getMenuStatus())
	{
		case 2: // Select Employee to Copy Menu
		case 4: // Select Candidate to Copy Menu
			strCapitalAction = "Copy";
			strLowercaseAction = "copy";
			break;
		case 5: // Select Employee to Change Menu
		case 6: // Select Candidate to Change Menu
			strCapitalAction = "Change";
			strLowercaseAction = "change";
			break;
		case 7: // Select Employee to Remove Menu
		case 8: // Select Candidate to Remove Menu
			strCapitalAction = "Remove";
			strLowercaseAction = "remove";
			break;
		case 9: // Select Employee to Show Menu
		case 10: // Select Candidate to Show Menu
			strCapitalAction = "Show";
			strLowercaseAction = "show";
			break;
		default:
			intIndex = -1;
			break;
	}
	switch (getMenuStatus())
	{
	case 2: // Select Employee to Copy Menu
	case 5: // Select Employee to Change Menu
	case 7: // Select Employee to Remove Menu
	case 9: // Select Employee to Show Menu
		strCapitalType = "Employee";
		strLowercaseType = "employee";
		chrN = 'n';
		break;
	case 4: // Select Candidate to Copy Menu
	case 6: // Select Candidate to Change Menu
	case 8: // Select Candidate to Remove Menu
	case 10: // Select Candidate to Show Menu
		strCapitalType = "Candidate";
		strLowercaseType = "candidate";
		chrN = '\0';
		break;
	default:
		intIndex = -1;
		break;
	}
	switch (intIndex)
	{
		case 1:
			strOption[intIndex] = " ";
			break;
		case 2:
			strOption[intIndex] = to_string(intIndex - 1) + ") Select " + strCapitalType + " to " + strCapitalAction + " Menu:";
			break;
		case 3:
			strOption[intIndex] = "--------------------";
			break;
		case 4:
			strOption[intIndex] = to_string(intIndex - 3) + ") Enter known serial number of a" + chrN + ' ' + strLowercaseType + " to " + strLowercaseAction;
			break;
		case 5:
			strOption[intIndex] = to_string(intIndex - 3) + ") Show " + strLowercaseType + " list";
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
			case 2: // Get selected Employee to copy
				getData();
				chrCreatePerson = 'E';
				break;
			case 4: // Get selected Candidate to copy
				getData(false, true);
				chrCreatePerson = 'C';
				break;
			case 5: // Go to Change Employee Menu
			case 6: // Go to Change Candidate Menu
				// go to change menu
				break;
			case 7: // Remove selected Employee
			case 8: // Remove selected Candidate
				cout << "Deleting the following:" << endl;
				blRetVal = pplList->show(getCSerial());
				cout << endl << endl << "... ";
				pplList->remPerson(getCSerial());
				cout << "done." << endl;
				break;
			case 9: // Show selected Employee
			case 10: // Show selected Candidate
				blRetVal = pplList->show(getCSerial());
				break;
			default:
				break;
			}
		}
		break;
	case 2:
		switch (getMenuStatus())
		{
		case 2:
		case 5:
		case 7:
		case 9:
			blRetVal = mnuShow('e'); // Show employee list
			break;
		case 4:
		case 6:
		case 8:
		case 10:
			blRetVal = mnuShow('c'); // Show candidate list
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
		case 2: // Select Employee to Copy Menu -> Add Employee Menu
		case 4: // Select Candidate to Copy Menu -> Add Employee Menu
			intMenuStatus--;
			break;
		case 5: // Select Employee to Change Menu -> Back to main menu
		case 6: // Select Candidate to Change Menu -> Back to main menu
		case 7: // Select Employee to Remove Menu -> Back to main menu
		case 8: // Select Candidate to Remove Menu -> Back to main menu
		case 9: // Select Employee to Show Menu -> Back to main menu
		case 10: // Select Candidate to Show Menu -> Back to main menu
			intMenuStatus = 0;
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

void myMenu::mnuInitChange(int intIndex)
{
	string strCapitalType = NULL;
	string strLowercaseType = NULL;
	bool blIsCandidate = false;
	switch (getMenuStatus())
	{
	case 11: // Change Employee Menu
		strCapitalType = "Employee";
		strLowercaseType = "employee";
		getData();
		break;
	case 12: // Change Candidate Menu
		strCapitalType = "Candidate";
		strLowercaseType = "candidate";
		getData(false, true);
		blIsCandidate = true;
		break;
	default:
		intIndex = -1;
		break;
	}
	switch (intIndex)
	{
	case 1:
		strOption[intIndex] = '\n' + to_string(intIndex) + ") Change " + strCapitalType + " Menu:";
		break;
	case 2:
		strOption[intIndex] = "--------------------";
		break;
	case 3: //name
		strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " name (current: '" + getCName() + "'";
		break;
	case 4: //active
		strOption[intIndex] = "Active";
		if (!getCActive())
		{
			strOption[intIndex] = "Not " + strOption[intIndex];
		}
		strOption[intIndex] = to_string(intIndex - 2) + ") Change if " + strLowercaseType + " is active (currently: '" + strOption[intIndex] + "'";
		break;
	case 5: //type
		switch (getCType())
		{
		case 'g':
			strOption[intIndex] = "Global";
			break;
		case 'h':
			strOption[intIndex] = "Hourly";
			break;
		case 't':
			strOption[intIndex] = "Temporary";
			break;
		default:
			strOption[intIndex] = "";
			break;
		}
		if (strOption[intIndex] == "")
		{
			break;
		}
		strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " type (current: '" + strOption[intIndex] + "'";
		break;
	case 6: //salary
		strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " salary (current: '" + to_string(getCSalary()) + "'";
		break;
	case 7: //status
		switch (getCType())
		{
		case 'c':
			strOption[intIndex] = strCapitalType;
			break;
		case 'r':
			strOption[intIndex] = "Resume";
			break;
		case 'i':
			strOption[intIndex] = "Interview";
			break;
		case 'p':
			strOption[intIndex] = "Passed";
			break;
		default:
			strOption[intIndex] = "";
			break;
		}
		if (strOption[intIndex] == "")
		{
			break;
		}
		strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " type (current: '" + strOption[intIndex] + "'";
		if (!blIsCandidate)
		{
			strOption[intIndex] = " ";
		}
		break;
	case 8: //fit
		strOption[intIndex] = "Fits";
		if (!getCFit())
		{
			strOption[intIndex] = "Doesn't Fit";
		}
		strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " salary (current: '" + strOption[intIndex] + "'";
		if (!blIsCandidate)
		{
			strOption[intIndex] = " ";
		}
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

bool myMenu::mnuActChange()
{
	bool blRetVal = false;
	getData(true, getMenuStatus() == 12);
	switch (getSelection())
	{
	case 1: // name
		pplList->setCName(pplList->getIndex(getCSerial()), getCName());
		break;
	case 2: //active
		pplList->setCActive(pplList->getIndex(getCSerial()), getCActive());
		break;
	case 3: // type
		pplList->setCType(pplList->getIndex(getCSerial()), getCType());
		break;
	case 4: // salary
		pplList->setCSalary(pplList->getIndex(getCSerial()), getCSalary());
		break;
	case 5: // status
		pplList->setCStatus(pplList->getIndex(getCSerial()), getCStatus());
		break;
	case 6: // fit
		pplList->setCFit(pplList->getIndex(getCSerial()), getCFit());
		break;
	case 9: // Back to previous menu
		intMenuStatus = intMenuStatus / 2;
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

long myMenu::getCSerial()
{
	return lngCSerial;
};

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

char myMenu::getCStatus()
{
	return chrStatus;
};

bool myMenu::getCFit()
{
	return blFits;
};

int myMenu::getMenuStatus()
{
	return intMenuStatus;
};

char myMenu::getCreateType()
{
	return chrCreatePerson;
}

int myMenu::getSelection()
{
	return intMenuSelection;
};

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
			case 1:  // Add Employee Menu
			case 3:  // Add Candidate Menu
				mnuInitAdd(i);
				break;
			case 2:  // Select Employee to Copy Menu
			case 4:  // Select Candidate to Copy Menu
			case 5:  // Select Employee to Change Menu
			case 6:  // Select Candidate to Change Menu
			case 7:  // Select Employee to Remove Menu
			case 8:  // Select Candidate to Remove Menu
			case 9:  // Select Employee to Show Menu
			case 10: // Select Candidate to Show Menu
				mnuInitSelect(i);
				break;
			case 11: // Change Employee Menu
			case 12: // Change Candidate Menu
				mnuInitChange(i);
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
			cout << " Gil's HR database menu:\n-------------------------\n\n";
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
					intMenuStatus = 9;
					break;
				case 8: // Show Candidate
					intMenuStatus = 10;
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
		case 2:  // Select Employee to Copy Menu
		case 4:  // Select Candidate to Copy Menu
		case 5:  // Select Employee to Change Menu
		case 6:  // Select Candidate to Change Menu
		case 7:  // Select Employee to Remove Menu
		case 8:  // Select Candidate to Remove Menu
		case 9:  // Select Employee to Show Menu
		case 10: // Select Candidate to Show Menu
			blPause = mnuActSelect();
			break;
		case 11: // Change Employee Menu
		case 12: // Change Candidate Menu
			blPause = mnuActChange();
			break;
		default:
			break;
	}
	if (blPause)
	{
		cin.get();
	}
};


myMenu::myMenu()
{
	pplList = new People;
	for (int i = 0; i <= 9; i++)
	{
		strOption[i] = to_string(NULL);
	}
	intMenuStatus = 0;
	intMenuSelection = 0;
	this->mnuInit();
};

myMenu::~myMenu()
{
	delete pplList;
};
