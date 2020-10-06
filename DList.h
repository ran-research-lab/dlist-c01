// class DList:
// Declaration of the ADT List using linked list
// Code from the OpenDSA book

#include "List.h"
#include <stdexcept>
#include <string>
#ifndef MAIN_LLIST_H
#define MAIN_LLIST_H

class DNode {         // Singly linked list node class
public:
    ListItemType data;    // Value for this node
    DNode *next;      // Point to next node in list
    DNode *prev;      // Point to previous node in list

    // Constructor
    DNode(ListItemType d = 0, DNode *p = NULL, DNode *n = NULL)
        { data = d; prev = p; next = n; }
};


class DList : public List {
private:
    DNode *head;         // Pointer to list header
    DNode *tail;         // Pointer to last element
    DNode *curr;         // Access to current element
    int listSize;      // Size of list
public:

    DList() {
        // these are the buffer nodes
        tail = curr = new DNode();
        head = new DNode(0, NULL, tail);
        tail->prev = head;
    }
    // Destructor
    ~DList();

    // Remove all contents from the list, so it is once again empty
    void clear();

    // Insert "it" at the current location
    // The client must ensure that the list's capacity is not exceeded
    bool insert(const ListItemType& d);

    // Append "it" at the end of the list
    // The client must ensure that the list's capacity is not exceeded
    bool append(const ListItemType& it);

    // Remove and return the current element
    ListItemType remove();

    // Set the current position to the start of the list
    void moveToStart();

    // Set the current position to the end of the list
    void moveToEnd();

    // Move the current position one step left, no change if already at beginning
    void prev();

    // Move the current position one step right, no change if already at end
    void next();

    // Return the number of elements in the list
    int length() const;

    // Return the position of the current element
    int currPos() const;

    // Set the current position to "pos"
    bool moveToPos(int pos);

    // Return true if current position is at end of the list
    bool isAtEnd() const;

    // Return the current element
    ListItemType getValue() const;

    bool isEmpty() const;

    // Returns a string in the form < e0, e1 | e2 >, where the "|" indicates
    // the current position
    string to_string() const;
};


#endif //MAIN_LLIST_H
