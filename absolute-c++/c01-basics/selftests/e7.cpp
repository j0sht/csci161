/*
 * Write a complete C++ program that reads two whole numbers into two
 *  variables of type int and then outputs both the whole number part and
 *  the remainder when the first number is divided by the second.
 *
 * This can be done using the operators / and %.
 */
#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter two whole numbers: ";
    cin >> n1;
    cin >> n2;

    cout << n1 << " divided by " << n2
	 << " is " << (n1/n2) << " with a remainder of "
	 << (n1%n2) << endl;

    return 0;
}
