/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 2 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include"Account.h"
namespace sdds
{

	const char bankNameLen = 40;
	
	class Bank
	{

	public : int totalNoOfAccounts;

	private:
		char bankName[bankNameLen + 1];

		
		Account* accounts;

		int addedAccounts = 0;

		void setSafeEmpty();
		bool isInSafeEmpty() const;
		void header(const char* bankName) const;
        void footer() const;
		
	public:
		void filler(char fillValue) const;
		void initialize(const char* bank_name, int noOfAccounts);
		
		bool addAccount(int account_number, double balance, int daysSinceLastPayment);
		void clear();
		
		void display(bool interestOnly = false)const;
		
	};

}