/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 2 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include<iostream>
#include"Account.h"

using namespace std;
using namespace sdds;




    void Account::setSafeEmpty()
    {
		accountNumber = 0;
		accountBalance = 0;
		daysTillLastPayment = 0;
	}
	void Account::set(int accNo, double bal, int daysSinceLastPayment)
	{

		if (accNo != 0 && bal > 0 && daysSinceLastPayment > 0)
		{
			accountNumber = accNo;
			accountBalance = bal;
			daysTillLastPayment = daysSinceLastPayment;
		}
		else
		{
			setSafeEmpty();
		}
	}

	bool Account::isInSafeEmpty() const
	{
		return accountNumber == 0;
	}

	double Account::display() const
	{
		double interest, totalInterest = 0;
                
                cout.width(10);
		cout.setf(ios::left);
		cout << accountNumber;
		cout.unsetf(ios::left);

		cout.width(12);
		cout.setf(ios::right);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << accountBalance;
		cout.unsetf(ios::right);
		cout.unsetf(ios::fixed);
		cout << "  ";
		cout.width(4);
		cout.setf(ios::left);
		cout << daysTillLastPayment;
		cout.unsetf(ios::left);
				

		if (hasInterest())
		{

			interest = intereset();
			cout.setf(ios::right);
                        cout.precision(2);
            		cout.setf(ios::fixed);
			cout.width(8);
			cout << interest;
			cout.unsetf(ios::right);
         		cout.setf(ios::fixed);
			totalInterest = totalInterest + interest;


			
		}

		cout << endl;
		return totalInterest;
}


	bool Account::hasInterest() const
	{
		return daysTillLastPayment > INTEREST_FREE_PERIOD;
	}

	double Account::intereset() const
	{
		double totalInterest;
	  totalInterest = daysTillLastPayment* (INTEREST_RATE_FRACTION / NUMBER_OF_DAYS_IN_A_YEAR)* accountBalance;
	  return totalInterest;

		
	}


