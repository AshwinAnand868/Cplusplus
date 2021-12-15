/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date 9-11-2021
// Author - Ashwin Anand
// Description - Contains method which is used in the implementation of run and operator~ function defined in Menu.cpp file
//
// Revision History
// -----------------------------------------------------------
// Name            Date
//Ashwin Anand	  10-11-2021
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include<iostream>
#include "Utils.h"
#include"Menu.h"
using namespace std;
namespace sdds
{
	unsigned int Util::getInt(int min, int nItems)
	{
		int inputNo;
		bool validate = false;
		do
		{
			cin >> inputNo;

			if (inputNo >= min && inputNo <= nItems && cin)
				validate = true;
			else if (validate == false || !cin)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
			}

		} while (!validate);
		return (unsigned)inputNo;
	}
}