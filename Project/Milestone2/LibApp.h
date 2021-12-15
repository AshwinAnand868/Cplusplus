/*
Final Project Milestone 1
Module : LibApp
Filename : LibApp.cpp
Version 1.0
Author	Ashwin Anand
Revision History
---------------------------------------------------------- -
Reason - A mockup library application
Date - 21-11-2021
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include"Menu.h"
namespace sdds {
   class LibApp {
	   bool m_changed; // to be set to initial values that is false
	   Menu m_mainMenu;
	   Menu m_exitMenu;
	   bool confirm(const char* message);
	   void load();
	   void save();
	   void search();
	   void returnPub();
	   void newPublication();
	   void removePublication();
	   void checkOutPub();
   public:
	   LibApp();
	   void run();

	   

   };
}
#endif // !SDDS_LIBAPP_H



