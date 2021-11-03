/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 15 October 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
namespace sdds {
	const int RegularEggWieght = 50; // in grams
	const int JumboEggWieght = 75; // in grams
   
	class EggCarton {
	   int m_size;
	   int m_noOfEggs;
	   int m_jumbo;
       void setBroken();
  
   public:
	   EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
	   std::ostream& display(std::ostream& ostr) const;
	   std::istream& read(std::istream& istr);
	   operator bool() const;
	   operator int() const;
	   operator double() const;
	   EggCarton& operator--();
	   EggCarton& operator++();
	   EggCarton operator--(int);
	   EggCarton operator++(int);
	   EggCarton& operator=(int value);
	   EggCarton& operator+=(int value);
	   EggCarton& operator+=(EggCarton& right);
	   bool operator==(const EggCarton& right)const;
   };

   int operator+(int left, const EggCarton& right);
   std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
   std::istream& operator>>(std::istream& istr, EggCarton& right);


}
#endif