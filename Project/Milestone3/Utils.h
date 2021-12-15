/*
Student Information
Final Project Milestone 3
Module : Util Module
Filename : Util.cpp
Version 1.0
Name	Ashwin Anand
Revision History
Date - 20-11-2021
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include<iostream>
#include<cstring>

namespace sdds
{
	class Utils
	{
	public:
		static char* getCStringDynamically(std::istream& fromKeyboard, int memoryAllocated, char delimiter);
	};
}
#endif // !SDDS_UTILS_H
