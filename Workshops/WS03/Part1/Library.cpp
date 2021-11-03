/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 22 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include"Library.h"
#include "Book.h"
using namespace std;
namespace sdds
{
	void Library::setEmpty()
	{
		strcpy(m_name, "");
		m_books = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;

	}

	void filler(char fillValue)
	{
		for (int i = 0; i < 78; i++)
		{
			cout << fillValue;
		}
		cout << endl;
	}

	bool Library::isEmpty()const
	{
		
		return (m_name[0] == 0);
		
	}

	void Library::header(const char* title)const
	{
		
		filler('-');
		//cout << endl;

		cout << "*****  " << m_name  << "  *****" << endl;

		cout << title << endl;

		filler('-');
		

		cout << "Row Book title                                       SKU     loan days penalty" << endl << "--- ------------------------------------------------ ------- --------- -------" << endl;
    }
	

	void Library::footer()const
	{
		filler('-');
	}

	void Library::initialize(const char* name, int noOfBooks)
	{
		if (name != nullptr && name[0] != 0 && noOfBooks > 0)
		{
			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;

			
			m_books = new Book[noOfBooks];
             
			



			m_addedBooks = 0;


		}
		else
		{
			setEmpty();
		}
	}

	bool Library::addBook(const char* book_title, int sku, int loadDays)
	{
		
		if (m_addedBooks < m_sizeOfBooksArray)
		{
			m_books[m_addedBooks].set(book_title, sku, loadDays);
			if (!m_books[m_addedBooks].isEmpty())
			{
				m_addedBooks++;
				return true;
			}
		}
		return false;
	}

	void Library::clear()
	{
		cout.precision(6);
		delete[] m_books;
		m_books = nullptr;
    }

	void Library::display(const char* substr)
	{

		
		int rowNo = 1, i;
		
		bool searchFlag = false;
		if (!isEmpty())
		{
			
		    cout << ">>> Searching for: \"" << substr << "\" <<<" << endl;
			
			header("Substring search");
			
			for (i = 0; i < m_addedBooks; i++)
			{
				if (m_books[i].subTitle(substr))
				{
					cout.width(4);
					cout.setf(ios::left);
					cout << rowNo;
					cout.unsetf(ios::left);
					rowNo++;
					m_books[i].display();
					searchFlag = true;

				}
			}
				if(searchFlag == false)
				{
					cout << "No book title contains \"" << substr << "\"" << endl;

					
				}
			
			footer();
			
		}
		else
		{
			cout << "Invalid Library" << endl;

		}
	}

	void Library::display(bool overdueOnly)const
	{
		int rowNo = 1;
		int flag = 0;

		
		if (!isEmpty())
		{
			
			if (overdueOnly == true)
			{
				header("Overdue Books");
				flag = 1;


			}
			else
			{
				header("Books on Loan");
			}


			
			for (int i = 0; i < m_addedBooks; i++)
			{
				if (flag == 1)
				{
					if (m_books[i].hasPenalty())
					{
						cout.setf(ios::fixed);
						cout.width(4);
						cout.precision(2);
						cout.setf(ios::left);
						cout << rowNo;
						cout.unsetf(ios::left);
						m_books[i].display();
						
						rowNo++;
					}
				}
				else
				{
					cout.setf(ios::fixed);
					cout.width(4);
					cout.precision(2);
					cout.setf(ios::left);
					
					cout << rowNo;
					cout.unsetf(ios::left);
					m_books[i].display();
					
					rowNo++;

				}
			}
			filler('-');
		}
		else
		{
			cout << "Invalid Library" << endl;
		}
	}

}