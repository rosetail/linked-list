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
    string contactName;
    int contactNum;
    
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
        
            case 'i':
                cout << "Enter contact name to insert: ";
                cin.ignore();
                getline(cin, contactName);
                cout << "Enter contact phone number: ";
                cin >> contactNum;
                ourPhoneBook.insert(contactName, contactNum);
                break;
                
            case 'd':
                cout << "Enter contact name to remove: ";
                cin.ignore();
                getline(cin, contactName);
            
                ourPhoneBook.remove(contactName);
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
