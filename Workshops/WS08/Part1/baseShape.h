/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BASESHAPE_H
#define SDDS_BASESHAPE_H
#include<iostream>
#include"Utils.h"
namespace sdds
{
	class baseShape
	{
	public:
		virtual void drawShape(std::ostream& toScreen)const = 0;
		virtual void readShape(std::istream& fromKeyboard) = 0;
		virtual ~baseShape();
	};
	std::ostream& operator<<(std::ostream& toScreen, const baseShape& baseShape);

	std::istream& operator>>(std::istream& fromKeyboard, baseShape& baseShape);
}
#endif