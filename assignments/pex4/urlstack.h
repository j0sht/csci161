/*
 * File: urlstack.h
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 21, 2018
 *
 * Purpose:
 *    - This file contains the definition of a URLStack.
 */
#ifndef URLSTACK_H
#define URLSTACK_H
#include "url.h"
#include <iostream>
using namespace std;

// Error class
class EmptyStack {};

class URLStack {
public:
    // Initializes head to NULL, count to 0
    URLStack();
    // Initializes stack with url in it
    URLStack(URLRef url);
    ~URLStack();
    // Property methods
    int getCount() const { return count; }
    bool isEmpty() const { return head == NULL; }
    // Action methods
    // Removes and returns last entered URL
    URLRef pop() throw (EmptyStack);
    // Returns last entered URL
    URLRef peek() const throw (EmptyStack);
    // Adds url to the top of the stack
    void push(URLRef url);
    // Deletes all urls in the stack
    void deleteAll();
private:
    struct Node {
	URLPtr data;
	Node* next;
    };
    typedef Node* NodePtr;
    NodePtr head;
    int count;
    void initializeEmpty() {
	head = NULL;
	count = 0;
    }
};
#endif
