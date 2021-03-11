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

    void insert(const Contact contact)
    {
        Node *tempNode;
        Node *nodeToInsert = new Node(contact);
        Node *currentNode = head;

        if (head == nullptr)
        {
            head = nodeToInsert;
            return;
        }
        else if (head->data.lastName > nodeToInsert->data.lastName)
        {
            tempNode = head;
            head = nodeToInsert;
            nodeToInsert->next = tempNode;
            return;
        }

        while (true)
        {
            if (currentNode->next == nullptr)
            {
                currentNode->next = nodeToInsert;
                nodeToInsert->next = tempNode;
                break;
            }
            if (currentNode->next->data.lastName > nodeToInsert->data.lastName)
            {
                tempNode = currentNode->next;
                currentNode->next = nodeToInsert;
                nodeToInsert->next = tempNode;
                break;
            }
            currentNode = currentNode->next;
        }
    }

    void deleteContact(string name)
    {
        Node *nodeToRemove;
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            nodeToRemove = contact->next;
            contact->next = nodeToRemove->next;
            delete nodeToRemove;
            currentNode = currentNode->next;
        }
    }

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
