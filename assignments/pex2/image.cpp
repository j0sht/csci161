#include "image.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* Static variables */
int Image::maxRows = 1024;
int Image::maxColumns = 1024;

/* Static methods */
int Image::getMaxRows() {
    return maxRows;
}
int Image::getMaxColumns() {
    return maxColumns;
}

/* Constructors */
Image::Image() {
    title = "";
    rows = columns = 0;
    pixels = NULL;
}
Image::Image(string title, int rows, int columns, IntArrayPtr array) {
    this->title = title;
    this->rows = rows;
    this->columns = columns;
    allocatePixels();
    for (int i = 0; i < rows; i++)
	for (int j = 0; j < columns; j++)
	    pixels[i][j] = array[i*columns + j];
}
// Copy Constructor
Image::Image(const Image &img) {
    title = img.title;
    rows = img.rows;
    columns = img.columns;
    allocatePixels();
    for (int i = 0; i < rows; i++)
	for (int j = 0; j < columns; j++)
	    pixels[i][j] = img.pixels[i][j];
}
// Destructor
Image::~Image() {
    deallocatePixels();
}

/* Member functions */
// Public member functions
void Image::histogram(int n) const {
    cout << "HISTOGRAM:\n";
    int increment = (256 / n);
    for (int x = 1, y = n; x <= n; x++, y--) {
	int lower = (n - y) * increment;
	int upper = (x == n) ? 255 : (x * increment) - 1;
	int count = 0;
	for (int i = 0; i < rows; i++)
	    for (int j = 0; j < columns; j++)
		if ((pixels[i][j] >= lower) && (pixels[i][j] <= upper))
		    count++;
	cout << setw(3) << right << lower << " to "
	     << setw(3) << right << upper << ": "
	     << count << endl;
    }
}
// Private member functions
void Image::allocatePixels() {
    pixels = new IntArrayPtr[rows];
    for (int i = 0; i < rows; i++)
	pixels[i] = new int[columns];
}
void Image::deallocatePixels() {
    if (pixels) {
	for (int i = 0; i < rows; i++)
	    delete pixels[i];
	delete [] pixels;
    }
}

/* Operators */
// Assignment
Image& Image::operator =(const Image &rightSide) {
    if (this == &rightSide) { // check if same object is on both sides of assignment
	return *this;
    } else {
	title = rightSide.title;
	deallocatePixels();
	rows = rightSide.rows;
	columns = rightSide.columns;
	allocatePixels();
	for (int i = 0; i < rows; i++)
	    for (int j = 0; j < columns; j++)
		pixels[i][j] = rightSide.pixels[i][j];
	return *this;
    }
}
// Addition
const Image Image::operator +(const Image &i2) const throw (string) {
    if ((rows != i2.rows) || (columns != i2.columns))
	throw string("Incompatible size");
    string newTitle = title + " + " + i2.title;
    IntArrayPtr newPixels = new int[rows * columns];
    for (int i = 0; i < rows; i++) {
	for (int j = 0; j < columns; j++) {
	    int thisPixel = pixels[i][j];
	    int otherPixel = i2.pixels[i][j];
	    int average = (thisPixel + otherPixel) / 2;
	    newPixels[i*columns + j] = average;
	}
    }
    return Image(newTitle, rows, columns, newPixels);
}
// Equality operator
bool Image::operator ==(const Image &i2) const {
    if ((rows != i2.rows) || (columns != i2.columns))
	return false;
    for (int i = 0; i < rows; i++)
	for (int j = 0; j < columns; j++)
	    if (pixels[i][j] != i2.pixels[i][j])
		return false;
    return true;
}

/* Image I/O */
ostream& operator <<(ostream &outs, const Image &img) {
    outs << "TITLE: " << img.title << endl;
    outs << "SIZE: " << img.rows << " by " << img.columns << endl;
    outs << "CONTENT:\n";
    for (int i = 0; i < img.rows; i++) {
	for (int j = 0; j < img.columns; j++)
	    outs << setw(7) << left << img.pixels[i][j] << " ";
	if (i != (img.rows-1))
	    outs << endl;
    }
    return outs;
}
istream& operator >>(istream &ins, Image &img) {
    // Deallocate pixels if it already exists
    img.deallocatePixels();
    cout << "Enter image title:\n";
    char newLine;
    if (ins.peek() == '\n')
	ins.get(newLine);
    getline(ins, img.title);
    cout << "Enter rows and columns:\n";
    ins >> img.rows >> img.columns;
    img.allocatePixels();
    cout << "Enter content:\n";
    for (int i = 0; i < img.rows; i++)
	for (int j = 0; j < img.columns; j++)
	    ins >> img.pixels[i][j];
    return ins;
}
