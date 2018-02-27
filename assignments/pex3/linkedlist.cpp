/*
 * File: linkedlist.cpp
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the implementation of a LinkedList
 */
#include <iostream>
#include "reservation.h"
#include "linkedlist.h"
using namespace std;

// Public methods
bool LinkedList::isEmpty() {
    return (head == NULL);
}
int LinkedList::getProcessed() const {
    return processed;
}
void LinkedList::insert(ReservationPtr data) {
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
}
void LinkedList::display() {
    if (isEmpty()) {
	printNoReservationsMessage();
    } else {
	// Print pick up time for each node in the list
	NodePtr tmp = head;
	while (tmp) {
	    tmp->data->printPickUpTime();
	    cout << "------------\n";
	    tmp = tmp->next;
	}
    }
}
void LinkedList::removeEarliest() {
    if (isEmpty()) {
	printNoReservationsMessage();
    } else {
	// Display earliest pick up time
	head->data->printPickUpTime();
	cout << "The information of this reservation has passed to "
	     << "a taxi driver.\n";
	// Delete head - the node with the earliest pick up time
	removeHead();
    }
}
// Private methods
void LinkedList::printNoReservationsMessage() {
    // Tell user there are reservations in the list
    cout << "\nThere is currently no reservation in the "
	 << "reservation list.\n\n";
}
void LinkedList::setUpFirstNodeWith(NodePtr node) {
    // Set node's next to head
    node->next = head;
    // Set node's prev to NULL indicating head
    node->prev = NULL;
    // Set head and tail to the first node
    head = node;
    tail = node;
}
void LinkedList::setTailTo(NodePtr node) {
    // Point new node's next to NULL indicating tail
    node->next = NULL;
    // Point current tail's next to new node
    tail->next = node;
    // Point new node's prev to current tail
    node->prev = tail;
    // Set tail to new node
    tail = node;
}
void LinkedList::setHeadTo(NodePtr node) {
    // Set node's next to current head
    node->next = head;
    // Set node's prev to NULL indicating head
    node->prev = NULL;
    // Set current head's prev to node
    head->prev = node;
    // Set head to new node
    head = node;
}
void LinkedList::insertBefore(NodePtr node, NodePtr after) {
    // Point after node's prev node's next to new node
    after->prev->next = node;
    // Point new node's prev to after node's prev
    node->prev = after->prev;
    // Point new node's next to after
    node->next = after;
    // Point after's prev to new node
    after->prev = node;
}
void LinkedList::removeHead() {
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
    // Increment processed
    processed++;
}
