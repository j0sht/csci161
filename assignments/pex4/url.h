/*
 * File: url.h
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 20, 2018
 *
 * Purpose:
 *    - This file contains the definition of a URL, which is a symbolic
 *      wrapper class of the string type.
 */
#ifndef URL_H
#define URL_H
#include <iostream>
using namespace std;

class URL {
public:
    // Initializes url property to empty string
    URL();
    // Initiliazes url property to s
    URL(const string& s);
    URL(char* s);
    // I/O friend functions
    friend istream& operator >>(istream& ins, URL& u);
    friend ostream& operator <<(ostream& outs, const URL& u);
private:
    string url;
};
typedef URL* URLPtr;
typedef URL& URLRef;
#endif
