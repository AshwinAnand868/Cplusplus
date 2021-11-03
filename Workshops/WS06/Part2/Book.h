#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds
{

	const int MaxAuthorLen = 25;
	const int MaxTitleLen = 40;
	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	class Book
	{
		
		char* bookTitle{};
		char* authorName{};
		int bookCaseNo;
		int shelfNo;
		void set(const char* book_title,const char* author_name, int caseNo, int shelfNumber);
		void setEmpty();
		void extractChar(std::istream& istr, char ch);
	public:
		Book();
		Book(const char* book_title,const char* author_name, int caseNo, int shelfNumber);
		//bool validBookAndAuthorName(const char* author_name, const char* book_name) const;
		
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		operator bool()const;
		void allocateAndCopy(const char* author_name, const char* book_title);
		
		std::istream& read(std::istream& istr);

		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Book& book);
	std::istream& operator>>(std::istream& istr, Book& book);
}
#endif // !SDDS_BOOK_H
