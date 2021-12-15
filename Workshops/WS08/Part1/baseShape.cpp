/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include"baseShape.h"

namespace sdds
{
	baseShape::~baseShape(){}

	std::ostream& operator<<(std::ostream& toScreen, const baseShape& baseShape)
	{
		baseShape.drawShape(toScreen);
		return toScreen;
	}

	std::istream& operator>>(std::istream& fromKeyboard, baseShape& baseShape)
	{
		baseShape.readShape(fromKeyboard);
		return fromKeyboard;
	}

}