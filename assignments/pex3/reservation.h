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
    // Sets member variable's value to user provided input
    void userSetValues();
    // Displays reservation's pick up time
    void printPickUpTime();
    // Returns pick up time
    int getTime();
    // Returns true if time is less than other reservations pick up time
    bool timeIsLessThan(Reservation* other);
private:
    // Reservation member variables
    int hour, minute;
    string location, contact;
    // Get's and returns integer between min and max,
    //  inclusive, from user with prompt
    int getIntInRange(int min, int max, string prompt);
    // Gets and returns an integer between 0 and 23, inclusive, from user
    int getValidHour();
    // Gets and returns an integer between 0 and 59, inclusive, from user
    int getValidMinute();
    // Gets and returns a non empty string from user with prompt
    string getValidString(string prompt);
};
// Convenience type defintion for Reservation*
typedef Reservation* ReservationPtr;
#endif
