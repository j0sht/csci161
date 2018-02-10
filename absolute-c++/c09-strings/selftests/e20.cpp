/*
 * Write some C++ code that will read a line of text and echo the line
 *  with all uppercase letters deleted.
 */
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char next;
    do {
	cin.get(next);
	if (!isupper(next))
	    cout << next;
    } while (next != '\n');
    return 0;
}
