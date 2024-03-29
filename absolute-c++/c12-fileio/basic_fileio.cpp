// Reads three numbers from the file infile.txt, sums the numbers,
//  and writes the sum of the file outfile.txt
#include <fstream>
using namespace std;

int main() {
    ifstream inStream;
    ofstream outStream;

    inStream.open("infile.txt");
    outStream.open("outfile.txt");

    int first, second, third;
    inStream >> first >> second >> third;
    outStream << "The sum of the first 3\n"
	      << "numbers in infile.txt\n"
	      << "is " << (first + second + third)
	      << endl;

    inStream.close();
    outStream.close();
    return 0;
}
