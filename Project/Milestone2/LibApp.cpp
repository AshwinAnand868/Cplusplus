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

#include<iostream>
#include "LibApp.h"
using namespace std;
namespace sdds {

    LibApp::LibApp(): m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_changed = false;   
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();       
    }
    bool LibApp::confirm(const char* message)
    {
        Menu menuTitle(message);
        bool isOne;
        menuTitle << "Yes";
        isOne = menuTitle.run() == 1 ? true : false;
        return isOne;
    }

    void LibApp::load()
    {
        cout << "Loading Data" << endl;
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }
    void LibApp::newPublication()
    {
        bool isPublicationAdded;
        cout << "Adding new publication to library" << endl;
        isPublicationAdded = confirm("Add this publication to library?");
        if (isPublicationAdded)
        {
            cout << "Publication added" << endl;
            m_changed = true;
        }
        
    }
    void LibApp::removePublication()
    {
        bool isPublicationRemoved;
        cout << "Removing publication from library" << endl;
        search();
        isPublicationRemoved = confirm("Remove this publication from the library?");
        if (isPublicationRemoved)
        {
            cout << "Publication removed" << endl;
            m_changed = true;
        }               

    }

    void LibApp::checkOutPub()
    {
        bool publicationCheckedOut;
        search();
        publicationCheckedOut = confirm("Check out publication?");
        if (publicationCheckedOut)
        {
            cout << "Publication checked out" << endl;
            m_changed = true;
        }

    }
    void LibApp::run()
    {
        unsigned int selectedOption;
        
        bool done = false;
        bool warningShown = false;
        do
        {
            selectedOption = m_mainMenu.run();
            if (selectedOption == 1)
            {
                newPublication();
            }
            else if (selectedOption == 2)
            {
                removePublication();
            }
            else if (selectedOption == 3)
            {
                checkOutPub();
            }
            else if (selectedOption == 4)
            {
                returnPub();
            }
            else
            {
                done = true;
                warningShown = true;
            }

            if (m_changed && warningShown)
            {
                selectedOption = m_exitMenu.run();

                if (selectedOption == 1)
                {
                    save();
                    done = true;
                }
                else if (selectedOption == 2)
                {
                    done = false;
                }
                else
                {
                    if (confirm("This will discard all the changes are you sure?"))
                    {
                        done = true;
                    }
                }
            }
            cout << endl;
        } while (!done);
       
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
        
    }
    

    
}
