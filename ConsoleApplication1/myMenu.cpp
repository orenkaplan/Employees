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
	}
}


myMenu::myMenu()
{
	pplList = new People;
	strOption = new string[9];
}


myMenu::~myMenu()
{
	delete strOption;
	delete pplList;
}
