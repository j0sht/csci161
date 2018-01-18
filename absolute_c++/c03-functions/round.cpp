#include <iostream>
#include <cmath>
using namespace std;

// Assumes number >= 0.
// Returns number rounded to the nearest integer.
int myRound(double number);

int main() {
    double doubleValue;
    char ans;
    do {
	cout << "Enter a double value: ";
	cin >> doubleValue;
	cout << "Rounded that number is " << myRound(doubleValue) << endl;
	cout << "Again? (y/n): ";
	cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << "End of testing.\n";
    return 0;
}

// Uses cmath
int myRound(double number) {
    int result = static_cast<int>(floor(number + 0.5));
    return result;
}
