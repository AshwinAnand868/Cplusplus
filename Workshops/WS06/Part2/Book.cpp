/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 27 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

namespace sdds
{


	void Book::setEmpty()
	{
		bookTitle = nullptr;
		authorName = nullptr;
	}

	void Book::allocateAndCopy(const char* author_name, const char* book_title)
	{
		delete[] bookTitle;
		delete[] authorName;
		bookTitle = new char[strlen(book_title) + 1];
		authorName = new char[strlen(author_name) + 1];
		strcpy(bookTitle, book_title);
		strcpy(authorName, author_name);

	}

	void Book::extractChar(std::istream& istr, char ch)
	{
		if (istr.peek() == ch)
		{
			istr.get();
		}
		else
		{
			istr.setstate(ios::failbit);
		}
	}

	void Book::set(const char* book_title, const char* author_name, int caseNo, int shelfNumber)
	{
		if (book_title != nullptr && book_title[0] != '\0' && author_name != nullptr && author_name[0] != '\0' && caseNo >= 1 && caseNo <= NoOfBookCases && shelfNumber >= 1 && shelfNumber <= NoOfShelves)
		{
			allocateAndCopy(author_name, book_title);
			shelfNo = shelfNumber;
			bookCaseNo = caseNo;
		}
		else
		{
			delete[] bookTitle;
			delete[] authorName;
			setEmpty();
		}
	}

	Book::Book()
	{
		authorName = nullptr;
		bookTitle = nullptr;
		bookCaseNo = 0;
		shelfNo = 0;
	}

	Book::Book(const Book& book)
	{
		if (book)
		{
			set(book.bookTitle, book.authorName, book.bookCaseNo, book.shelfNo);
		}

	}

	Book::Book(const char* bookTitle, const char* authorName, int bookCaseNumber, int shelfNumber)
	{
		set(bookTitle, authorName, bookCaseNumber, shelfNumber);
	}

	Book& Book::operator=(const Book& book)
	{
		if (this != &book)
		{
			set(book.bookTitle, book.authorName, book.bookCaseNo, book.shelfNo);
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] authorName;
		delete[] bookTitle;
	}

	Book::operator bool() const
	{
		return authorName != nullptr && bookTitle != nullptr;
	}

	std::ostream& Book::write(std::ostream& ostr, bool onScreen) const
	{
		if (onScreen)
		{
			if (*this)
			{
				ostr.setf(ios::left);
				ostr.width(40);
				ostr.fill(' ');
				ostr << bookTitle;
				ostr << "| ";
				ostr.width(25);
				ostr.fill(' ');
				ostr << authorName;
				ostr.unsetf(ios::left);
				ostr << "| ";

				ostr << shelfNo << '/';

				ostr.fill('0');
				ostr.width(3);

				ostr << bookCaseNo;
			}
			else
			{
				ostr << "Invalid Book Record ................... | ........................ | .....";

			}
		}
		else
		{
			if (*this)
			{
				ostr << bookTitle << "," << authorName << "," << shelfNo << '/' << bookCaseNo;
			}
			else
			{
				ostr << "Invalid Book Record";
			}

		}
		return ostr;
	}

	istream& Book::read(std::istream& istr)
	{
		int shelf_no = 0, book_case_no = 0; // book title temperory length increment for some books which has title length name more than that of usual MaxTitleLen
		const int maxTitleLenInc = MaxTitleLen + 1;
		char author_name[MaxAuthorLen];
		char book_title[maxTitleLenInc];

		istr.getline(book_title, maxTitleLenInc, ',');

		istr.getline(author_name, MaxAuthorLen, ',');

		istr >> shelf_no;
		if (shelf_no < 1 || shelf_no >NoOfShelves)
		{
			istr.setstate(ios::failbit);
		}

		extractChar(istr, '/');

		istr >> book_case_no;
		if (book_case_no<1 || book_case_no > NoOfBookCases)
		{
			istr.setstate(ios::failbit);
		}

		if (!istr.fail())
		{
			set(book_title, author_name, book_case_no, shelf_no);
		}
		return istr;
	}

	ostream& operator<<(std::ostream& ostr, const Book& cnt)
	{
		return cnt.write(ostr, true);
	}

	istream& operator>>(std::istream& istr, Book& cnt)
	{
		return cnt.read(istr);
	}
}