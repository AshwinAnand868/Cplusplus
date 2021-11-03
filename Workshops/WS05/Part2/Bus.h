/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 18 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
namespace sdds 
{
   
    const double busTktPrice = 125.34;
   class Bus 
   {
      
       int nSeats;
       int nPassengers;
       void drawBus(std::ostream& ostr, int seats, int psng);
       void setOutOfService();
   public: 
       Bus(int noOfSeats = 20, int noOfPassengers = 0);
       std::istream& read(std::istream& istr);
       
       operator bool() const;
       operator int() const;
       operator double() const;
       std::ostream& display(std::ostream& ostr)const;
       bool operator--();
       bool operator++();
       bool operator--(int);
       bool operator++(int);
       Bus& operator=(int value);
       Bus& operator+=(int value);
       Bus& operator+=(Bus& bus);
       bool operator==(Bus& bus);
       
       
   };
   int operator+(int leftNum, const Bus& bus);
   std::ostream& operator<<(std::ostream&,const Bus& senecaBus);
   std::istream& operator>>(std::istream&, Bus& senecaBus);

   
}
#endif