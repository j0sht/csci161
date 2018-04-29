#include "pfarrayd.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Definition for the member functions for the class PFArrayD
// They require the following include and using directives:
// #include <iostream>
// #include <cstdlib>
// using std::cout;
PFArrayD::PFArrayD(): capacity(50), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(int size): capacity(size), used(0) {
    a = new double[capacity];
}

// Copy constructor
PFArrayD::PFArrayD(const PFArrayD& pfaObject) {
    capacity = pfaObject.capacity;
    used = pfaObject.used;
    a = new double[capacity];
    for (int i = 0; i < used; i++)
	a[i] = pfaObject.a[i];
}

void PFArrayD::addElement(double element) {
    if (used >= capacity) {
	cout << "Attempt to exceed capacity in PFArrayD.\n";
	exit(0);
    }
    a[used] = element;
    used++;
}

double& PFArrayD::operator [](int index) {
    if (index >= used) {
	cout << "Illegal index in PFArrayD.\n";
	exit(0);
    }
    return a[index];
}

// Overloaded assignment
PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide) {
    // Also checks for the case of have the same object
    //  on both sides of the assignment operator
    if (capacity != rightSide.capacity) {
	delete [] a;
	a = new double[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
	a[i] = rightSide.a[i];

    return *this;
}

PFArrayD::~PFArrayD() {
    delete [] a;
}
