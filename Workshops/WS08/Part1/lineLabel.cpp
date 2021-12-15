/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include"lineLabel.h"
using namespace std;
namespace sdds
{
	lineLabel::lineLabel():labelShape()
	{
		m_length = 0;
	}
	lineLabel::lineLabel(const char* label, int length) : labelShape(label)
	{
		if(length != 0)
			m_length = length;
	}
	void lineLabel::readShape(std::istream& fromKeyboard)
	{
		labelShape::readShape(fromKeyboard);
		fromKeyboard >> m_length;
		fromKeyboard.ignore(10000, '\n'); // can be changed
	}

	void printEqualTo(int length, ostream& toScreen)
	{
		for (int i = 0; i < length; i++)
		{
			toScreen << "=";
		}
	}
	void lineLabel::drawShape(ostream& toScreen)const
	{
		if (m_length > 0 && labelShape::label())
		{
			toScreen << labelShape::label() << endl;
			printEqualTo(m_length, toScreen);
		}
	}

	
}