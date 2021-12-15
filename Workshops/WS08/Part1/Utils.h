/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include<iostream>
namespace sdds
{
	class Utils
	{
		Utils() = delete;
	public:
		static void copyCString(char*& des, const char* src);
		static const char* getCStringDynamically(std::istream& fromKeyboard, int memoryAllocated);
	};
}
#endif
