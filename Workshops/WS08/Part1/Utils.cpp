/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "Utils.h"
namespace sdds
{
	void Utils::copyCString(char*& des, const char* src)
	{
		delete[] des;
		des = new char[strlen(src) + 1];
		strcpy(des, src);
	}
	const char* Utils::getCStringDynamically(std::istream& fromKeyboard, int memoryAllocated)
	{
		bool notoutOfMemory;
		int addedMemory = memoryAllocated;
		char* readLabel = new char[memoryAllocated];
		char* pointerPosition = readLabel;

		do
		{
			fromKeyboard.getline(pointerPosition, memoryAllocated, ',');
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
			}
		} while (!notoutOfMemory);
		return readLabel;
	}
}
