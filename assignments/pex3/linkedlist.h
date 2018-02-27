/*
 * File: linkedlist.h
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the definition of a LinkedList
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "reservation.h"
using namespace std;

// Linked list class definition
class LinkedList {
public:
    /* Constructor */
    LinkedList() {
        head = NULL;
	tail = NULL;
        processed = 0;
    }
    /* Public Methods */
    // Returns true if list is empty, otherwise false
    bool isEmpty();
    // Returns processed count
    int getProcessed() const;
    // Insert's data into list based on data's pick up time
    //  sorted from earliest to latest pick up time
    void insert(ReservationPtr data);
    // Display's list contents
    void display();
    // Remove's the earliest pick up time from the list
    void removeEarliest();
private:
    // Node definition and convenience typedef for Node*
    struct Node {
	ReservationPtr data;
	Node *prev;
	Node *next;
    };
    typedef Node* NodePtr;
    /* LinkedList member variables */
    // Pointers to head and tail of list
    NodePtr head, tail;
    // Integer to keep track of processed reservations
    int processed;
    /* Private Methods */
    // Informs user there are no reservations in the list
    void printNoReservationsMessage();
    // Sets up node to be the first node in an empty list
    /* Assumes that node is not NULL */
    void setUpFirstNodeWith(NodePtr node);
    // Sets tail of the list to given node
    /* Assumes that tail and node are not NULL */
    void setTailTo(NodePtr node);
    // Sets head of the list to given node
    /* Assumes that head and node are not NULL */
    void setHeadTo(NodePtr node);
    // Inserts given node before given after node
    /* Assumes that node and after are not NULL */
    void insertBefore(NodePtr node, NodePtr after);
    // Removes and deallocates head and its data
    /* Assumes that head is not NULL when called */
    void removeHead();
};
#endif
