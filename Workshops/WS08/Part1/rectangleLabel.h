/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SDDS_RECTANGLELABEL_H
#define SDDS_RECTANGLELABEL_H
#include "labelShape.h"

namespace sdds
{
	class rectangleLabel : public labelShape
	{
		int m_width;
		int m_spaces;
	public:
		rectangleLabel();
		rectangleLabel(const char* label, int width, int nSpaces);
		void readShape(std::istream& fromKeyboard);
		bool checkSafeEmpty()const;
		void drawShape(std::ostream& toScreen)const;
		void drawDashesAndPluses(std::ostream& toScreen)const;
		void writeLabelWithSpaces(std::ostream& toScreen)const;
	};
}
#endif