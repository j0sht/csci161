// Shows the difference between each of a list of golf scores and
//  their average
#include <iostream>
using namespace std;

const int MAX_NUMBER_SCORES = 10;

// Precondition: size is the declared size of the array a
// Postcondition: numberUsed is the number of values stored in a.
//  a[0] through a[numberUsed-1] have been filled with non-negative
//  integers read from the keyboard
void fillArray(int a[], int size, int &numberUsed);

// Precondition: a[0] through a[numberUsed-1] have values
//  numberUsed > 0
// Returns the average of numbers a[0] through a[numberUsed-1]
double computeAverage(const int a[], int numberUsed);

// Precondition: The first numberUsed indexed variables of a have values.
// Postcondition: Gives screen output showing how much each of the first
//  numberUsed elements of the array differs from their average
void showDifference(const int a[], int numberUsed);

int main() {
    int score[MAX_NUMBER_SCORES], numberUsed;
    cout << "This program reads golf scores and shows\n"
	 << "how much each differs from the average.\n";
    cout << "Enter golf scores:\n";
    fillArray(score, MAX_NUMBER_SCORES, numberUsed);
    showDifference(score, numberUsed);
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

// const before an array parameter tells the compiler that the arrays
//  contents will not be modified by the function. If the function
//  attempts to modify the array or its contents, a compiler error
//  will be thrown.
double computeAverage(const int a[], int numberUsed) {
    double total = 0;
    for (int index = 0; index < numberUsed; index++)
	total += a[index];
    if (numberUsed > 0)
	return (total/numberUsed);
    else {
	cout << "ERROR: number of elements is 0 in computeAverage.\n"
	     << "computeAverage returns 0.\n";
	return 0;
    }
}

void showDifference(const int a[], int numberUsed) {
    double average = computeAverage(a, numberUsed);
    cout << "Average of the " << numberUsed
	 << " scores = " << average << endl
	 << "The scores are:\n";
    for (int index = 0; index < numberUsed; index++)
	cout << a[index] << " differs from average by "
	     << (a[index] - average) << endl;
}
