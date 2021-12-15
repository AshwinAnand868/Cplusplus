/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{
	VehicleBasic::VehicleBasic()
	{
		licensePlateNo[0] = { '\0' };
		vehicleCurrentAddrs[0] = { '\0' };
		yrVehicleBuilt = 0;
	}

	VehicleBasic::VehicleBasic(const char* licensePltNo, int year, const char* vehicleLocation)
	{
		yrVehicleBuilt = year;
		strcpy(licensePlateNo, licensePltNo);
		strcpy(vehicleCurrentAddrs, vehicleLocation);
	}

	void VehicleBasic::NewAddress(const char* address)
	{
		char vehicleOldAddrs[vhcleAddrSize] = { '\0' }; 
		strcpy(vehicleOldAddrs, vehicleCurrentAddrs);
		if (strcmp(vehicleCurrentAddrs, address) != 0)
		{
			strcpy(vehicleCurrentAddrs, address);
		}

		cout << "|";
		cout.width(8);
	
		cout << licensePlateNo;
		cout << "| |";
		cout.width(20);
		cout << vehicleOldAddrs;
		cout << " ---> ";
		cout.width(20);
		cout.setf(ios::left);
		cout << vehicleCurrentAddrs;
		cout << "|" << endl;
		cout.unsetf(ios::left);
	}

	ostream& VehicleBasic::write(ostream& os)const
	{
		os << "| " << yrVehicleBuilt << " | " << licensePlateNo << " | " << vehicleCurrentAddrs;
		return os;
	}

	std::istream& VehicleBasic::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> yrVehicleBuilt;
		
		cout << "License plate: ";
		in >> licensePlateNo;
		cout << "Current location: ";
		in >> vehicleCurrentAddrs;
		return in;
	}

	 ostream& operator<<(ostream& os, const VehicleBasic& vehicleBasic)
	{
		vehicleBasic.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, VehicleBasic& vehicleBasic)
	{
		return vehicleBasic.read(is);
		
	}
	const char* VehicleBasic::returnVehicleLocn()const
	{
		return vehicleCurrentAddrs;
	}

}
