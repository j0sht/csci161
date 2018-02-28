/*
 * File: linkedlist.cpp
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the implementation of a ReservationList
 */
#include <iostream>
#include <fstream>
#include "reservation.h"
#include "reservationlist.h"
using namespace std;

// Error class
string ReservationListEmpty::description() const {
    string s = "\nThere is currently no reservation in the ";
    s += "reservation list.\n";
    return s;
}

// Constructor
ReservationList::ReservationList() {
    head = NULL;
    tail = NULL;
    processed = count = 0;
}
ReservationList::~ReservationList() {
    while (head)
	removeHead();
}
// Public methods
bool ReservationList::isEmpty() const {
    return (head == NULL);
}
int ReservationList::getProcessed() const {
    return processed;
}
int ReservationList::getCount() const {
    return count;
}
void ReservationList::insert(ReservationPtr data) {
    // Create new node
    NodePtr node = new Node;
    // Add node data
    node->data = data;
    // Check if it is the first element
    if (!head)
	setUpFirstNodeWith(node);
    // Not the first element
    else {
	// Create tmp node to iterate through list,
	//  starting with current head
	NodePtr tmp = head;
	// Iterate through list while tmp is not NULL and
	//  tmp's time is less than the new data's time
	while (tmp && tmp->data->timeIsLessThan(data))
	    tmp = tmp->next;
	// Check if it is the back of the list
	if (tmp == NULL) {
	    setTailTo(node);
	}
	// Check if it is the front of the list
	else if (tmp == head) {
	    setHeadTo(node);
	}
	// It is between two nodes
	else {
	    insertBefore(node, tmp);
	}
    }
    count++;
}
void ReservationList::display() const throw (ReservationListEmpty) {
    if (isEmpty())
	throw ReservationListEmpty();
    // Print pick up time for each node in the list
    NodePtr tmp = head;
    while (tmp) {
	tmp->data->printPickUpTime();
	cout << "------------\n";
	tmp = tmp->next;
    }
}
void ReservationList::removeEarliest() throw (ReservationListEmpty) {
    if (isEmpty())
	throw ReservationListEmpty();
    // Display earliest pick up time
    head->data->printPickUpTime();
    cout << "The information of this reservation has passed to "
	 << "a taxi driver.\n";
    // Delete head - the node with the earliest pick up time
    removeHead();
    // Increment processed
    processed++;
}
bool ReservationList::readReservations(string filename) {
    ifstream inputStream;
    inputStream.open(filename.c_str());
    if (inputStream.fail())
	return false;
    int numRecords;
    inputStream >> numRecords;
    for (int i = 0; i < numRecords; i++) {
	int hour, minute;
	string location, contact;
	inputStream >> hour >> minute;
	string garbage;
	getline(inputStream, garbage);
	getline(inputStream, location);
	getline(inputStream, contact);
	ReservationPtr data = new Reservation(hour, minute,
					      location, contact);
	insert(data);
    }
    inputStream.close();
    return true;
}
void ReservationList::writeReservations(string filename) {
    ofstream outputStream;
    outputStream.open(filename.c_str());
    if (!outputStream.fail()) {
	outputStream << count << endl;
	NodePtr tmp = head;
	while (tmp) {
	    outputStream << tmp->data->getHour() << " ";
	    outputStream << tmp->data->getMinute() << endl;
	    outputStream << tmp->data->getLocation() << endl;
	    outputStream << tmp->data->getContact() << endl;
	    tmp = tmp->next;
	}
    }
    outputStream.close();
}
// Private methods
void ReservationList::setUpFirstNodeWith(NodePtr node) {
    // Set node's next to head
    node->next = head;
    // Set node's prev to NULL indicating head
    node->prev = NULL;
    // Set head and tail to the first node
    head = node;
    tail = node;
}
void ReservationList::setTailTo(NodePtr node) {
    // Point new node's next to NULL indicating tail
    node->next = NULL;
    // Point current tail's next to new node
    tail->next = node;
    // Point new node's prev to current tail
    node->prev = tail;
    // Set tail to new node
    tail = node;
}
void ReservationList::setHeadTo(NodePtr node) {
    // Set node's next to current head
    node->next = head;
    // Set node's prev to NULL indicating head
    node->prev = NULL;
    // Set current head's prev to node
    head->prev = node;
    // Set head to new node
    head = node;
}
void ReservationList::insertBefore(NodePtr node, NodePtr after) {
    // Point after node's prev node's next to new node
    after->prev->next = node;
    // Point new node's prev to after node's prev
    node->prev = after->prev;
    // Point new node's next to after
    node->next = after;
    // Point after's prev to new node
    after->prev = node;
}
void ReservationList::removeHead() {
    // Create victim to remove
    NodePtr victim = head;
    // Set head to next node in the list
    head = head->next;
    // Check if list is not empty
    if (head)
	// Set new head prev to NULL indicating head of list
	head->prev = NULL;
    // Remove victim node
    delete victim->data;
    victim->data = NULL;
    victim->next = NULL;
    delete victim;
    victim = NULL;
}
