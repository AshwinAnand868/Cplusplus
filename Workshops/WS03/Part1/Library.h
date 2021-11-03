/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 22 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include"Book.h"
namespace sdds
{
	const int libNameLen = 30;
	class Library
	{

        char m_name[libNameLen + 1];
		Book* m_books;

		int m_sizeOfBooksArray;

		int m_addedBooks;

		
		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
		void footer()const;

	public:
		void clear();
		void initialize(const char* name, int noOfBooks);
		bool addBook(const char* book_title, int sku, int loanDays);
		void display(const char* substr);
		void display(bool overdueOnly = false)const;


	};

}