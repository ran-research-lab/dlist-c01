// class DList:
// An implementation of the ADT List using linked list
// Code from the OpenDSA book

#include "DList.h"
#include <string>

DList::~DList() { clear(); }

// Remove all elements
void DList::clear() {
    curr = head->next;
    while(curr != tail) remove();
}

// Insert d at current position
bool DList::insert(const ListItemType& d) {
    curr = new DNode(d, curr->prev, curr);
    curr->prev->next = curr; //setNext(curr);
    curr->next->prev = curr;
    listSize++;
    return true;
}

// Append d to list
bool DList::append(const ListItemType& d) {
    tail->prev = new DNode(d, tail->prev, tail);
    tail->prev->prev->next = tail->prev;
    if (curr == tail) curr = tail->prev;
    listSize++;
    return true;
}

// Remove and return current element
ListItemType DList::remove ()  {
    if (curr == tail) // Nothing to remove
        throw std::out_of_range("remove() in DList: current is at the tail, cannot remove");
    DNode *tmp = curr;
    ListItemType tmpData = curr->data;       // Remember value
    curr->prev->next = curr->next;     // Remove from list
    curr->next->prev = curr->prev;
    curr = curr->next;
    listSize--;                             // Decrement element count
    delete tmp;                             // Delete the node!
    return tmpData;                         // Return value
}

void DList::moveToStart()   { curr = head->next; } // Set curr at list start
void DList::moveToEnd()     { curr = tail; }          // Set curr at list end

// Move curr one step left; no change if now at front
void DList::prev() {
    if (curr->prev != head)   // Can't back up from list head
        curr = curr->prev;
}

// Move curr one step right; no change if now at end
void DList::next() { if (curr != tail) curr = curr->next; }

int DList::length() const { return listSize; } // Return list length


// Return the position of the current element
int DList::currPos() const {
    DNode *temp = head->next;
    int i;
    for (i=0; curr != temp; i++)
        temp = temp->next;
    return i;
}

// Move down list to "pos" position
bool DList::moveToPos(int pos) {
    if ((pos < 0) || (pos > listSize)) return false;
    curr = head->next;
    for(int i=0; i<pos; i++) curr = curr->next;
    return true;
}

// Return true if current position is at end of the list
bool DList::isAtEnd() const { return curr == tail; }

// Return current element value.
ListItemType DList::getValue() const  {
        if (curr == tail) // No current element
            throw std::out_of_range("getvalue() in DList is currently at tail, which is not a a valid element");
        return curr->data;
}

// Check if the list is empty
bool DList::isEmpty() const { return listSize == 0; }


string DList::to_string() const {
    string res = "<";
    int i = 0;
    DNode *tmp = head->next;
    while (tmp!=tail) {
        if ( tmp == curr) res += "|";
        res += std::to_string(tmp->data);
        if (tmp->next!= tail && curr != tmp->next)  res += ",";
        tmp = tmp->next;
    }
    if ( tmp == curr) res += "|";
    res += ">";
    return res;


}