#include <iostream>
#include <cstdlib>
using namespace std;

class CharPair {
public:
    CharPair() {}
    CharPair(char firstVal, char secondVal): first(firstVal),
					     second(secondVal) {}

    // If you want to use [] in an expression on the left-hand side
    //  of an assignment operator, then the operator must be defined
    //  to return a reference.
    // NOTE: the operator [] must be a member function
    // NOTE: the index parameter must be an integer type
    char& operator [](int index);
private:
    char first, second;
};

int main() {
    CharPair a;
    a[1] = 'A';
    a[2] = 'B';
    cout << "a[1] and a[2] are:\n";
    cout << a[1] << a[2] << endl;
    cout << "Enter two letters (no spaces):\n";
    cin >> a[1] >> a[2];
    cout << "You entered:\n";
    cout << a[1] << a[2] << endl;
    return 0;
}

// Uses iostream and cstdlib
char& CharPair::operator [](int index) {
    if (index == 1)
	return first;
    else if (index == 2)
	return second;
    else {
	cout << "Illegal index value.\n";
	exit(1);
    }
}
