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
#include "labelShape.h"
using namespace std;
namespace sdds
{
	const char* labelShape::label() const
	{
		return m_label;
	}

	labelShape::labelShape()
	{
		/*m_label = nullptr; no need to do this because it is already initialized to nullptr at the time of declaration in class definition*/
	}
	const char* labelShape::getCStringDynamically(std::istream& fromKeyboard, int memoryAllocated)
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
	void labelShape::copyCString(char*& des, const char* src)
	{
		delete[] des;
		des = new char[strlen(src) + 1];
		strcpy(des, src);
	}

	labelShape::labelShape(const char* label)
	{
		if (label && label[0])
		{
			copyCString(m_label, label);
		}
	}

	labelShape::~labelShape()
	{
		delete[] m_label;
		/*m_label = nullptr; 
		* no need to do this because labelShape object is already deleted
		*/
	}

	void labelShape::readShape(std::istream& fromKeyboard)
	{
		const int allocatedMemory = 64;
		const char* readLabel = getCStringDynamically(fromKeyboard, allocatedMemory); // done without string class. I learned doing this in one of my OOP classes.
		copyCString(m_label, readLabel);
		delete[] readLabel;
	}
}