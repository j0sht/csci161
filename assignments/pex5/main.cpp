/*
 * File: country.cpp
 * Author: Joshua Tate
 * Date: April 3, 2018
 * Updated: April 3, 2018
 *
 * Purpose:
 *    - This file contains the main program.
 */
#include "country.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    ifstream inputStream;
    inputStream.open("wikiCountry.txt");
    if (inputStream.fail()) {
	cout << "Couldn't open file.\n";
	exit(1);
    }
    int numberOfCountries;
    inputStream >> numberOfCountries;
    string garbage;
    getline(inputStream, garbage);
    Country** countries = new Country*[numberOfCountries];
    for (int i = 0; i < numberOfCountries; i++) {
	countries[i] = new Country;
	inputStream >> *(countries[i]);
    }
    inputStream.close();
    for (int i = 0; i < numberOfCountries; i++) {
	cout << *(countries[i]) << endl;
	delete countries[i];
    }
    delete [] countries;
    return 0;
}
