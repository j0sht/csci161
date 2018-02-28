/*
 * File: reservationlist.cpp
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

// Error Class output overload
ostream& operator <<(ostream& outs, const ReservationListEmpty &e) {
    outs << "\nThere is currently no reservation in the "
	 << "reservation list.\n";
    return outs;
}

// Constructor
ReservationList::ReservationList() {
    head = NULL;
    tail = NULL;
    processed = count = 0;
}
ReservationList::~ReservationList() {
    while (head) {
	ReservationPtr data = removeHead();
	delete data;
    }
}
// Public methods
bool ReservationList::empty() const {
    return (head == NULL);
}
int ReservationList::getProcessed() const {
    return processed;
}
int ReservationList::getCount() const {
    return count;
}
void ReservationList::insert(ReservationPtr data) {
    NodePtr node = new Node;
    node->data = data;
    if (empty())
	setUpFirstNodeWith(node);
    else {
	NodePtr tmp = head;
	// Search for position based on pick up time
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
    if (empty())
	throw ReservationListEmpty();
    NodePtr tmp = head;
    while (tmp) {
	tmp->data->displayPickUpTime();
	cout << "------------\n";
	tmp = tmp->next;
    }
}
ReservationPtr ReservationList::removeEarliest() throw (ReservationListEmpty) {
    if (empty())
	throw ReservationListEmpty();
    ReservationPtr data = removeHead();
    processed++;
    return data;
}
bool ReservationList::readReservationsFrom(string filename) {
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
void ReservationList::writeReservationsTo(string filename) {
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
    node->next = head;
    node->prev = NULL;
    head = node;
    tail = node;
}
void ReservationList::setTailTo(NodePtr node) {
    node->next = NULL;
    tail->next = node;
    node->prev = tail;
    tail = node;
}
void ReservationList::setHeadTo(NodePtr node) {
    node->next = head;
    node->prev = NULL;
    head->prev = node;
    head = node;
}
void ReservationList::insertBefore(NodePtr node, NodePtr after) {
    after->prev->next = node;
    node->prev = after->prev;
    node->next = after;
    after->prev = node;
}
ReservationPtr ReservationList::removeHead() {
    NodePtr victim = head;
    head = head->next;
    if (head)
	head->prev = NULL;
    ReservationPtr data = victim->data;
    victim->data = NULL;
    victim->next = NULL;
    delete victim;
    victim = NULL;
    count--;
    return data;
}
