/*
 * File: country.cpp
 * Author: Joshua Tate
 * Date: April 3, 2018
 * Updated: April 10, 2018
 *
 * Purpose:
 *    - This file contains the main program.
 */
#include "dictionary.h"
#include "country.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm> // for transform
using namespace std;

// Global Constants
const string FILENAME = "wikiCountry.txt";
const string LIST = "list";
const string SHOW = "show";
const string ADD = "add";
const string REMOVE = "remove";
const string UPDATE = "update";
const string HELP = "help";
const string EXIT = "exit";

// Command enum
enum class Command {
    List, Show, Add, Remove, Update, Help, Exit
};

// Global Function Headers
// Reads contents of FILENAME into dict.
//  returns true if open is successful, otherwise returns false.
bool read(Dictionary<string, Country>& dict);
bool write(Dictionary<string, Country>& dict);
// Prints list of acceptable user commands to cout
void printMenu();
Command getUserCommand();
void convertToLowercase(string& s);
void listContentsOf(const Dictionary<string, Country>& dict);
void showCountry(const Dictionary<string, Country>& dict);
void addCountryTo(Dictionary<string, Country>& dict);
void removeCountryFrom(Dictionary<string, Country>& dict);
void updateCountryIn(Dictionary<string, Country>& dict);

/* MAIN */
int main() {
    // Read contents of wikiCountry.txt into Dictionary
    Dictionary<string, Country> dict;
    if (!read(dict))
	cout << "Could not open: " << FILENAME << endl
	     << "Starting with an empty wiki.\n";
    // Print valid user commands
    printMenu();
    bool running = true;
    while (running) {
	Command cmd = getUserCommand();
	switch (cmd) {
	case Command::List:
	    listContentsOf(dict);
	    break;
	case Command::Show:
	    showCountry(dict);
	    break;
	case Command::Add:
	    addCountryTo(dict);
	    break;
	case Command::Remove:
	    removeCountryFrom(dict);
	    break;
	case Command::Update:
	    updateCountryIn(dict);
	    break;
	case Command::Help:
	    printMenu();
	    break;
	case Command::Exit:
	    running = false;
	}
    }
    write(dict);
    return 0;
}
/* END MAIN */

// Function definitions
bool read(Dictionary<string, Country>& dict) {
    ifstream inputStream;
    inputStream.open(FILENAME);
    if (inputStream.fail())
	return false;
    int numberOfCountries;
    inputStream >> numberOfCountries;
    string garbage;
    getline(inputStream, garbage);
    for (int i = 0; i < numberOfCountries; i++) {
	CountryRef country = *(new Country);
	inputStream >> country;
	dict.insert(country.getName(), country);
    }
    inputStream.close();
    return true;
}
bool write(Dictionary<string, Country>& dict) {
    // ofstream outputStream;
    // outputStream.open(FILENAME);
    // if (outputStream.fail())
    // 	return false;
    return true;
}
void listContentsOf(const Dictionary<string, Country>& dict) {
    try {
	string* keys = dict.getKeys();
	for (int i = 0; i < dict.getSize(); i++)
	    cout << keys[i] << endl;
	delete [] keys;
    } catch (EmptyDictionary &e) {
	cout << "No countries in Wiki.\n";
    }
}
void showCountry(const Dictionary<string, Country>& dict) {
    string countryName;
    cout << "Please enter a country's full name: ";
    getline(cin, countryName);
    try {
	CountryRef country = dict.valueForKey(countryName);
	cout << country << endl;
    } catch (ValueNotFound& e) {
	cout << countryName << " doesn't exist in the Wiki.\n";
    }
}
void addCountryTo(Dictionary<string, Country>& dict) {
    string& countryName = *(new string);
    string garbage;
    cout << "Please enter a country's full name: ";
    getline(cin, countryName);
    if (dict.contains(countryName)) {
	cout << "This country is already in the Wiki.\n";
	delete &countryName;
	return;
    }
    // Set country's name
    CountryRef country = *(new Country);
    country.setName(countryName);
    // Set capital
    string& capital = *(new string);
    cout << "capital: ";
    getline(cin, capital);
    country.setCapital(capital);
    // Set language
    string& language = *(new string);
    cout << "language: ";
    getline(cin, language);
    country.setLanguage(language);
    // Set area
    double area;
    cout << "area: ";
    cin >> area;
    country.setArea(area);
    // Set population
    l_int pop;
    cout << "population: ";
    cin >> pop;
    country.setPopulation(pop);
    getline(cin, garbage);
    // Set description
    string& description = *(new string);
    cout << "description: ";
    getline(cin, description);
    country.setDescription(description);
    dict.insert(countryName, country);
    cout << "New country added into the Wiki.\n";
}
void removeCountryFrom(Dictionary<string, Country>& dict) {
    cout << "Please enter a country's full name: ";
    string key;
    getline(cin, key);
    try {
	CountryRef country = dict.remove(key);
	cout << "Country " << country.getName()
	     << " removed from the Wiki.\n";
	delete &country;
    } catch (ValueNotFound& e) {
	cout << "Country " << key << " doesn't exist in the Wiki.\n";
    }
}
void updateCountryIn(Dictionary<string, Country>& dict) {
    cout << "Updating a country...\n";
}
void printMenu() {
    cout << "Please enter list to show all countries' names\n"
	 << "       enter show to show a country's info\n"
	 << "       enter add to add a new country\n"
	 << "       enter remove to remove an existing country\n"
	 << "       enter update to update a country's info\n"
	 << "       enter help to see this menu\n"
	 << "       enter exit to terminate this program.\n";
}
Command getUserCommand() {
    Command cmd;
    do {
	cout << "--------------------------\n"
	     << "Enter your command choice: ";
	string s, garbage;
	cin >> s;
	getline(cin, garbage);
	convertToLowercase(s);
	if (s == LIST) {
	    cmd = Command::List;
	    break;
	} else if (s == SHOW) {
	    cmd = Command::Show;
	    break;
	} else if (s == ADD) {
	    cmd = Command::Add;
	    break;
	} else if (s == REMOVE) {
	    cmd = Command::Remove;
	    break;
	} else if (s == UPDATE) {
	    cmd = Command::Update;
	    break;
	} else if (s == HELP) {
	    cmd = Command::Help;
	    break;
	} else if (s == EXIT) {
	    cmd = Command::Exit;
	    break;
	} else {
	    cout << "Unknown command. Try again\n";
	}
    } while (true);
    return cmd;
}
void convertToLowercase(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}
