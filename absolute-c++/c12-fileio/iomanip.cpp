// Reads all the numbers in the file rawdata.txt and writes the numbers
//  to the screen and to the file neat.txt in a neatly formatted way
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip> // needed for setw
using namespace std;

// Precondition: The streams messyFile and neatFile have been connected
//  to two different files. The file named messyFile contains only
//  floating-point numbers.
// Postcondition: The numbers in the file connected to messyFile have
//  been written to the screen and to the file connected to the stream
//  neatFile. The numbers are written one per line, in fixed-point
//  notation (that is, not in e-notation), with numberAfterDecimalPoint
//  digits after the decimal point; each number is preceded by a plus or
//  minus sign and each number is in a field of width fieldWidth.
//  (This function does not close the file.)
void makeNeat(ifstream& messyFile, ofstream& neatFile,
	      int numberAfterDecimalPoint, int fieldWidth);

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("rawdata.txt");
    if (fin.fail()) {
	cout << "Input file opening failed.\n";
	exit(1);
    }

    fout.open("neat.txt");
    if (fout.fail()) {
	cout << "Output file opening failed.\n";
	exit(1);
    }

    makeNeat(fin, fout, 5, 12);

    fin.close();
    fout.close();
    cout << "End of program.\n";
    return 0;
}

// Uses <iostream>, <fstream>, and <iomanip>
void makeNeat(ifstream& messyFile, ofstream& neatFile,
	      int numberAfterDecimalPoint, int fieldWidth) {
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint);
    neatFile.setf(ios::showpos);
    neatFile.precision(numberAfterDecimalPoint);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(numberAfterDecimalPoint);

    double next;
    while (messyFile >> next) {
	cout << setw(fieldWidth) << next << endl;
	neatFile << setw(fieldWidth) << next << endl;
    }
}
