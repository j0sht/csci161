/*
 * File: url.h
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 15, 2018
 *
 * Purpose:
 *    - This file contains the definition of a URL
 */
#ifndef URL_H
#define URL_H
#include <iostream>
using namespace std;

class URL {
public:
    URL();
    URL(const string& s);
    URL(char* s);
    friend istream& operator >>(istream& ins, URL& u);
    friend ostream& operator <<(ostream& outs, const URL& u);
private:
    string url;
};
typedef URL* URLPtr;
#endif
