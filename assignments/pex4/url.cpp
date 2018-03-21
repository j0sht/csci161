/*
 * File: url.cpp
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 20, 2018
 *
 * Purpose:
 *    - This file contains the implementation of the URL class.
 */
#include "url.h"
#include <iostream>
using namespace std;

URL::URL() {
    url = "";
}
URL::URL(const string& s) {
    url = s;
}
URL::URL(char* s) {
    url = string(s);
}
istream& operator >>(istream& ins, URL& u) {
    ins >> u.url;
    return ins;
}
ostream& operator <<(ostream& outs, const URL& u) {
    outs << u.url;
    return outs;
}
