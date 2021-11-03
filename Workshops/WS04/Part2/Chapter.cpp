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
using namespace std;

namespace sdds
{
	Chapter::Chapter()
	{
		setEmpty();
	}
	Chapter::Chapter(const char* chapName, int pages)
	{
		if (chapName != nullptr && chapName[0] != '\0' && pages > 0)
		{
			strcpy(chapterName, chapName);
			noOfPages = pages;
		}
		else
		{
			setEmpty();
		}
	}
	void Chapter::setEmpty()
	{
		chapterName[0] = '\0';
		noOfPages = -1;
	}
	bool Chapter::isEmpty()const
	{
		return chapterName[0] == '\0' && noOfPages < 0;
	}
	void Chapter::displayChapter()const
	{

		if (!(isEmpty()))
		{
			cout.width(50);
			cout.setf(ios::left);
			cout.fill('.');
			cout << chapterName;
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.fill(' ');
			cout << " ";
			cout.width(3);
			cout << noOfPages;
			cout.unsetf(ios::right);
			cout << endl;
		}
		else
		{
			cout << "Invalid Chapter" << endl;
		}

	}

	/*Chapter::~Chapter()
	{
		delete[] chapterName;
	}*/

}
