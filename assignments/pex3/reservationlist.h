/*
 * File: linkedlist.h
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the definition of a ReservationList
 */
#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H
#include <iostream>
#include "reservation.h"
using namespace std;

// Error class
class ReservationListEmpty {
public:
    string description() const;
};

// Linked list class definition
class ReservationList {
public:
    /* Constructor & Destructor */
    ReservationList();
    ~ReservationList();
    /* Public Methods */
    // Returns true if list is empty, otherwise false
    bool isEmpty() const;
    // Returns processed count
    int getProcessed() const;
    // Returns number of reservations in list
    int getCount() const;
    // Insert's data into list based on data's pick up time
    //  sorted from earliest to latest pick up time
    void insert(ReservationPtr data);
    // Display's list contents
    void display() const throw (ReservationListEmpty);
    // Remove's the earliest pick up time from the list
    void removeEarliest() throw (ReservationListEmpty);
    // Reads in reservations if they exist. Returns true if
    //  filename was opened successfully else false
    bool readReservations(string filename);
    // Write reservations in list to filename
    void writeReservations(string filename);
private:
    // Node definition and convenience typedef for Node*
    struct Node {
	ReservationPtr data;
	Node *prev;
	Node *next;
    };
    typedef Node* NodePtr;
    /* ReservationList member variables */
    // Pointers to head and tail of list
    NodePtr head, tail;
    // Integer to keep track of processed reservations
    int processed;
    // Integer to keep track of list count
    int count;
    /* Private Methods */
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
