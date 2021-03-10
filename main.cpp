/**
 * CIS 22B
 *
 * Lab4: A contact list that is implemented using a linked list
 *
 * Author: Alex Hagemeister
 *
 * Group 4: Rose Osterheld, Maren Alessandri Lane, Alex Hagemeister

 *
 * Date: 03/07/2021
 */

#include "contactlist.cpp"
#include "contact.hpp"
#include <iostream>
using namespace std;

int main() {
    
    PhoneBook ourPhoneBook; // Instantiation of PhoneBook object to contain contact names & phone numbers
    char userSelection;     // Variable for use in user interface
    Contact newContact;     // Buffer variable to contain new contact details to insert into list
    string fName;
    string lName;
    
    /*
     User interface prompts the user to insert a new contact, delete a contact,
     or print the list of contacts. The appropriate methods are called based on the users' selection,
     and the prompt repeats until the user chooses to quit.
     */
    bool quit = false;
    
    while (!quit) {
        
        cout << "Choose from the following options: \n";
        cout << "i - insert new contact\n";
        cout << "d - delete a contact\n";
        cout << "p - print list of contacts\n";
        cout << "q - quit\n";
    
        cin >> userSelection;
    
        switch (userSelection) {
        
            // FIXED: 'insert new contact' selection now passes initialized Contact to insert function
            case 'i':
                cout << "Enter contact name to insert: ";
                cin.ignore();
                cin >> newContact.firstName;
                cin.ignore();
                cin >> newContact.lastName;
                cout << "Enter contact phone number: ";
                cin >> newContact.tel;
                ourPhoneBook.insert(newContact);
                
                break;
                
                // FIXED: 'delete' selection now passes first and last name to remove function
            case 'd':
                cout << "Enter contact name to remove: ";
                cin.ignore();
                cin >> fName;
                cin.ignore();
                cin >> lName;
                ourPhoneBook.remove(fName, lName);
                break;
                
            case 'p':
                ourPhoneBook.print();
                break;
                
            case 'q':
                quit = true;
                break;
                
            default:
                cout << "Invalid selection. Try again.\n";
                break;
        }
    }
    return 0;
}
