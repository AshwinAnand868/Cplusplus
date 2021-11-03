/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 2 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

namespace sdds
{
	const int INTEREST_FREE_PERIOD = 30;
	const double INTEREST_RATE = 28.5 / 100;
	const double INTEREST_RATE_FRACTION = INTEREST_RATE;
	const int NUMBER_OF_DAYS_IN_A_YEAR = 365;
	class Account
	{
		int accountNumber;
		double accountBalance;
		int daysTillLastPayment;

		void setSafeEmpty();
		double intereset() const;

		public:
			 void set(int accNo, double bal,int daysSinceLastPayment);
			  bool isInSafeEmpty() const;
			  double display() const;
			  bool hasInterest() const;
			  

	};
}
#endif // !SDDS_ACCOUNT_H
