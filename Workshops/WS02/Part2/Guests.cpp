#include <iostream>
using namespace std;
#include "Guests.h"
namespace sdds {
   void read(char* str, int len) 
   {
      if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
      cin.getline(str, len);
   }

   void read(PhoneNumber& thePhoneNumber)
   {
       cout << "Enter Phone Number [area] [number]: ";
       cin >> thePhoneNumber.m_areacode;
       cin >> thePhoneNumber.m_number;
   }

   bool read(Guest& theGuest)
   {
       cout << "Guest name: ";
       read(theGuest.m_name, 21);
    
       if (theGuest.m_name[0])
       {
           read(theGuest.m_phno);
           return true;
       }
       return false;

   }
   void print(const PhoneNumber& thePhoneNUmber)
   {
       cout << "(" << thePhoneNUmber.m_areacode << ") " << thePhoneNUmber.m_number << endl;

   }
   void print(const Guest& theGuest)
   {
       cout << theGuest.m_name << ", "; 
       print(theGuest.m_phno);
   }
   void print(const GuestList& theGuestList)
   {
       int i;
       
       for (i = 0; i < theGuestList.m_noOfGuests; i++)
       {
           
           cout << i + 1 << "- ";
           print(theGuestList.m_gst[i]);
       }
       
   }
   void addGuest(GuestList& theGuestList, const Guest& aGuest)
   {
  
       Guest* guest = nullptr;
       guest = new Guest[theGuestList.m_noOfGuests + 1];
       for (int i = 0; i < theGuestList.m_noOfGuests; i++)
       {

           guest[i] = theGuestList.m_gst[i];
       }
    
       guest[theGuestList.m_noOfGuests] = aGuest;
       delete[] theGuestList.m_gst;
       theGuestList.m_gst = nullptr;
       theGuestList.m_gst = guest;
       theGuestList.m_noOfGuests++;
   }
}