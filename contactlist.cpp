/**
 * CIS 22B
 *
 * Lab4: A contact list that is implemented using a linked list
 *
 * Author: Rose Osterheld and Maren Alessandri Lane
 *
 * Group 4: Rose Osterheld, Maren Alessandri Lane, Alex Hagemeister

 *
 * Date: 03/07/2021
 */

#include "contact.hpp"
#include <iostream>

class PhoneBook : List
{
  private:
    Node *head;

  public:
    /**
     * Head is always initialized to nullptr. Use insert to add the first
     * contact
     */
    PhoneBook() : head(nullptr) {}

    /**
     * Prints every person in the phonebook
     */
    void print() const
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data;
            currentNode = currentNode->next;
        }
    }
};
