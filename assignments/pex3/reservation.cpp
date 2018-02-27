/*
 * File: reservation.cpp
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the definition of a Reservation
 */
#include <iostream>
#include <iomanip>
#include "reservation.h"
using namespace std;

// Public methods
void Reservation::userSetValues() {
    hour = getValidHour();
    minute = getValidMinute();
    location = getValidString("Please enter the pick up location\n");
    contact = getValidString("Please enter the name of the contact\n");
}
void Reservation::printPickUpTime() {
    // Display reservation data
    cout << "    pick up time: "
	 << hour << ":" << setfill('0') << setw(2) << minute << endl
	 << "pick up location: " << location << endl
	 << "    contact name: " << contact << endl;
}
int Reservation::getTime() {
    // Return total minutes
    return (hour * 60) + minute;
}
bool Reservation::timeIsLessThan(ReservationPtr other) {
    return this->getTime() < other->getTime();
}
// Private methods
int Reservation::getIntInRange(int min, int max, string prompt) {
    // val represents value to be returned
    int val;
    // valid is set to true when user enters a value in range min..max
    bool valid = false;
    // garbage will hold extraneous data in cin
    string garbage;
    // Display prompt
    cout << prompt;
    while (!valid) {
	// Get value
	cin >> val;
	// Collect garbage
	getline(cin, garbage);
	// Set valid to true if val in range min..max
	valid = ((val >= min) && (val <= max));
	// If not valid, explain to user value must be in range min..max
	if (!valid)
	    cout << "The number must be in the range of "
		 << min << " and " << max << ". Enter again.\n";
    }
    // Return valid entered value
    return val;
}
int Reservation::getValidHour() {
    string prompt = "Please enter the hour of the pick up time.\n";
    return getIntInRange(0, 23, prompt);
}
int Reservation::getValidMinute() {
    string prompt = "Please enter the minute of the pick up time.\n";
    return getIntInRange(0, 59, prompt);
}
string Reservation::getValidString(string prompt) {
    // s represents string to be returned
    string s = "";
    // Display prompt
    cout << prompt;
    while (s.empty()) {
	// Get string from user
	getline(cin, s);
	// If string given is empty, tell user it cannot be
	if (s.empty())
	    cout << "The string must NOT be an empty one. "
		 << "Enter again.\n";
    }
    // Return non empty string
    return s;
}
