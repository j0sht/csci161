/*
 * File: reservation.cpp
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the implementation of a Reservation
 */
#include <iostream>
#include <iomanip>
#include "reservation.h"
using namespace std;

// Constructors
Reservation::Reservation() {
    hour = minute = 0;
    location = contact = "";
}
Reservation::Reservation(int hour, int minute, string location, string contact) {
    this->hour = hour;
    this->minute = minute;
    this->location = location;
    this->contact = contact;
}
// Public methods
void Reservation::userSetValues() {
    hour = userValidHour();
    minute = userValidMinute();
    location = userValidString("Please enter the pick up location\n");
    contact = userValidString("Please enter the name of the contact\n");
}
void Reservation::displayPickUpTime() {
    cout << "    pick up time: "
	 << hour << ":" << setfill('0') << setw(2) << minute << endl
	 << "pick up location: " << location << endl
	 << "    contact name: " << contact << endl;
}
int Reservation::getTime() {
    return (hour * 60) + minute;
}
int Reservation::getHour() {
    return hour;
}
int Reservation::getMinute() {
    return minute;
}
string Reservation::getLocation() {
    return location;
}
string Reservation::getContact() {
    return contact;
}
bool Reservation::timeIsLessThan(ReservationPtr other) {
    return this->getTime() < other->getTime();
}
// Private methods
int Reservation::userIntInRange(int min, int max, string prompt) {
    int val;
    // valid is set to true when user enters a value in range min..max
    bool valid = false;
    string garbage;
    cout << prompt;
    while (!valid) {
	cin >> val;
	getline(cin, garbage);
	valid = ((val >= min) && (val <= max));
	if (!valid)
	    cout << "The number must be in the range of "
		 << min << " and " << max << ". Enter again.\n";
    }
    return val;
}
int Reservation::userValidHour() {
    string prompt = "Please enter the hour of the pick up time.\n";
    return userIntInRange(0, 23, prompt);
}
int Reservation::userValidMinute() {
    string prompt = "Please enter the minute of the pick up time.\n";
    return userIntInRange(0, 59, prompt);
}
string Reservation::userValidString(string prompt) {
    string s = "";
    cout << prompt;
    while (s.empty()) {
	getline(cin, s);
	if (s.empty())
	    cout << "The string must NOT be an empty one. "
		 << "Enter again.\n";
    }
    return s;
}
