/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 25 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include"Contact.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	Contact::Contact(){}

	Contact::Contact(const Contact& contact)
	{
		*this = contact;
	}

	Contact& Contact::operator=(const Contact& contact)
	{
		if (this != &contact)
		{
			Person::operator=(contact);
			strCpy(m_province, contact.m_province);
			strCpy(m_postalCode, contact.m_postalCode);
			delAlloCopy(m_address, contact.m_address);
			delAlloCopy(m_city, contact.m_city);
		}
		return *this;
	}

	Contact::~Contact()
	{
		~*this;
	}



	std::istream& Contact::read(std::istream& istr)
	{
		~*this;
		Person::read(istr);
		m_address = dynRead(istr, ',');
		m_city = dynRead(istr, ',');
		istr.getline(m_province, provCodeSize + 1, ',');
		if (!istr)
			~*this;
		istr.getline(m_postalCode, postalCodeSize + 1, '\n');
		if (istr.fail())
			~*this;
		return istr;
	}

	std::ostream& Contact::write(std::ostream& ostr) const
	{
		int i;
		if (*this)
		{
			Person::write(ostr);
			ostr << endl;
			ostr << m_address << endl;
			ostr << m_city << " " << m_province << endl;
			for (i = 0; i < postalCodeSize; i++)
				i == 3 ? ostr << " " << m_postalCode[i] : ostr << m_postalCode[i];
			ostr << endl;
		}
		return ostr;
	}

	Contact::operator bool() const
	{
		return (m_address && m_address[0] && m_city && m_city[0] && m_province && m_province[0] && m_postalCode && m_postalCode[0]);
	}

	void Contact::operator~()
	{
		Person::operator~();
		delete[] m_address;
		delete[] m_city;
		m_address = m_city = nullptr;
	}


}