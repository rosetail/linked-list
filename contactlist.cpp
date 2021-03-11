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

    void insert(
        const Contact contact) // function called to add a contact to the list
    {
        Node *tempNode; // node to temporarily hold the moving contact
        Node *nodeToInsert = new Node(contact); // the new contact being added
        Node *currentNode = head;               // the contact being moved

        if (head == nullptr) // if there are no contacts yet, the first contact
                             // becomes the head
        {
            head = nodeToInsert;
            return;
        }
        // make sure we check against head before traversing through the list
        else if (head->data.lastName > nodeToInsert->data.lastName)
        {
            tempNode = head;
            head = nodeToInsert;
            nodeToInsert->next = tempNode;
            return;
        }

        while (true)
        {
            // append if we're at the end of the list
            if (currentNode->next == nullptr)
            {
                tempNode = currentNode->next;
                currentNode->next = nodeToInsert;
                nodeToInsert->next = tempNode;
                return;
            }
            if (currentNode->next->data.lastName >
                nodeToInsert->data.lastName) // searches the list to put the new
                                             // contact in alphabetically
            {
                tempNode = currentNode->next; // temporarily holds the moving
                                              // node do it doesn't get deleted
                // inserts the new contact in alphabetically
                currentNode->next = nodeToInsert;
                // puts the moving contact back into the list
                nodeToInsert->next = tempNode;
                return;
            }
            currentNode = currentNode->next;
        }
    }

    void deleteContact(
        string name) // function called to delete a contact in the list
    {
        int pos = name.find(" "); // position of the first space in name
        string firstName = name.substr(0, pos); // get up to the first space
        string lastName =
            name.substr(pos + 1); // get from first space to the end
        Node *currentNode = head;

        if (head == nullptr) // exit if list is empty
            return;

        // check if we need to remove head before traversing
        if (head->data.firstName == firstName &&
            head->data.lastName == lastName)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            return;
        }

        // traverse the list to find the correct node
        while (currentNode->next != nullptr)
        {
            if (currentNode->next->data.firstName == firstName &&
                currentNode->next->data.lastName == lastName)
            {
                Node *tmp = currentNode->next;
                currentNode->next = currentNode->next->next;
                delete tmp;
                return;
            }
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
