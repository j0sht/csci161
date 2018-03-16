/*
 * File: url.cpp
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 15, 2018
 *
 * Purpose:
 *    - This file contains the implementation of a URL
 */
#include "url.h"
#include <iostream>
using namespace std;

URL::URL(const string& s) {
    url = s;
}

ostream& operator <<(ostream& outs, const URL& u) {
    outs << u.url;
    return outs;
}
