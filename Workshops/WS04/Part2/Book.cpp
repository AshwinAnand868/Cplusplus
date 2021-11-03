/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 10 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Chapter.h"
#include"Book.h"
using namespace std;

namespace sdds
{
	Book::Book()
	{
		setSafeEmpty();
	}

	Book::Book(const char* bName, int nChaps, Chapter* chaps)
	{
		setSafeEmpty();
		if (bName != nullptr && chaps != nullptr && nChaps > 0)
		{
			setBookName(bName);
			noOfChapters = nChaps;

			if (nChaps > 0)
			{
				chapters = new Chapter[nChaps];
				for (int i = 0; i < nChaps; i++)
				{
					chapters[i] = chaps[i];
				}
			}

		}
	}
	void Book::setSafeEmpty()
	{
		bookName = nullptr;
		noOfChapters = 0;
		chapters = nullptr;
	}

	void Book::setBookName(const char* name)
	{
		if (name != nullptr && name[0] != '\0')
		{
			bookName = new char[strlen(name) + 1];
			strcpy(bookName, name);

		}
		else
		{
			delete[] bookName;
			setSafeEmpty();
		}


	}

	bool Book::isEmpty()const
	{
		return bookName != nullptr && noOfChapters > 0;
	}

	Book& Book::addChapter(const char* chapter_name, int noOfPages)
	{
		int i;
		Chapter addedChapter = Chapter(chapter_name, noOfPages);
		if (!(addedChapter.isEmpty()) && noOfPages <= MAXIMUMPAGES)
		{
			Chapter* tempchaps = new Chapter[noOfChapters + 1];
			for (i = 0; i < noOfChapters; i++)
			{
				tempchaps[i] = chapters[i];
			}

			delete[] chapters;
			tempchaps[noOfChapters] = addedChapter;

			chapters = tempchaps;
			noOfChapters++;

		}
		return *this;
	}

	void Book::display()const
	{
		int i;
		bool valid = true;
		for (i = 0; i < noOfChapters; i++)
		{
			if (chapters[i].isEmpty())
			{
				valid = false;
			}

		}
		if (bookName != nullptr && noOfChapters > 0 && valid)
		{

			cout << "Book Name: ";
			cout << bookName << endl;
			cout << "No of Chapters: ";
			cout << noOfChapters << endl;
			cout << "Chapter name                                       Pages" << endl;

			for (i = 0; i < noOfChapters; i++)
			{
				chapters[i].displayChapter();
			}
		}
		else
		{
			cout << "Invalid Book object" << endl;
		}

	}
	Book::~Book()
	{
		delete[] bookName;
		delete[] chapters;
	}
}
