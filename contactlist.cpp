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
#include <algorithm>
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
    void PhoneBook::insert(const Contact value)
    {
        PhoneBook()::head(nullptr) {}
        if (head)
        {
            // First check against the head value to see if it should be first
            if (value < head->data)
            {
                Node Contact *x = new Node Contact;
                x->data = value;
                x->next = head;
                head = x; // make x the new head
            }
            // keep looking through list
            Node Contact *y = head;
            while (y->next)
            {
                if (y->next->data < value)
                    y = y->next;
                else
                    break;
            }
            // actually insert the node
            Node Contact *x = new Node Contact;
            x->data = value;
            x->next = y->next;
            y->next = x;
        }

        // If it's the first contact being added
        else
        {
            head = new Node Contact;
            head->data = value;
            head->next = NULL;
        }
    }

    void remove(value) { remove(List, value); }

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
