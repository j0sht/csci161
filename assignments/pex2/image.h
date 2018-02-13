#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
using namespace std;

// Convenience type definitions
typedef int* IntArrayPtr;
typedef IntArrayPtr* TwoDIntArray;

class Image {
public:
    /* Constructors */
    // Creates an image object, whose title is an empty string and
    //  whose size is 0 rows and 0 columns
    Image();
    Image(string title, int rows, int columns, IntArrayPtr array);
    // Copy constructor
    Image(const Image &img);
    ~Image(); // destructor
    /* Getters/Setters */
    string getTitle();
    void setTitle(string s);
    int getRows();
    int getColumns();
    /* Operators */
    Image& operator =(const Image &rightSide);
    const Image operator +(const Image &i2) const throw (string);
    bool operator ==(const Image &i2) const;
    // I/O Friends
    friend ostream& operator <<(ostream &outs, const Image &img);
    friend istream& operator >>(istream &ins, Image &img);
    /* Member Functions */
    void histogram(int n) const;
private:
    // Member variables
    string title;
    int rows, columns;
    TwoDIntArray pixels;
    // Private member functions
    // Precondition: rows and columns are initialized to proper values
    void allocatePixels();
    // Precondition: rows and columns are initialized to proper values
    void deallocatePixels();
};
#endif
