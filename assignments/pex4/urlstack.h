/*
 * File: urlstack.h
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 15, 2018
 *
 * Purpose:
 *    - This file contains the definition of a Stack
 */
#ifndef URLSTACK_H
#define URLSTACK_H
#include "url.h"
#include <iostream>
using namespace std;

// Error class
class EmptyStack {
public:
    friend ostream& operator <<(ostream& outs, const EmptyStack& e);
};

class URLStack {
public:
    URLStack();
    ~URLStack();
    URLPtr pop() throw (EmptyStack);
    const URL& peek() const throw (EmptyStack);
    void push(URLPtr url);
    void dump();
    int getCount() const { return count; }
    bool isEmpty() const { return head == NULL; }
    
    // Debug
    void display() const;
private:
    struct Node {
	URLPtr data;
	Node* next;
    };
    typedef Node* NodePtr;
    NodePtr head;
    int count;
};
#endif
