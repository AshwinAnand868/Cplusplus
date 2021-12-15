/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	const int sizeOfLcnsePlt = 9; 
	const int vhcleAddrSize = 21;
	class VehicleBasic
	{
		char licensePlateNo[sizeOfLcnsePlt];
		char vehicleCurrentAddrs[vhcleAddrSize];
		int yrVehicleBuilt;
	public:
		VehicleBasic();
		VehicleBasic(  const char* licensePltNo, int year, const char* vehicleLocation = "Factory");
		void NewAddress(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);

		const char* returnVehicleLocn()const;

	};
    std::ostream& operator<<(std::ostream& os, const VehicleBasic& vehicleBasic);
	std::istream& operator>>(std::istream& is, VehicleBasic& vehicleBasic);

}

#endif