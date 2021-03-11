/**
 * CIS 22B
 *
 * Lab4: A contact list that is implemented using a linked list
 *
 * main function:  instantiates phone book object and provides the user interface where they may choose to add or remove contacts, or print the list of contacts. 
 *
 * Author: Alex Hagemeister (person 1: main function)
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
    string fullName;
    
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
        
            /*
             'insert new contact' selection prompts the user to enter contact details. These are assigned with
             newContact data members which is then passed to insert function.
             */
            case 'i':
                cout << "Enter contact name to insert: ";
                cin.ignore();
                cin >> newContact.firstName;
                cin.ignore();
                cin >> newContact.lastName;
                cout << "Enter contact phone number: ";
                cin >> newContact.tel;
                ourPhoneBook.insert(newContact);
                cout << endl;
                
                break;
                
                /*
                 'delete a contact' selection prompts the user to enter the name of the contact
                 they wish to delete, assigns this name to newContact and passes to remove function.
                 */
            case 'd':
                cout << "Enter contact name to delete: ";
                cin.ignore();
                getline(cin, fullName);
                ourPhoneBook.deleteContact(fullName);
                break;
                /*
                 'print list of contacts' selection calls the print function.
                 */
            case 'p':
                ourPhoneBook.print();
                cout << endl;
                break;
                /*
                 'quit' selection exits the selection menu, & program ends;
                 */
            case 'q':
                quit = true;
                break;
                /*
                 If the user input does not match selection options, prints error message
                 and selection prompt repeats.
                 */
            default:
                cout << "Invalid selection. Try again.\n";
                break;
        }
    }
    return 0;
}
