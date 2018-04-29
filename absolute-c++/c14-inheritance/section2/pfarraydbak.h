// This is the header file pfarraydbak.h.
// This is the interface for the class PFArrayDBak. Objects of this
//  type are partially filled arrays of doubles.
// This version allows the programmer to make a backup copy and restores
//  to the last saved copy of the partially filled array.
#ifndef PFARRAYDBAK_H
#define PFARRAYDBAK_H
#include "pfarrayd.h"

class PFArrayDBak: public PFArrayD {
public:
    PFArrayDBak(); // Intializes with a capacity of 50.
    PFArrayDBak(int capacityValue);
    // Copy constructor
    PFArrayDBak(const PFArrayDBak& obj);
    // Makes a backup copy of the partially filled array
    void backup();
    // Restores the partially filled array to the last saved version
    void restore();
    // If backup has never been invoked, this empties the partially
    //  filled array.
    PFArrayDBak& operator =(const PFArrayDBak& rightSide);
    ~PFArrayDBak();
private:
    double *b; // for backup of main array.
    int usedB; // backup for inherited member variable used.
};
#endif
