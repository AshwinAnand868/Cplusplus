/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 15 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sdds
{
	Contact::Contact()
	{
		m_area = m_exchangeCode= m_number = 0;
	}

	Contact::Contact(const char* name, int areaCode, int exchangeCode, int numberPart)
	{
		
		set(name, areaCode, exchangeCode, numberPart);

	}
	Contact::Contact(const Contact& cnt)
	{
		if (cnt)
		{
			set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
		}
	}

	Contact& Contact::operator=(const Contact& cnt)
	{
		if (this != &cnt)
		{
			set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
		}
		return *this;
	}

	ostream& Contact::print(ostream& ostr, bool toFile) const
	{
		if (*this)
		{
			if (toFile)
			{
				ostr << m_name << ',';
				printPhoneNumber(ostr);
			}
			else
			{
				
				ostr.width(50);
				ostr.fill('.');

				ostr.setf(ios::left);
				ostr << m_name;
				
				ostr.unsetf(ios::left);
				printPhoneNumber(ostr);
				

			}
		}
		return ostr;
		
	}

	Contact::~Contact()
	{
		delete[] m_name;
	}

	istream& Contact::read(istream& istr)
	{
		char name[MaxNameLength] = { '\0' };
		int areaCode = 0, exchangeCode = 0, numberPart = 0;
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		if (name == nullptr)  
			istr.setstate(ios::failbit);
		extractChar(istr, '(');
		istr >> areaCode;
		if(areaCode <= 100 && areaCode >= 999)  
			istr.setstate(ios::failbit);
		extractChar(istr, ')');
		extractChar(istr, ' ');
		istr >> exchangeCode;
		if (exchangeCode <= 100 && exchangeCode >= 999)  
			istr.setstate(ios::failbit);

		extractChar(istr, '-');
		istr >> numberPart;
		if (numberPart <= 0 && numberPart >= 9999) 
			istr.setstate(ios::failbit);

		extractChar(istr, '\n');

		if (istr)
			set(name, areaCode, exchangeCode, numberPart);

		
		
		return istr;
	}


	bool Contact::validPhone(int areaCode, int exchangeCode, int number)const
	{
		bool checkValid;

		checkValid = areaCode >= 100 && areaCode <= 999 && exchangeCode >= 100 && exchangeCode <= 999 && number >= 0 && number <= 9999;

		return checkValid;
    	}
	
	bool Contact::validCntName(const char* name)const
	{
	        return name != nullptr && name[0] != '\0';
	}

	void Contact::setEmpty()
	{
		m_name = nullptr;
	}

	void Contact::allocateAndCopy(const char* name)
	{
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);

	}

	void Contact::extractChar(istream& istr, char ch) const
	{
		//cout << istr.peek();
		if (istr.peek() == ch)
			istr.get();
		else
			istr.setstate(ios::failbit);
    }

	ostream& Contact::printPhoneNumber(ostream& ostr)const
	{
		ostr << '('  << m_area << ')' << ' ' << m_exchangeCode << '-';
		ostr.setf(ios::right);
		ostr.width(4);
		ostr.fill('0');
		ostr << m_number;
		ostr.unsetf(ios::right);
		return ostr;

	}
	Contact::operator bool()const
	{
		return m_name != nullptr;
	}
	void Contact::set(const char* name, int areaCode, int exchangeCode, int number)
	{
		

		if (validPhone(areaCode, exchangeCode, number) && validCntName(name))
		{
			allocateAndCopy(name);
			m_area = areaCode;
			m_exchangeCode = exchangeCode;
			m_number = number;
		}
		else
		{
			delete[] m_name;
			setEmpty();
		}

	}	

	
	ostream& operator<<(ostream& ostr,Contact& cnt)
	{
		if (cnt)
		{
			cnt.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Phone Record";
		}
		return ostr;
	}

	istream& operator>>(istream& istr, Contact& cnt)
	{
		cnt.read(istr);
		return istr;
	}

}
