#include "growing.h"
#include <iostream>
using namespace std;

Growing::Growing() {
    capacity = 2;
    size = 0;
    array = new double[capacity];
}

Growing::Growing(int size) {
    this->capacity = size;
    this->size = 0;
    array = new double[capacity];
}

Growing::~Growing() {
    delete [] array;
}

void Growing::insert(double n) {
    if (size == capacity) {
	// Allocate new array with double the current capacity
	capacity *= 2;
	double *tmp = new double[capacity];
	// Copy elements of old array into new one
	for (int i = 0; i < size; i++)
	    tmp[i] = array[i];
	// Set array to newly allocated array
	delete [] array;
	array = tmp;
    }
    // Insert n
    array[size++] = n;
}

void Growing::show() {
    cout << "Contents of array:\n";
    for (int i = 0; i < size; i++)
	cout << array[i] << " ";
    cout << endl;
}

int Growing::getSize() {
    return size;
}

bool Growing::operator ==(const Growing &other) {
    if (size != other.size)
	return false;
    for (int i = 0; i < size; i++)
	if (array[i] != other.array[i])
	    return false;
    return true;
}
