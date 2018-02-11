// Program demonstrating how to return an array from a function
#include <iostream>
using namespace std;

typedef int* IntPtr;

// Precondition: size is the size of the array a
// All indexed variables of a have values
// Returns: a pointer to an array of the same size as a in which
//  each indexed variable is double the corresponding element in a.
IntPtr doubler(int a[], int size);

int main() {
    int a[] = {1, 2, 3, 4, 5};
    IntPtr b;

    b = doubler(a, 5);

    int i;
    cout << "Array a:\n";
    for (i = 0; i < 5; i++)
	cout << a[i] << " ";
    cout << endl;
    cout << "Array b:\n";
    for (i = 0; i < 5; i++)
	cout << b[i] << " ";
    cout << endl;

    // This call to delete is not really needed since the program
    //  is ending. In another context it could be important to
    //  include this delete.
    delete [] b;
    return 0;
}

IntPtr doubler(int a[], int size) {
    IntPtr tmp = new int[size];

    for (int i = 0; i < size; i++)
	tmp[i] = 2 * a[i];

    return tmp;
}
