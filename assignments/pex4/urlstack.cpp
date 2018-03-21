/*
 * File: urlstack.cpp
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 20, 2018
 *
 * Purpose:
 *    - This file contains the implementation of a Stack
 */
#include <iostream>
#include "urlstack.h"
using namespace std;

// Error class << overload
ostream& operator <<(ostream& outs, const EmptyStack& e) {
    outs << "ERROR: Empty stack";
    return outs;
}

// Constructor & Destructor
URLStack::URLStack() {
    initializeEmpty();
}
URLStack::URLStack(URLRef url) {
    initializeEmpty();
    push(url);
}
URLStack::~URLStack() {
    deleteAll();
}

// Public Methods
URLRef URLStack::pop() throw (EmptyStack) {
    if (isEmpty())
	throw EmptyStack();
    NodePtr tmp = head;
    head = head->next;
    URLPtr url = tmp->data;
    delete tmp;
    count--;
    return *url;
}
URLRef URLStack::peek() const throw (EmptyStack) {
    if (isEmpty())
	throw EmptyStack();
    return *(head->data);
}
void URLStack::push(URLRef url) {
    NodePtr newNode = new Node;
    newNode->data = &url;
    newNode->next = head;
    head = newNode;
    count++;
}
void URLStack::deleteAll() {
    while (head) {
	URLRef url = pop();
	delete &url;
    }
}

// Private methods
void URLStack::initializeEmpty() {
    head = NULL;
    count = 0;
}

// Debug
void URLStack::display() const {
    NodePtr tmp = head;
    cout << "==============================\n";
    for (int i = count; tmp; i--, tmp = tmp->next)
	cout << "URL " << i << ": "
	     << *(tmp->data) << endl;
    cout << "==============================\n";
}
