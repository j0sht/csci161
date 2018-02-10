// Demonstrates the standard class string
#include <iostream>
#include <string>
using namespace std;

int main() {
    string phrase; // Initialized to the empty string
    string adjective("fried"), noun("ants"); // Initial value v1
    string wish = "Bon appetite!"; // Initial value v2

    // Can concatenate string with +
    phrase = "I love " + adjective + " " + noun + "!";
    cout << phrase << endl
	 << wish << endl;
    return 0;
}
