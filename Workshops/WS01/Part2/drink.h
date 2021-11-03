/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id - 152042206
Date of creation - 13 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef DRINK_H
#define DRINK_H

namespace sdds
{
	const int MAXDRINKS = 5;

	struct Drink
	{
		char name[10];
		int volume;
		double price;
		int quantity;
	};

//	void loadDrinks();
	void loadDrinksFromFile(const char* filename);
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);
}
#endif