/*
 * Write a function definition for a function called oneMore, which has
 *  a formal parameter for an array of integers and increases the value
 *  of each array element by 1. Add any other formal parameters that
 *  are needed.
 */
#include <iostream>
using namespace std;

void oneMore(int a[], int size);

int main() {
    int a[5] = { 1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
	cout << "a[" << i << "] = " << a[i] << endl;
    oneMore(a, 5);
    cout << "\nAfter oneMore:\n";
    for (int i = 0; i < 5; i++)
	cout << "a[" << i << "] = " << a[i] << endl;
    return 0;
}

void oneMore(int a[], int size) {
    for (int i = 0; i < size; i++)
	a[i]++;
}
