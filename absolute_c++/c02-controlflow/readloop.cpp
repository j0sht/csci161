#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string text;
    fstream inputStream;

    inputStream.open("player.txt");

    while (inputStream >> text) // false when EOF reached
	cout << text << endl;

    inputStream.close();

    return 0;
}
