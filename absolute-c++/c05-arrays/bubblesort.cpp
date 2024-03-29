// Sorts an array of integers using Bubble Sort.
#include <iostream>
using namespace std;

// Precondition: length <= declared size of the array arr
//  The array elements arr[0] through a[length - 1] have values.
// Postcondition: The values of arr[0] through arr[length - 1] have
//  been rearranged so that arr[0] <= a[1] <= ... <= arr[length - 1]
void bubbleSort(int arr[], int length);

int main() {
    int a[] = {3, 10, 9, 2, 5, 1};
    bubbleSort(a, 6);
    for (int i = 0; i < 6; i++)
	cout << a[i] << " ";
    cout << endl;
    return 0;
}

void bubbleSort(int arr[], int length) {
    // Bubble largest number toward the right
    for (int i = length-1; i > 0; i--)
	for (int j = 0; j < i; j++)
	    if (arr[j] > arr[j+1]) {
		// Swap the numbers
		int temp = arr[j+1];
		arr[j+1] = arr[j];
		arr[j] = temp;
	    }
}
