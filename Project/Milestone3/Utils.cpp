/*
Student Information
Final Project Milestone 3
Module : Util Module
Filename : Util.h
Version 1.0
Name	Ashwin Anand
Revision History
Date - 20-11-2021
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Utils.h"
using namespace std;


namespace sdds
{
	char* Utils::getCStringDynamically(std::istream& fromKeyboard, int memoryAllocated, char delimiter)
	{
		bool notoutOfMemory;
		int addedMemory = memoryAllocated;
		char* readLabel = new char[memoryAllocated];
		char* pointerPosition = readLabel;
		char* toBeReturned{};

		do
		{
			fromKeyboard.getline(pointerPosition, memoryAllocated,delimiter);
			notoutOfMemory = false;
			if (fromKeyboard)
			{
				notoutOfMemory = true;
			}
			else
			{
				char* newLabel = new char[memoryAllocated + addedMemory];
				strcpy(newLabel, readLabel);
				delete[] readLabel;
				readLabel = newLabel;
				pointerPosition = &readLabel[strlen(readLabel)];
				addedMemory += memoryAllocated;
				fromKeyboard.clear();
			}
		} while (!notoutOfMemory);
		toBeReturned = new char[strlen(readLabel) + 1];
		if (toBeReturned)
		{
			strcpy(toBeReturned, readLabel);
		}
		delete[] readLabel;
		return toBeReturned;
	}
}