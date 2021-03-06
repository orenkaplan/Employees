#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "myMenu.h"
#include "People.h"


using namespace std;


void myMenu::getData(bool blFromUser, bool blCandidate)
{
	strName = to_string(NULL);
	blActive = NULL;
	chrType = '\0';
	lngCSalary = -1;
	chrStatus = '\0';
	blFits = NULL;
	if (blFromUser)
	{ // Get info from user
		string strTemp = to_string(NULL);
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
		if ((blPart && intGetSelection == 1) || !blPart) // Get name
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
		string strTmp = to_string(NULL);
		if ((blPart && intGetSelection == 2) || !blPart) // Get active
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
		if ((blPart && intGetSelection == 3) || !blPart) // Get type
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
			switch (getCType())
			{
				case 'g':
					strTmp = strTmp + " global ";
					break;
				case 'h':
					strTmp = strTmp + " hourly ";
					break;
				case 't':
					strTmp = strTmp + " temporary ";
					break;
				default:
					cout << "Bad type getting input from user.\nRestart and contact author.\n";
					intMenuSelection = -1;
					return;
					break;
			}
			cout << endl << getCName() + " is an " + strTmp + strTemp + ".\n\n";
		}
		else
		{
			switch (intGetSelection)
			{
				case 4: // Get salary
					blCandidate = false;
					break;
				case 5: // Get status
				case 6: // Get fits
				case 9: // Back to main menu
					blCandidate = true;
					break;
				default:
					break;
			}
		}
		if (blCandidate)
		{
			if ((blPart && intGetSelection == 5) || !blPart) // Get status
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
			if ((blPart && intGetSelection == 5) || !blPart) // Get fitness
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
		else // Get salary
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
	{ // Copy data from existing user
		int intIndex = getIndex(getCSerial());
		if (intIndex != -1)
		{
			strName = pplList->getCName(intIndex);
			blActive = pplList->getCActive(intIndex);
			chrType = pplList->getCType(intIndex);
			lngCSalary = pplList->getSerialSalary(intIndex);
			chrStatus = pplList->getCStatus(intIndex);
			blFits = pplList->getCFit(intIndex);
		}
		else
		{
			cout << "No person recorded by that Serial Number.\nRestart and report to author.\n\n";
		}
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
	string strCap = to_string(NULL);
	string strLow = to_string(NULL);
	switch (getMenuStatus())
	{
		case 1: // Add employee
			strCap = "Employee";
			strLow = "employee";
			break;
		case 3: // Add candidate
			strCap = "Candidate";
			strLow = "candidate";
			break;
		default:
			intMenuSelection = -1;
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
		case 1: // Add 'empty' person
			switch (getMenuStatus())
			{
			case 1: // employee
				chrCreatePerson = 'e';
				break;
			case 3: // candidate
				chrCreatePerson = 'c';
				break;
			default:
				break;
			}
			break;
		case 2: // Add person with initialization data
			switch (getMenuStatus())
			{
			case 1: // employee
				chrCreatePerson = 'E';
				break;
			case 3: // candidate
				chrCreatePerson = 'C';
				break;
			default:
				break;
			}
			break;
		case 3: // Select person to copy
			switch (getMenuStatus())
			{
			case 1: // Select employee to copy menu
				intMenuStatus = 2;
				break;
			case 3: // Select candidate to copy menu
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
	string strCapitalType = to_string(NULL);
	string strLowercaseType = to_string(NULL);
	string strCapitalAction = to_string(NULL);
	string strLowercaseAction = to_string(NULL);
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
		case 9:
			strOption[intIndex] = " ";
			switch (getMenuStatus())
			{
				case 5:  // Select Employee to Change Menu
				case 6:  // Select Candidate to Change Menu
				case 7:  // Select Employee to Remove Menu
				case 8:  // Select Candidate to Remove Menu
				case 9:  // Select Employee to Show Menu
				case 10: // Select Candidate to Show Menu
					break;
				case 2:  // Select Employee to Copy Menu
				case 4:  // Select Candidate to Copy Menu
					if (intIndex == 9)
					{
						strOption[intIndex] = to_string(intIndex) + ") Back to previous menu";
					}
					break;
				default:
					break;
			}
			break;
		case 0:
			strOption[intIndex] = to_string(intIndex) + ") Back to main menu";
			break;
		default:
			intMenuSelection = -1;
			strOption[intIndex] = "";
			break;
	}
};

bool myMenu::mnuActSelect()
{
	bool blRetVal = false;
	int intIndex = -1;
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
						chrCreatePerson = 'E';
						break;
					case 4: // Get selected Candidate to copy
						chrCreatePerson = 'C';
						break;
					case 5: // Go to Change Employee Menu
						intMenuStatus = 11;
						break;
					case 6: // Go to Change Candidate Menu
						intMenuStatus = 12;
						break;
					case 7: // Remove selected Employee
					case 8: // Remove selected Candidate
						intIndex = getIndex(getCSerial());
						if (intIndex != -1)
						{
							cout << "Deleting the following:" << endl;
							blRetVal = mnuShow(getCSerial());
							cout << endl << endl << "... ";
							remPerson(intIndex, true);
							cout << "done." << endl;
						}
						else
						{
							cout << "No person recorded by that Serial Number.\nTry again.\n\n";
							blRetVal = true;
						}
						break;
					case 9: // Show selected Employee
					case 10: // Show selected Candidate
						blRetVal = mnuShow(getCSerial());
						break;
					default:
						break;
				}
			}
			break;
		case 2:
			switch (getMenuStatus())
			{
				case 2:  // Select Employee to Copy Menu
				case 5:  // Select Employee to Change Menu
				case 7:  // Select Employee to Remove Menu
				case 9:  // Select Employee to Show Menu
					blRetVal = mnuShow('e'); // Show employee list
					break;
				case 4:  // Select Candidate to Copy Menu
				case 6:  // Select Candidate to Change Menu
				case 8:  // Select Candidate to Remove Menu
				case 10: // Select Candidate to Show Menu
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
	string strCapitalType = to_string(NULL);
	string strLowercaseType = to_string(NULL);
	bool blIsCandidate = false;
	switch (getMenuStatus())
	{
		case 11: // Change Employee Menu
			strCapitalType = "Employee";
			strLowercaseType = "employee";
			break;
		case 12: // Change Candidate Menu
			strCapitalType = "Candidate";
			strLowercaseType = "candidate";
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
		case 3: // Change name option
			strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " name (current: '" + getCName() + "')";
			break;
		case 4: // Change active option
			strOption[intIndex] = "Active";
			if (!getCActive())
			{
				strOption[intIndex] = "Not " + strOption[intIndex];
			}
			strOption[intIndex] = to_string(intIndex - 2) + ") Change if " + strLowercaseType + " is active (currently: '" + strOption[intIndex] + "')";
			break;
		case 5: // Change type option
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
				case '\0':
					strOption[intIndex] = " ";
					break;
				default:
					strOption[intIndex] = "";
					break;
			}
			if (strOption[intIndex] == "")
			{
				break;
			}
			else if (strOption[intIndex] == " ")
			{
				strOption[intIndex] = "";
			}
			strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " type (current: '" + strOption[intIndex] + "')";
			break;
		case 6: // Change salary option
			strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " salary (current: '" + to_string(getCSalary()) + "')";
			break;
		case 7: // Change status option
			switch (getCStatus())
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
					if (blIsCandidate)
					{
						strOption[intIndex] = "";
					}
					else
					{
						strOption[intIndex] = "N/A";
					}
					break;
			}
			if (strOption[intIndex] == "")
			{
				break;
			}
			strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " type (current: '" + strOption[intIndex] + "')";
			if (!blIsCandidate)
			{
				strOption[intIndex] = " ";
			}
			break;
		case 8: // Change fit options
			strOption[intIndex] = "Fits";
			if (!getCFit())
			{
				strOption[intIndex] = "Doesn't Fit";
			}
			strOption[intIndex] = to_string(intIndex - 2) + ") Change " + strLowercaseType + " salary (current: '" + strOption[intIndex] + "')";
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
			intMenuSelection = -1;
			strOption[intIndex] = "";
			break;
	}
};

bool myMenu::mnuActChange()
{
	bool blRetVal = false;
	int intIndex = getIndex(getCSerial());
	if (intIndex != -1)
	{
		int intSelection = getSelection();
		if (intSelection > 0 || intSelection < 9) // Don't get if exiting menu
		{
			getData(true, getMenuStatus() == 12);
		}
		switch (intSelection)
		{
			case 1: // Change name
				pplList->setCName(intIndex, getCName());
				if (getCName() != "")
				{
					*pplList->blEmpty[intIndex] = false;
				}
				break;
			case 2: // Change active
				pplList->setCActive(intIndex, getCActive());
				break;
			case 3: // Change type
				pplList->setCType(intIndex, getCType());
				if (getCType() != '\0')
				{
					*pplList->blEmpty[intIndex] = false;
				}
				break;
			case 4: // Change salary
				pplList->setCSalary(intIndex, getCSalary());
				if (getCSalary() != -1)
				{
					*pplList->blEmpty[intIndex] = false;
				}
				break;
			case 5: // Change status
				pplList->setCStatus(intIndex, getCStatus());
				if (getCStatus() != '\0')
				{
					*pplList->blEmpty[intIndex] = false;
				}
				break;
			case 6: // Change fit
				pplList->setCFit(intIndex, getCFit());
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
		pplList->setLastTouched(intIndex);
	}
	else
	{
		cout << "No person recorded by that Serial Number.\nTry again.\n\n";
		blRetVal = true;
	}
	return blRetVal;
};

bool myMenu::mnuShow(char chrType)
{
	system("cls");
	pplList->show(chrType);
	return true;
};

bool myMenu::mnuShow(long lngExistingSerial)
{
	int intIndex = getIndex(lngExistingSerial);
	pplList->show(lngExistingSerial);
	if (intIndex != -1)
	{
		pplList->setLastTouched(intIndex);
	}
	return intIndex != -1;
};

bool myMenu::mnuShowStats()
{
	cout << *pplList << endl;
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

int myMenu::getListSize()
{
	return pplList->getSize();
};

void myMenu::mnuInit()
{
	switch (getMenuStatus())
	{
		case 11: // Change Employee Menu
			getData();
			break;
		case 12: // Change Candidate Menu
			getData(false, true);
			break;
		case 1:  // Add Employee Menu
		case 2:  // Select Employee to Copy Menu
		case 3:  // Add Candidate Menu
		case 4:  // Select Candidate to Copy Menu
		case 5:  // Select Employee to Change Menu
		case 6:  // Select Candidate to Change Menu
		case 7:  // Select Employee to Remove Menu
		case 8:  // Select Candidate to Remove Menu
		case 9:  // Select Employee to Show Menu
		case 10: // Select Candidate to Show Menu
		default:
			break;
	}
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
			intMenuSelection = -1;
			cout << "Bad Index when building menu.\nRestart and contact author." << endl;
			continue;
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
	strName = to_string(NULL);
	blActive = NULL;
	chrType = '\0';
	lngCSalary = -1;
	chrStatus = '\0';
	blFits = NULL;
	bool blPause = false;
	string strPause = to_string(NULL);
	switch (getMenuStatus())
	{
		case 0:
		{
			switch (getSelection())
			{
				case 1: // Add Employee
					lngCSerial = -1;
					intMenuStatus = 1;
					break;
				case 2: // Add Candidate
					lngCSerial = -1;
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
					break;
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
		system("pause");
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
	mnuInit();
};

myMenu::~myMenu()
{
	pplList->setLastInstance();
	delete pplList;
};
