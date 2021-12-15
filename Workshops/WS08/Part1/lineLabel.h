/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SDDS_LINELABEL_H
#define SDDS_LINELABEL_H
#include"labelShape.h"

namespace sdds
{
	class lineLabel : public labelShape
	{
		int m_length;
	public:
		lineLabel();
		lineLabel(const char* label, int length);
		void drawShape(std::ostream& toScreen)const;
		void readShape(std::istream& fromKeyboard);
	};
}
#endif
