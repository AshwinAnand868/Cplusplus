/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 10 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHARACTERS_H
#define SDDS_CHARACTERS_H

namespace sdds
{
	const int chapNameLen = 50;
	const int MAXIMUMPAGES = 200;
	class Chapter
	{
		char chapterName[chapNameLen + 1];
		int noOfPages;

	public:
		Chapter();
		Chapter(const char* chapName, int pages);
		void setEmpty();
		bool isEmpty() const;

		void displayChapter() const;



	};
}
#endif
