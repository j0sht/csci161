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
    friend ostream& operator <<(ostream& outs, const ReservationListEmpty& e);
};

// Linked list class definition
class ReservationList {
public:
    // Constructor & Destructor
    ReservationList();
    ~ReservationList();
    // Propert getters
    // Returns true if list is empty, otherwise false
    bool empty() const;
    int getProcessed() const;
    // Returns number of reservations currently in list
    int getCount() const;
    // Insert's data into list based on data's pick up time
    //  sorted from earliest to latest pick up time
    void insert(ReservationPtr data);
    void display() const throw (ReservationListEmpty);
    // Remove's the earliest pick up time from the list
    //  and returns its data
    ReservationPtr removeEarliest() throw (ReservationListEmpty);
    // Reads in reservations if they exist. Returns true if
    //  filename was opened successfully else false
    bool readReservations(string filename);
    void writeReservations(string filename);
private:
    // Node definition and convenience typedef for Node*
    struct Node {
	ReservationPtr data;
	Node *prev;
	Node *next;
    };
    typedef Node* NodePtr;
    // Member variables
    NodePtr head, tail;
    int processed, count;
    /* Assumes that node is not NULL */
    void setUpFirstNodeWith(NodePtr node);
    /* Assumes that tail and node are not NULL */
    void setTailTo(NodePtr node);
    /* Assumes that head and node are not NULL */
    void setHeadTo(NodePtr node);
    /* Assumes that node and after are not NULL */
    void insertBefore(NodePtr node, NodePtr after);
    // Removes and deallocates head and returns pointer to its data
    /* Assumes that head is not NULL when called */
    ReservationPtr removeHead();
};
#endif
