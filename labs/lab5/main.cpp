#include "growing.h"
#include <iostream>
using namespace std;

int main() {
    // Test default constructor
    Growing a1;
    for (int i = 1; i <= 3; i++)
	a1.insert(static_cast<double>(i));
    a1.show();
    // Test other constructor
    Growing a2(3);
    for (int i = 1; i <= 3; i++)
	a2.insert(static_cast<double>(i));
    a2.show();
    // Check size
    cout << "a1 size: " << a1.getSize() << endl;
    cout << "a2 size: " << a2.getSize() << endl;
    // Check equality
    if (a1 == a2) {
	cout << "a1 and a2 have the same elements\n";
    } else {
	cout << "a1 and a2 do not have the same elements (WRONG)\n";
    }
    cout << "Inserting new element to a2\n";
    a2.insert(4.0);
    a1.show();
    a2.show();
    // Check equality
    if (a1 == a2) {
	cout << "a1 and a2 have the same elements (WRONG)\n";
    } else {
	cout << "a1 and a2 do not have the same elements\n";
    }
    return 0;
}
