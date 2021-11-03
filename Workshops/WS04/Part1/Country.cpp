/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 22 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Country.h"
#include "City.h"
#include <cstring>
using namespace std;

namespace sdds
{



	Country::Country()
	{
		setEmpty();
	}

	Country::Country(const char* name, int noOfCity, const City* cities)
	{
		setEmpty();
		bool valid = name != nullptr && cities != nullptr && noOfCity > 0;
		if (valid)
		{
			setName(name);
			m_noOfCity = noOfCity;
			if (m_noOfCity > 0 && m_noOfCity < MAX_CITY)
			{
				m_city = new City[m_noOfCity];
				for (int i = 0; i < m_noOfCity; i++)
				{
					m_city[i] = cities[i];
				}
			}

		}
		else
		{
			setEmpty();
		}
	}

	void Country::setName(const char* name)
	{
		delete[] m_name;
		if (name != nullptr && name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);

		}
		else
		{
			delete[] m_city;
			setEmpty();
		}

	}

	Country& Country::addCity(const City& c)
	{
		int i;
		if (!(c.isEmpty()))
		{
			City* tempCityptr = nullptr;
			tempCityptr = new City[m_noOfCity + 1];



			for (i = 0; i < m_noOfCity; i++)
			{
				tempCityptr[i] = m_city[i];
			}

			delete[] m_city;
			tempCityptr[i] = c;

			m_noOfCity++;
			m_city = tempCityptr;

		}
		return *this;
	}

	Country& Country::migrate(int people)
	{
		for (int i = 0; i < m_noOfCity; i++)
		{

			if (m_city[i].getPeople() < POPULATION)
			{
				m_city[i].addPopulation(people);
			}

		}

		return *this;
	}

	void Country::setEmpty()
	{
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}

	bool Country::isEmpty()const
	{
		return m_name == nullptr;
	}

	Country::~Country()
	{
		delete[] m_name;
		delete[] m_city;
	}

	void Country::display()const
	{
		if (!(this->isEmpty()))
		{
			cout << "Country Name: " << m_name << endl;
			cout << "No of city: " << m_noOfCity << endl;
			cout.setf(ios::left);
			cout.width(32);
			cout << "City name";

			cout.unsetf(ios::left);
			cout << "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++)
			{
				m_city[i].display();
			}
		}
		else
		{
			cout << "Invalid country object" << endl;
		}
	}



}