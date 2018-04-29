// This is the file pfarraydbak.cpp.
// This is the implementation of the class PFArrayDBak
// The interface for the class PFArrayDBak is in the file pfarraydbak.h
#include "pfarraydbak.h"
#include <iostream>
using namespace std;

PFArrayDBak::PFArrayDBak(): PFArrayD(), usedB(0) {
    b = new double[capacity];
}
PFArrayDBak::PFArrayDBak(int capacityValue): PFArrayD(capacityValue),
					     usedB(0) {
    b = new double[capacity];
}
PFArrayDBak::PFArrayDBak(const PFArrayDBak& oldObject): PFArrayD(oldObject),
							usedB(0) {
    b = new double[capacity];
    usedB = oldObject.usedB;
    for (int i = 0; i < usedB; i++)
	b[i] = oldObject.b[i];
}
void PFArrayDBak::backup() {
    usedB = used;
    for (int i = 0; i < usedB; i++)
	b[i] = a[i];
}
void PFArrayDBak::restore() {
    used = usedB;
    for (int i = 0; i < used; i++)
	a[i] = b[i];
}
PFArrayDBak& PFArrayDBak::operator =(const PFArrayDBak& rightSide) {
    int oldCapacity = capacity;
    // Use a call to the base class assignment operator in order
    //  to assign to the base class member variables.
    PFArrayD::operator =(rightSide);
    if (oldCapacity != rightSide.capacity) {
	delete [] b;
	b = new double[rightSide.capacity];
    }
    usedB = rightSide.usedB;
    for (int i = 0; i < usedB; i++)
	b[i] = rightSide.b[i];

    return *this;
}

// The destructor for the base class PFArrayD is called automatically
//  and performs delete [] a.
PFArrayDBak::~PFArrayDBak() {
    delete [] b;
}
