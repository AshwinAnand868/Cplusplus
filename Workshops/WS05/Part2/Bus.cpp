/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 18 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/




#include<iostream>
#include "Bus.h"
using namespace std;
namespace sdds {
	void Bus::setOutOfService()
	{
		nPassengers = -1;
		nSeats = -1;
	}
	Bus::Bus(int noOfSeats, int noOfPassengers)
	{
		if (noOfSeats % 2 == 0 && noOfSeats >= 10 && noOfSeats <= 40 && noOfPassengers >= 0 && noOfPassengers <= noOfSeats)
		{
			nSeats = noOfSeats;
			nPassengers = noOfPassengers;
		}
		else
		{
			setOutOfService();
		}

	}

	ostream& Bus::display(ostream& ostr)const
	{
		Bus tempSenecaBus = *this;
		if (tempSenecaBus)
		{
           tempSenecaBus.drawBus(ostr, nSeats, nPassengers);
		   ostr.width(4);
		   ostr.precision(2);
		   ostr.setf(ios::fixed);

		   ostr << "Total Fare Price: " << (double) *this << endl;
		   cout.precision(6);

		   cout.unsetf(ios::fixed);
	    }
		else
		{
			ostr << "Out of service!" << endl;
		}
		return ostr;
	}

	istream& Bus::read(istream& istr)
	{
		int seats, passengers;
		istr >> seats;

		istr.ignore();
		istr >> passengers;

		if (seats % 2 == 0 && seats >= 10 && seats <= 40 && passengers >= 0 && passengers <= seats)
		{
			nSeats = seats;
			nPassengers = passengers;
		}
		else
		{
			setOutOfService();

		}
		return istr;
	}
	Bus::operator bool() const
	{
		return nSeats > 0;
		
	}

	Bus::operator int() const
	{
		if (*this)
		{
			return nPassengers;
		}
                else
                {
		        return -1;
                }
	}
	Bus::operator double() const
	{
	
		
		if(*this)
		{
		   return nPassengers * busTktPrice;
		}
		return -1.0;
	}

	void Bus::drawBus(ostream& ostr, int seats, int psng)
	{
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}


	 ostream& operator<<(ostream& ostr, const Bus& senecaBus)
	{
		 senecaBus.display(ostr);
		 return ostr;
	}

	 istream& operator>>(istream& istr, Bus& senecaBus)
	 {
		 senecaBus.read(istr);
		 return istr;
	 }
	 bool Bus::operator--()
	 {
              bool flag = false;
		 if (*this && nPassengers != 0)
		 {
			 nPassengers--;
			 flag = true;
		 }
		 return flag;


	 }
	 bool Bus::operator++()
	 {
                 bool flag = false;
		 if (*this && nPassengers < nSeats)
		 {
		      nPassengers++;
		      flag = true;
			 
		 }
		 return flag; 
	 }

	 bool Bus::operator--(int)
	 {
                     
			bool value =  --(*this);
			return value;
                        
			
	 }

	 bool Bus::operator++(int)
	 {
			bool value = ++(*this);
			return value;
	 }

	 Bus& Bus::operator=(int value)
	 {
		 nPassengers = value;
		 if (nPassengers > nSeats)
		 {
			 setOutOfService();
		 }
		 return *this;
	 } 
	 Bus& Bus::operator+=(int value)
	 {
		 if (*this)
		 {
			 nPassengers += value;
		 }
		 if (nPassengers > nSeats)
		 {
			 setOutOfService();
		 }
		 return *this;
	 }
	 
	 Bus& Bus::operator+=(Bus& bus)
	 {
		 bool flag = true;
		 if (*this && bus)
		 {
			 while (bus.nPassengers > 0 && flag == true) // 7
			 {
				 if (nPassengers < nSeats) // 7 < 10, 8 < 10, 9 < 10
				 {
					 nPassengers++; // 8, 9, 10
					 bus.nPassengers--; // 7, 6, 5
				 }
				 if (nPassengers == nSeats)
				 {
					 flag = false;
				 }
			 }
			 
		 }
		 return *this;
	 }
	 bool Bus::operator==(Bus& bus)
	 {
		 return *this && bus && nPassengers == bus.nPassengers;
	 }

	 int operator+(int leftNum,const Bus& bus)
	 {
		 int passgengersAtStop;
		 if(bus)
		 {
			 passgengersAtStop = leftNum + (int)bus;
			 return passgengersAtStop;
		 }
		 else
		 {
			 return leftNum;
		 }
	 }
}