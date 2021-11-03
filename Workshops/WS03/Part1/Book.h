/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 22 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOKS_H
#define SDDS_BOOKS_H
namespace sdds
{
	const int bookNameLength = 50;
	const double PENALTY = 1.5;
	const int MAXLOAN = 15;

	class Book
	{
		char m_title[bookNameLength + 1];
		int m_SKU;
		int m_daysOnLoan;

		void setEmpty();
		double penalty()const;
	public:
		void set(const char* bookTitle, int b_SKU, int daysOnLoan);
		bool isEmpty()const;
		bool hasPenalty()const;
		
		bool subTitle(const char* substrInTitle);
		void display()const;
		
	};


};

#endif // !SDDS_BOOKS_H



