// Program to demonstrate pointers and dynamic variables
#include <iostream>
using namespace std;

int main() {
    int *p1, *p2; // declare to variables of type int*

    p1 = new int; // Point p1 to a nameless variable
    *p1 = 42; // Set value that p1 points to to 42
    p2 = p1; // Point p2 to value that p1 points too
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    *p2 = 53;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    p1 = new int;
    *p1 = 88;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    cout << "Hope you got the point of this example!\n";
    return 0;
}
