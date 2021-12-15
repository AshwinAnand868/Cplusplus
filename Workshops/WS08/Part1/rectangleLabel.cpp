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
#include"rectangleLabel.h"
using namespace std;

namespace sdds
{
	rectangleLabel::rectangleLabel():labelShape()
	{
		m_width = 0;
		m_spaces = 0;
	}
	rectangleLabel::rectangleLabel(const char* label, int width, int nSpaces):labelShape(label)
	{
		if (width <= nSpaces && strlen(label) >= (unsigned)width)
		{
			m_width = 0;
		}
		else
		{
			m_width = width;
			m_spaces = nSpaces;
		}
	}
	void rectangleLabel::readShape(std::istream& fromKeyboard)
	{
		labelShape::readShape(fromKeyboard);
		fromKeyboard >> m_width;
		fromKeyboard.get();
		fromKeyboard >> m_spaces;
		fromKeyboard.ignore(1000, '\n');
	}
	bool rectangleLabel::checkSafeEmpty()const
	{
		bool yesEmpty = false;
		if (m_width != 0)
		{
			yesEmpty = true;
		}
		return yesEmpty;
	}

	void rectangleLabel::drawDashesAndPluses(std::ostream& toScreen)const
	{
		toScreen << "+";
		toScreen.width(m_width - 2 + 1);
		toScreen.fill('-');
		toScreen << "+";
		toScreen.fill(' ');
	}

	void rectangleLabel::writeLabelWithSpaces(std::ostream& toScreen)const
	{
		toScreen << "|";
		for (int i = 0; i < m_spaces; i++)
			toScreen << " ";
		toScreen.width(m_width - m_spaces - 2);
		toScreen.setf(ios::left);
		toScreen << label();
		toScreen.unsetf(ios::left);
		toScreen << "|";
		toScreen << endl;
	}

	
	void rectangleLabel::drawShape(std::ostream& toScreen)const
	{
		bool checkEmpty = checkSafeEmpty();
		if (checkEmpty)
		{
			drawDashesAndPluses(toScreen);
			toScreen << endl;
			writeLabelWithSpaces(toScreen);
			drawDashesAndPluses(toScreen);
		}
	}


	

}
