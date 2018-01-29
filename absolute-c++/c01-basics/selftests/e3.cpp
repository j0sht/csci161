/*
 * Write a program that contains statements that output the values of
 *  five or six variables that have been defined, but not initialized.
 *
 * Compile and run the program. What is the output? Explain.
 *
 * (Because the variables are not initialized they contain garbage values)
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, y;
    double a, c;
    bool d;
    string s;

    cout << "ints:    " << x << " " << y << endl;
    cout << "doubles: " << a << " " << c << endl;
    cout << "bool:    " << d << endl;
    cout << "string:  " << s << endl;

    return 0;
}
