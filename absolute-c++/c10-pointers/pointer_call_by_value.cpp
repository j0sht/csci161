// Program to demonstrate the way call-by-value parameters
//  behave with pointer arguments
#include <iostream>
using namespace std;

typedef int* IntPtr;

void sneaky(IntPtr tmp);

int main() {
    IntPtr p;

    p = new int;
    *p = 77;
    cout << "Before call to function *p == " << *p << endl; // 77

    sneaky(p);

    cout << "After call to function *p == " << *p << endl; // 99

    return 0;
}

void sneaky(IntPtr tmp) {
    *tmp = 99;
    cout << "Inside function call *tmp == " << *tmp << endl; // 99
}
