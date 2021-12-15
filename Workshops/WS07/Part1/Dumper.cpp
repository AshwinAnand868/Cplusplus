/*
Name: Ashwin Anand
Email: aanand24@myseneca.ca
Student ID: 152042206
Data: 10 November 2021
Section: OOP244NCC

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include<cstring>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;

namespace sdds
{
	Dumper::Dumper(const char* lcnsePltNo, int year, double dumperCurrCapacity, const char* vehicleAddress) : VehicleBasic( lcnsePltNo, year)
	{
		currentWeightCarried = 0.0;
		maxWeightCapacity = dumperCurrCapacity;
		if (strcmp(VehicleBasic::returnVehicleLocn(), vehicleAddress) != 0)
		{
			VehicleBasic::NewAddress(vehicleAddress);
		}

	}

	bool Dumper::loaddCargo(double cargo)
	{
		bool toReturn = false;
		double totalWght = cargo + currentWeightCarried;
		currentWeightCarried = totalWght < maxWeightCapacity ? totalWght : currentWeightCarried;
		toReturn = currentWeightCarried == totalWght ? true : false;
		return toReturn;
	}

	bool Dumper::unloadCargo()
	{
		double storedCurrWght = currentWeightCarried;
		bool toRet = false;
		if (currentWeightCarried != 0.0)
		{
			currentWeightCarried = 0.0;
			toRet = currentWeightCarried != storedCurrWght ? true : false;
		}
		
		return toRet;
	}

	ostream& Dumper::write(ostream& os) const
	{
		VehicleBasic::write(os);
		os << " | " << currentWeightCarried <<"/" << maxWeightCapacity;
		return os;
	}

	istream& Dumper::read(istream& is)
	{
		VehicleBasic::read(is);
		cout << "Capacity: ";
		cin >> maxWeightCapacity;
		cout << "Cargo: ";
		cin >> currentWeightCarried;
		return is;
	}

	 std::ostream& operator<<(std::ostream& os, const Dumper& dumper)
	{
		dumper.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Dumper& dumper)
	{
		return dumper.read(is);
	}


}
