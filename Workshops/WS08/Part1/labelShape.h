/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNIGS
#ifndef SDDS_LABELSHAPE_H
#define SDDS_LABELSHAPE_H

#include "baseShape.h"
namespace sdds
{
	class labelShape : public baseShape 
	{
		char* m_label{};
	protected:
		const char* label()const;
	public:
		labelShape();
		labelShape(const char* label);
		~labelShape();
		labelShape(const labelShape& labelShape) = delete;
		labelShape& operator=(const labelShape& labelShape) = delete;
		void readShape(std::istream& fromKeyboard);
		void copyCString(char*& des, const char* src);
	    const char* getCStringDynamically(std::istream& fromKeyboard, int memoryAllocated);
	};
}

#endif