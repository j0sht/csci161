/*
 * File: reservation.h
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose:
 *    - This file contains the definition of a Reservation
 */
#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
using namespace std;

class Reservation {
public:
    // Constructors
    Reservation();
    Reservation(int hour, int minute, string location, string contact);
    // Getters
    // Returns total time
    int getTime();
    int getHour();
    int getMinute();
    string getLocation();
    string getContact();
    // Methods
    // Sets member variable's value to user provided input
    void userSetValues();
    // Displays reservation's pick up time and associated data
    void displayPickUpTime();
    // Returns true if time is less than other reservations time
    bool timeIsLessThan(Reservation* other);
private:
    // Reservation member variables
    int hour, minute;
    string location, contact;
    // Gets and returns integer between min and max,
    //  inclusive, from user with prompt
    int userIntInRange(int min, int max, string prompt);
    // Gets and returns an integer between 0 and 23, inclusive, from user
    int userValidHour();
    // Gets and returns an integer between 0 and 59, inclusive, from user
    int userValidMinute();
    // Gets and returns a non empty string from user with prompt
    string userValidString(string prompt);
};
// Convenience type defintion for Reservation*
typedef Reservation* ReservationPtr;
#endif
