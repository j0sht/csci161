#include <iostream>
using namespace std;

int main() {
    int numberOfLanguages;

    // Text enclosed in double quotes is a C-string
    // cout displays text to the console
    cout << "Hello reader.\n"
	 << "Welcome to C++.\n";

    cout << "How many programming languages have you used? ";
    // cin reads from stdin into variable on right of >>
    cin >> numberOfLanguages;

    if (numberOfLanguages < 1)
	cout << "Read the preface. You may prefer\n"
	     << "a more elementary book by the same author.\n";
    else
	cout << "Enjoy the book.\n";

    return 0;
}
