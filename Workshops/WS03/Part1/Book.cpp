/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 22 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include"Book.h"
#include<iostream>
using namespace std;

namespace sdds
{
	void Book::set(const char* bookTitle, int b_SKU, int daysOnLoan)
	{
		if (bookTitle != nullptr && bookTitle[0] != 0 && b_SKU > 0 && daysOnLoan > 0)
		{
			strcpy(m_title, bookTitle);
			m_SKU = b_SKU;
			m_daysOnLoan = daysOnLoan;

		}
		else
		{
			setEmpty();
		}
	}

	bool Book::isEmpty()const
	{
		return (m_title[0] == 0);

	}

	bool Book::hasPenalty()const
	{
		return m_daysOnLoan > MAXLOAN;
	}
	void Book::setEmpty()
	{
		strcpy(m_title, "");
		m_SKU = 0;
		m_daysOnLoan = 0;

	}

	bool Book::subTitle(const char* substrInTitle)
	{
		return (strstr(m_title, substrInTitle)) ? true : false;
	}

	void Book::display()const
	{
		if (!isEmpty())
		{
			
			cout.width(49);
			cout.setf(ios::left);
			cout << m_title;

			cout.width(8);
			cout << m_SKU;
			cout.width(10);
			cout << m_daysOnLoan;
			if (hasPenalty())
			{
				double totalPenalty = penalty();
				cout.unsetf(ios::left);
				

				cout.width(7);
				
				cout.precision(2);
				
				cout << totalPenalty;
			
            }
			
			
			cout << endl;
		}
		else
		{
			cout << "Invalid Library book" << endl;
		}
	}

	double Book::penalty()const
	{
		double totalPenalty;
		int overdueDays;
		cout.setf(ios::left);
		overdueDays = m_daysOnLoan - MAXLOAN;
		totalPenalty = overdueDays * PENALTY;

		return totalPenalty;
	}
};
	