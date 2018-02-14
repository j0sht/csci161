/*
 * File: image.h
 * Author: Joshua Tate
 * Date: February 9, 2018
 * Updated: February 14, 2018
 *
 * Purpose:
 *    - This file contains the definition for an Image class.
 *    - Image represents grayscale images, consisting of a two dimensional
 *      array of 'pixels' whose values are between 0 and 255 inclusive.
 *    - Image holds a title, the number of rows and columns, and an
 *      array consisting of the pixels.
 */
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
    // '+' returns an Image whose content consists of the average of
    //  the two corresponding pixels in this and i2.
    // '+' throws a string "Incompatible size" if this and i2 do not
    //  have the same number of rows and columns
    const Image operator +(const Image &i2) const throw (string);
    // '==' returns true if this and i2 have the same content,
    //  regardless of title, otherwise returns false.
    bool operator ==(const Image &i2) const;
    // I/O Friends
    friend ostream& operator <<(ostream &outs, const Image &img);
    friend istream& operator >>(istream &ins, Image &img);
    /* Member Functions */
    // histogram displays the number of pixels between 0 to (256/n)-1,
    //  (256/n) to 2*(256/n)-1, ..., (n-1) * (256/n) to 255.
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
