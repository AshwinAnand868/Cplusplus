/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 15 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
namespace sdds
{
	const int MaxNameLength = 55;
	class Contact
	{
		char* m_name{};
		int m_area;
		int m_exchangeCode;
		int m_number;

		bool validPhone(int areaCode, int exchangeCode, int number)const;
		bool validCntName(const char* name)const;
		void setEmpty(); // set to invalid empty state
		void allocateAndCopy(const char* name);
		void extractChar(std::istream& istr, char ch)const;
		std::ostream& printPhoneNumber(std::ostream& ostr)const;
		void set(const char* name, int areaCode, int exchangeCode, int number);
	public:
		Contact();
		Contact(const char* name, int areaCode, int exchangeCode, int numberPart);
		Contact(const Contact& cnt);
		Contact& operator=(const Contact& cnt);
		
		~Contact();
		operator bool()const;
		std::ostream& print(std::ostream& ostr, bool toFile = true) const;
		std::istream& read(std::istream& istr);
	};
	
	std::ostream& operator<<(std::ostream& ostr,Contact& cnt);
	std::istream& operator>>(std::istream& ostr,Contact& cnt);
}
#endif // !SDDS_CONTACT_H


