/*
 *  Modify your solution to exercise 39 to output only the name and score
 *   of the player with the highest score.
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int numberOfRecords;
    int highestScore = 0;
    string nameWithHighestScore;
    ifstream inputStream;

    inputStream.open("scores.txt");

    inputStream >> numberOfRecords;
    for (int i = 0; i < numberOfRecords; i++) {
	string name;
	int score;
	inputStream >> name;
	inputStream >> score;
	if (score > highestScore) {
	    highestScore = score;
	    nameWithHighestScore = name;
	}
    }
    cout << "Highest score: "
	 << nameWithHighestScore << ", " << highestScore << endl;

    inputStream.close();
    return 0;
}
