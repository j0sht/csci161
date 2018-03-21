/*
 * File: urlstack.cpp
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 21, 2018
 *
 * Purpose:
 *    - This file contains the implementation of a URLStack
 */
#include <iostream>
#include "urlstack.h"
using namespace std;

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
