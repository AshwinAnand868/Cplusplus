#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds
{
	class Book
	{
		char* bookName;
		int noOfChapters;
		Chapter* chapters;

	public:
		Book();
		Book(const char* bName, int nChaps, Chapter* chaps);

		void setSafeEmpty();
		void setBookName(const char* name);
		bool isEmpty()const;
		Book& addChapter(const char* chapter_name, int noOfPages);
		void display()const;
		~Book();

	};
}
#endif