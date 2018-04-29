// Write the definition for a void function called toScreen
// The function toScreen has one formal parameter called fileStream,
//  which is of type ifstream.
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// Precondition: The stream fileStream has been connected
//  to a file with a call to the member function open. The
//  file contains a list of integers (and nothing else).
// Postcondition: The numbers in the file connected to
//  fileStream have been written to the screen one per line.
//  (This function does not close the file.)
void toScreen(ifstream& fileStream) {
    int next;
    while (fileStream >> next)
	cout << next << endl;
}

int main() {
    ifstream fin;
    fin.open("list.txt");
    if (fin.fail()) {
	cout << "Could not open file list.txt\n";
	exit(1);
    }
    toScreen(fin);
    fin.close();
    return 0;
}
