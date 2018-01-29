/*
 * Write a function named outOfOrder that takes as parameters an array
 *  of double and an int parameter named size and returns a value of
 *  type int.
 *
 * This function will test this array for being out of order, meaning
 *  that the array violates the following condition:
 *  a[0] <= a[1] <= a[2] <= ...
 *
 * The function returns -1 if the elements are not out of order; otherwise,
 *  it will return the index of the first element of the array that is
 *  out of order.
 */
#include <iostream>
using namespace std;

int outOfOrder(double a[], int size);

int main() {
    double a[10] = {1.2, 2.1, 3.3, 2.5, 4.5,
		    7.9, 5.4, 8.7, 9.9, 1.0};
    double b[4] = { 1.0, 2.0, 3.0, 4.0 };
    int index = outOfOrder(a, 10);
    cout << "index = 3? " << (index == 3) << endl;
    index = outOfOrder(b, 4);
    cout << "index = -1? " << (index == -1) << endl;
    return 0;
}

int outOfOrder(double a[], int size) {
    double first = a[0];
    for (int i = 1; i < size; i++) {
	if (first > a[i])
	    return i;
	first = a[i];
    }
    return -1;
}
