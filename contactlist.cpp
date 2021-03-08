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
    /**
     * helper function for the destructor
     */
    void freeList(Node *currentNode)
    {
        // finish if the current node is null
        if (currentNode == nullptr)
            return;
        // recursively traverse through list to delete every node
        freeList(currentNode->next);
        delete currentNode;
    }

  public:
    /**
     * Head is always initialized to nullptr. Use insert to add the first
     * contact
     */
    PhoneBook() : head(nullptr) {}

    /**
     * Recursively deletes each node to prevent a memory link
     */
    ~PhoneBook() { freeList(head); }

    /**
     * Prints every person in the phonebook
     */
    void print() const
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }
};
