/*
 * Write a complete C++ program to compute and output the square roots
 *  of the whole numbers 1 to 10.
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        double sr = sqrt(i);
	cout << "Square root of " << i << " is " << sr << endl;
    }
    return 0;
}
