/*
 *  Consider a file of high scores. The first line is an integer that
 *   stores the number of records in the file.
 *
 *  The records alternate between the name of the player (first name only)
 *   and the player's score.
 *
 *  Write code that reads the file and outputs the player's name and score
 *   on one line, e.g.,
 *
 *     Gordon, 500
 *     Mario, 550
 *     Illidian, 385
 *
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int numberOfRecords;
    ifstream inputStream;

    inputStream.open("scores.txt");

    inputStream >> numberOfRecords;
    for (int i = 0; i < numberOfRecords; i++) {
	string name;
	int score;
	inputStream >> name;
	inputStream >> score;
	cout << name << ", " << score << endl;
    }

    inputStream.close();
    return 0;
}
