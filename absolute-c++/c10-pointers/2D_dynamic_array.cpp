// Program demonstrating 2D dynamic array
#include <iostream>
using namespace std;

typedef int* IntArrayPtr;
typedef IntArrayPtr* TwoDIntArray;

int main() {
    int d1, d2;
    cout << "Enter the row and column dimensions of the array:\n";
    cin >> d1 >> d2;

    TwoDIntArray m = new IntArrayPtr[d1];
    int i, j;
    for (i = 0; i < d1; i++)
	m[i] = new int[d2]; // m is now a d1-by-d2 array

    cout << "Enter " << d1 << " rows of "
	 << d2 << " integers each:\n";

    for (i = 0; i < d1; i++)
	for (j = 0; j < d2; j++)
	    cin >> m[i][j];

    cout << "Echoing the two-dimensional array:\n";
    for (i = 0; i < d1; i++) {
	for (j = 0; j < d2; j++)
	    cout << m[i][j] << " ";
	cout << endl;
    }

    for (i = 0; i < d1; i++)
	delete m[i]; // must be one call to delete for each array
    delete [] m;

    return 0;
}
