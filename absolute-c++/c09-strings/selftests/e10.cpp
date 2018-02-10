/*
 * Write code using a library function to copy the string constant
 *  "Hello" into the string variable char aString[10]
 */
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char aString[10];
    strncpy(aString, "Hello", 10);
    cout << "aString = " << aString << endl;
    return 0;
}
