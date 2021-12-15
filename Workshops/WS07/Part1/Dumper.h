/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper : public VehicleBasic
	{
		double maxWeightCapacity;
		double currentWeightCarried; // must not exceed the maxWeightCapacity
	public:
		Dumper(const char* lcnsePltNo, int year, double dumperCapacity, const char* vehicleAddress);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);

	};
	std::ostream& operator<<(std::ostream& os, const Dumper& dumper);
	std::istream& operator>>(std::istream& is, Dumper& dumper);
}
#endif
