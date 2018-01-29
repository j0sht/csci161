/*
 *  Write some C++ code that will fill an array with 20 values of type
 *   int read in from the keyboard.
 */
#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

int main() {
    int array[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
	cout << "Enter number: ";
	cin >> array[i];
    }
    cout << "You entered:\n";
    // Range based for loop:
    // Requires compilation with C++ 11 (-std=c++11)
    for (int i : array)
	cout << '\t' << i << endl;
    return 0;
}
