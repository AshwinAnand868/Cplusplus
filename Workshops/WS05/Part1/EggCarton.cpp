/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 15 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds
{


	void EggCarton::setBroken()
	{
		m_size = -1;
		m_noOfEggs = -1;
	}


	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
	{
		if (size % 6 == 0 && size >= 6 and size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
		{
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumbo = jumboSize;
		}
		else
		{
			setBroken();
		}
	}

	EggCarton::operator bool() const
	{
		return m_size > 0 ? true : false;
	}

	istream& EggCarton::read(istream& istr)
	{
		char jumbo = '\0';
		bool jumboFlag;
		int noOfEggs, size;
		istr >> jumbo;
		if (jumbo == 'j')
		{
			jumboFlag = true;
		}
		else
		{
			jumboFlag = false;
		}
		istr.ignore();

		istr >> size;
		istr.ignore();

		istr >> noOfEggs;
		istr.ignore();

		if (size % 6 == 0 && size >= 6 and size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
		{
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumbo = jumboFlag;
		}
		else
		{
			setBroken();
		}
		
		return istr;
	}

	ostream& EggCarton::display(ostream& ostr) const
	{
		// displays an Egg Carton
		if (*this)
		{
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++)
			{
				cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}
		else
		{
			cout << "Broken Egg Carton!" << endl;
		}

		return ostr;
	}


	EggCarton::operator int() const
	{
		if (*this)
		{
			return m_noOfEggs;
		}
		return -1;
	}
	EggCarton::operator double() const
	{
		double totalWeight = 0.0;
		if (*this)
		{
			if (m_jumbo)
			{                              
				totalWeight = ((double)JumboEggWieght * (double)m_noOfEggs) / 1000.0;

			}
			else
			{
				totalWeight = ((double)RegularEggWieght * (double)m_noOfEggs) / 1000.0;

			}
			return totalWeight;
		}
		return -1.0;
	}

	EggCarton& EggCarton::operator--()
	{
		if (*this && m_noOfEggs > 0)
		{
			m_noOfEggs--;
		}
		return *this;
	}

	EggCarton& EggCarton::operator++()
	{
		if (*this)
		{
			m_noOfEggs++;
			if (m_noOfEggs > m_size)
			{
				setBroken();
			}

		}
		return *this;
	}

	EggCarton EggCarton::operator--(int)
	{
		EggCarton eggCarton = *this;
		--(*this);
		return eggCarton;
	}

	EggCarton EggCarton::operator++(int)
	{
		EggCarton eggCarton = *this;
		++(*this);
		return eggCarton;
	}

	EggCarton& EggCarton::operator=(int value)
	{
		m_noOfEggs = value;
		if (m_noOfEggs > m_size)
		{
			setBroken();
		}
		return *this;
	}

	EggCarton& EggCarton::operator+=(int value)
	{
		if (*this)
		{
			m_noOfEggs += value;
		}
		if (m_noOfEggs > m_size)
		{
			setBroken();
		}
		return *this;
	}

	EggCarton& EggCarton::operator+=(EggCarton& right)
	{
		if (*this)
		{
			while ((*this).m_noOfEggs < m_size)
			{

				(*this).m_noOfEggs++; // 5, 6
				right.m_noOfEggs--; // 4, 3
			}

		}
		return *this;
	}

	bool EggCarton::operator==(const EggCarton& right)const
	{
		bool valid;
		double currentCartonWght = *this;
		double rightCartonWght = right;
		double difference = currentCartonWght - rightCartonWght;

		valid = (difference > -0.001 && difference < 0.001) ? true : false;
		return valid;
	}

	int operator+(int left, const EggCarton& right)
	{
		int localRight;
		if (right)
		{
			localRight = right;
			return (left + localRight);
		}
		else
		{
			return left;
		}
	}


	ostream& operator<<(ostream& ostr, const EggCarton& right)
	{
		right.display(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, EggCarton& right)
	{
		right.read(istr);
		return istr;
	}
}