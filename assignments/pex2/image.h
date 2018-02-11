#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
using namespace std;

typedef int* IntArrayPtr;
typedef IntArrayPtr* TwoDIntArray;

class Image {
public:
    static int getMaxRows();
    static int getMaxColumns();
    // Creates an image object, whose title is an empty string and
    //  whose size is 0 rows and 0 columns
    Image();
    Image(string title, int rows, int columns, IntArrayPtr array);
    Image(const Image &img); // copy constructor
    ~Image(); // destructor

    Image& operator =(const Image &rightSide);
    const Image operator +(const Image &i2) const throw (string);
    bool operator ==(const Image &i2) const;

    friend ostream& operator <<(ostream &outs, const Image &img);
    friend istream& operator >>(istream &ins, Image &img);

    void histogram(int n) const;
private:
    static int maxRows, maxColumns;
    // Member variables
    string title;
    int rows, columns;
    TwoDIntArray pixels;
};
#endif
