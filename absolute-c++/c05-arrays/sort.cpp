// Tests selection sort
#include <iostream>
using namespace std;

// Precondition: size is the declared size of the array a
// Postcondition: numberUsed is the number of values stored in a.
//  a[0] through a[numberUsed-1] have been filled with non-negative
//  integers read from the keyboard
void fillArray(int a[], int size, int &numberUsed);

// Precondition: numberUsed <= declared size of the array a
//  The array elements a[0] through a[numberUsed - 1] have values.
// Postcondition: The values of a[0] through a[numberUsed - 1] have
//  been rearranged so that a[0] <= a[1] <= ... <= a[numberUsed - 1]
void sort(int a[], int numberUsed);

// Interchanges the values of v1 and v2
void swapValues(int &v1, int &v2);

// Precondition: 0 <= startIndex < numberUsed. Reference array elements
//  have values. Returns the index i such that a[i] is the smallest of
//  the values a[startIndex], a[startIndex - 1], ..., a[numberUsed - 1]
int indexOfSmallest(const int a[], int startIndex, int numberUsed);

int main() {
    cout << "This program sorts numbers from lowest to highest.\n";

    int sampleArray[10], numberUsed;
    fillArray(sampleArray, 10, numberUsed);
    sort(sampleArray, numberUsed);

    cout << "In sorted order the numbers are:\n";
    for (int index = 0; index < numberUsed; index++)
	cout << sampleArray[index] << " ";
    cout << endl;
    return 0;
}

void fillArray(int a[], int size, int &numberUsed) {
    cout << "Enter up to " << size << " non-negative whole numbers.\n"
	 << "Mark the end of the list with a negative number.\n";
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size)) {
	a[index] = next;
	index++;
	cin >> next;
    }
    numberUsed = index;
}

void sort(int a[], int numberUsed) {
    int indexOfNextSmallest;
    for (int index = 0; index < numberUsed - 1; index++) {
	indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);
	swapValues(a[index], a[indexOfNextSmallest]);
    }
}

void swapValues(int &v1, int &v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

int indexOfSmallest(const int a[], int startIndex, int numberUsed) {
    int min = a[startIndex], indexOfMin = startIndex;
    for (int index = startIndex + 1; index < numberUsed; index++)
	if (a[index] < min) {
	    min = a[index];
	    indexOfMin = index;
	}
    return indexOfMin;
}
