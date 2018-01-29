#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "Hello Out There!\n";
    // By convention, 1 is used for a call to exit that is caused by an
    //  error, and 0 is used in other cases.
    exit(1);

    cout << "This statement is pointless,\n"
	 << "because it will never be eecuted.\n"
	 << "This is just a toy program to illustrate exit.\n";
    return 0;
}
