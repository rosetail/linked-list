//
//  Contact.hpp
//  PhoneBook
//
//  Created by Hellen Pacheco on 12/13/20.
//  Copyright © 2020 Hellen Pacheco. All rights reserved.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <string>

using namespace std;

// structure to hold the data related to one contact
struct Contact
{
    string firstName;
    string lastName;
    string tel;
};

// This operator is being overloaded so it can be used to print the content of
// a variable of type Contact.
// Ex: Contact person
//     cout << person
inline ostream &operator<<(ostream &strm, const Contact &obj)
{
    strm << obj.firstName + "\t";
    strm << obj.lastName + "\t";
    strm << obj.tel;
    return strm;
}

// Definition of one node on the linked list
class Node
{
  public:
    Node *next;
    Contact data;

    // Constructor initializes next and data
    Node(const Contact &value) : next(nullptr), data(value) {}
    // This function should Display the information in one node
    void display() {}
};

// Definition of the linked list
class List
{
  private:
    Node *head; // points to the beginning of the list

  public:
    List() : head(nullptr) {}
    // The destructor should traverse the list destroying each node
    ~List() {}
    // this function should insert in a way that keeps the list alphabatically
    // organized
    void insert(const Contact value) {}
    // this function should prints the whole list
    void print() const {}
};

#endif /* Contact_hpp */
