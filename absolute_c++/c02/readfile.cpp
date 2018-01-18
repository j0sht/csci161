#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // string class included in iostream
    string firstName, lastName;
    int score;
    fstream inputStream;
    string filename = "player.txt";

    // need to convert string object to c string
    //  to work with fstream.open
    inputStream.open(filename.c_str());

    inputStream >> score;
    inputStream >> firstName >> lastName;

    cout << "Name: " << firstName << " "
	 << lastName << endl;
    cout << "Score: " << score << endl;
    inputStream.close();

    return 0;
}
