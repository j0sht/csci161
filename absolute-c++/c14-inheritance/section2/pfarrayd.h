// This is the header file pfarrayd.h.
// This is the interface for the class PFArrayD.
// Objects of this type are partially filled arrays of doubles.
#ifndef PFARRAYD_H
#define PFARRAYD_H
#include <iostream>
#include <cstdlib>
using namespace std;

// Object of this class are partially filled arrays of doubles
class PFArrayD {
public:
    PFArrayD(); // Initializes with a capacity of 50
    PFArrayD(int size);
    PFArrayD(const PFArrayD& pfaObject); // copy constructor
    ~PFArrayD();
    // Precondition: The array is not full
    // Postcondition: The element has been added
    void addElement(double element);
    // Returns true if the array is full, false otherwise
    bool full() const { return (capacity == used); }
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    // Empties the array
    void emptyArray() { used = 0; }
    // Read and change access to elements 0 through numberUsed - 1
    double& operator [](int index);
    // Overloaded assignment
    PFArrayD& operator =(const PFArrayD& rightSide);
protected:
    // Member variables are protected, and can be accessed
    //  directly by any subclasses.
    double *a; // for an array of doubles
    int capacity; // for the size of the array
    int used; // for the number of array positions currently in use
};
#endif
