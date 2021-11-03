/*
Name - Ashwin Anand
Seneca email - aanand24@myseneca.ca
Student id -152042206
Date of creation - 22 September 2021
*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include<iostream>
#include<cstring>
#include "Fighter.h"
using namespace std;
namespace sdds 
{
	
	void fighter(char* name)
	{
		cout << "Enter Fighter Name: ";
		cin >> name;
	}
	void fighter(int& power)
	{
		
		cout << "Enter Fighter Power: ";
		cin >> power;
	}

	void addFighter(Competition& myCompetition)
	{
		int i;
		Fighter* fighters = nullptr;
		fighters = new Fighter[myCompetition.numfighters + 1];
		for (i = 0; i < myCompetition.numfighters; i++)
		{
			fighters[i] = myCompetition.fighters[i];
		}
		cout << "Information of the new fighter:\n";
		
		fighter(fighters[myCompetition.numfighters].name);
		fighter(fighters[myCompetition.numfighters].power);
		
		

		delete[] myCompetition.fighters;
		myCompetition.fighters = nullptr;
		myCompetition.fighters = fighters;
		
		myCompetition.numfighters++;

	}

	void display(const Fighter& myFighter)
	{

		cout << "Name: " << myFighter.name << ", Power: " << myFighter.power << endl;
	}
	void display(const Competition& mycompetition)
	{
		for (int i = 0; i < mycompetition.numfighters; i++)
		{
			display(mycompetition.fighters[i]);
		}
	}
	void removeFighter(Competition& mycompetition, const Fighter& loserFighter)
	{
		int numfighters, loserFighterIndex;
		numfighters = mycompetition.numfighters;
		Fighter* fighters = nullptr;
		fighters = new Fighter[numfighters - 1];
		loserFighterIndex = findFighter(mycompetition, loserFighter);
		for (int i = 0, j = 0; i < numfighters; i++)
		{
			if (loserFighterIndex != i)
			{
				fighters[j] = mycompetition.fighters[i];
				j++;
			}

		}
		mycompetition.numfighters--;
		delete[] mycompetition.fighters;
		mycompetition.fighters = fighters;
	}

	int findFighter(const Competition& mycompetition, const Fighter& theFighter)
	{
		int fighterIndex = -1;
		int temp, keepGoing = 1;

		for (int i = 0; i < mycompetition.numfighters && keepGoing ; i++)
		{
			temp =  strcmp(mycompetition.fighters[i].name, theFighter.name);
			fighterIndex = temp == 0 ? i : -1;
			keepGoing = !(fighterIndex == i);

		}
		return fighterIndex;
	}

	bool fight(const Fighter& f1, const Fighter& f2)
	{
		bool value;
		value = f1.power > f2.power;
		return value;
	}

	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2)
	{
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		bool value = fight(f1, f2);
		if (value)
		{
			cout << "    " << "The winner => ";
			display(f1);
			removeFighter(mycompetition, f2);
			
		}
		else
		{
			cout << "    " << "The winner => ";
			display(f2);
			removeFighter(mycompetition, f1);
			
			
		}

	}
}