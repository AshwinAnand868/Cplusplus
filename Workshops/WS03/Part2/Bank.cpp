/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 2 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Bank.h"
#include"Account.h"
using namespace std;
using namespace sdds;

 void Bank::initialize(const char* bank_name, int noOfAccounts)
{
	 if (bank_name != nullptr && bank_name[0] != '\0' && noOfAccounts > 0)
	 {
		 strcpy(bankName, bank_name);
		  totalNoOfAccounts = noOfAccounts;

		 accounts = new Account[totalNoOfAccounts];
		 
		 this->addedAccounts = 0;
     }
	 else
	 {
		 setSafeEmpty();
	 }
 }

 void Bank::setSafeEmpty()
 {
	 strcpy(bankName, "");
	 totalNoOfAccounts = 0;
	 accounts = nullptr;
	 addedAccounts = 0;

 }

 

 bool Bank::addAccount(int account_number, double balance, int daysSinceLastPayment)
 {
	 if (addedAccounts < totalNoOfAccounts)
	 {
		 accounts[addedAccounts].set(account_number, balance, daysSinceLastPayment);
		 if (!accounts[addedAccounts].isInSafeEmpty())
		 {
			 addedAccounts++;
			 return true;
		 }

		 	
	 }
         return false;
 }


 void Bank::clear()
 {
	 delete[] accounts;
	 accounts = nullptr;
 }
 

 void Bank::filler(char fillValue) const
 {
	 for (int i = 0; i < 40; i++)
	 {
		 cout << fillValue;
	 }
	 cout << endl;
 }

 void Bank::header(const char* bank_name) const
 {
	 filler('-');
	 
	 cout << ">>> " << bank_name << " <<<" << endl;

	 

	 filler('-');


	 cout << "Row Accnt No       Balance  Days Interest" << endl << "--- ---------- ------------ ---- --------" << endl;
 }


 void Bank::footer() const
 {
	 for (int i = 0; i < 41; i++)
	 {
		 cout << "-";
	 }
	 cout << endl;

 }

 
 bool Bank::isInSafeEmpty() const
 {
	 return (bankName[0] == 0);
 }
 void Bank::display(bool interestOnly) const
 {
	 double totalInterest = 0.0;

	 int rowNo = 1, i;

	 
		 if (!isInSafeEmpty())
		 {
			 
			 if (interestOnly)
			 {
				 cout << "INTEREST ONLY LIST!" << endl;
			 }
			 header(bankName);
			 for (i = 0; i < addedAccounts; i++)
			 {
				 if (interestOnly)
				 {

					

					 if (accounts[i].hasInterest())
					 {
						 cout.width(5);
						 
						 cout.setf(ios::left);
						 cout << rowNo;
						 cout.unsetf(ios::left);
						totalInterest = totalInterest + accounts[i].display();
						 rowNo++;
					 }
				 }
				 else
				 {
					 
					 cout.width(5);
					 cout.setf(ios::left);
					 cout << rowNo;
					 cout.unsetf(ios::left);
					 totalInterest = totalInterest + accounts[i].display();
					 rowNo++;
				 }

			 }
			 footer();

			 cout.setf(ios::fixed);
			 cout.precision(2);
			 cout << "              Total interest:  ";
			 cout.width(9);
                         cout << totalInterest << endl << endl;
			
		 }
		 else
		 {
			 cout << "Invalid Bank" << endl;
		 }
 }
 