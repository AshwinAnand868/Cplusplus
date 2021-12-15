/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 25 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include<iostream>
#include "Person.h"
namespace sdds
{
	const int provCodeSize = 2;
	const int postalCodeSize = 6;
	class Contact :public Person
	{
		char* m_address{};
		char* m_city{};
		char m_province[provCodeSize + 1]{ '\0' };
		char m_postalCode[postalCodeSize + 1]{ '\0' };
	public:
		Contact();
		Contact(const Contact& contact);
		Contact& operator=(const Contact& contact);
		~Contact();
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		operator bool()const;
		void operator~();
	};
}
#endif