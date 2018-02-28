/*
 * File: main.cpp
 * Author: Joshua Tate
 * Date: February 27, 2018
 * Updated: February 27, 2018
 *
 * Purpose: Program to help the dispatcher in a taxi company to manage
 *          taxi reservations in one day.
 */
#include <iostream>
#include "reservation.h"
#include "reservationlist.h"
using namespace std;

const string filename = "reservations.txt";

// Display's welcome message to user
void welcome();
// Display's list of acceptable commands to user
void displayMenu();
char getCommand();
// Submit newly allocated taxi reservation to today or tomorrow's list
void submitNewReservation(ReservationList& today,
			  ReservationList& tomorrow);
// Get's earliest reservation from list, displays it's reservations data
//  and deallocates it
void pickUpFrom(ReservationList& list);
void displayContentsOf(const ReservationList& list);
// Checks if list is empty, then explains to user that program cannot terminate
//  if it is not empty, else displays the proccessed count. Returns true
//  if the list is empty, otherwise false.
bool attemptToTerminateWith(const ReservationList& list);
void displayReservationsExistMessage();
void displayProcessedReservationCount(const ReservationList& list);
// Asks user if reservation is for today or tomorrow. Returns true
//  if reservation is for today.
bool reservationForToday();

/* MAIN */
int main() {
    bool running = true;
    ReservationList todaysList, tomorrowsList;
    welcome();
    if (!todaysList.readReservations(filename))
	cout << "Can't open " << filename << " to read data.\n"
	     << "Assuming that there is no reservation made yesterday.\n";
    displayMenu();
    while (running) {
        char cmd = getCommand();
        switch (cmd) {
	case 's': case 'S':
	    submitNewReservation(todaysList, tomorrowsList);
	    break;
	case 'p': case 'P':
	    pickUpFrom(todaysList);
	    break;
	case 'l': case 'L':
	    displayContentsOf(todaysList);
	    break;
	case 'h': case 'H':
	    displayMenu();
	    break;
	case 't': case 'T':
	    running = attemptToTerminateWith(todaysList);
	    break;
	default:
	    cout << "Unknown command. Try again.\n";
        }
    }
    tomorrowsList.writeReservations(filename);
    return 0;
}

/* GLOBAL FUNCTION DEFINITIONS */
void welcome() {
    cout << "\n*** Welcome to Taxi Reservation Management System ***\n\n";
}
char getCommand() {
    cout << "-----------------------------------\n";
    cout << "Please enter your command: ";
    char cmd;
    cin >> cmd;
    string garbage;
    getline(cin, garbage);
    return cmd;
}
void displayMenu() {
    cout << endl
	 << "Enter S to submit a new reservation\n"
	 << "   or P to pick up the passenger(s)\n"
	 << "   or L to list all reservations\n"
	 << "   or H for help (displays this menu)\n"
	 << "   or T to terminate this program\n\n";
}
void submitNewReservation(ReservationList& todaysList,
			  ReservationList& tomorrowsList) {
    ReservationPtr data = new Reservation;
    data->userSetValues();
    if (reservationForToday()) {
	todaysList.insert(data);
	cout << "Reservation successfully added today's list.\n";
    } else {
	tomorrowsList.insert(data);
	cout << "Reservation successfully added to tomorrow's list.\n";
    }
}
void pickUpFrom(ReservationList& list) {
    try {
        ReservationPtr data = list.removeEarliest();
	data->displayPickUpTime();
	cout << "The information of this reservation has passed to "
	     << "a taxi driver.\n";
	delete data;
    } catch (const ReservationListEmpty& e){
	cout << e << endl;
    }
}
void displayContentsOf(const ReservationList& list) {
    try {
        list.display();
    } catch (const ReservationListEmpty& e) {
	cout << e << endl;
    }
}
bool attemptToTerminateWith(const ReservationList& list) {
    bool notEmpty = !list.empty();
    if (notEmpty) {
	displayReservationsExistMessage();
    } else {
	displayProcessedReservationCount(list);
    }
    return notEmpty;
}
void displayProcessedReservationCount(const ReservationList& list) {
    cout << "The total number of reservations processed is "
	 << list.getProcessed() << ".\n";
}
void displayReservationsExistMessage() {
    cout << "\nProgram can not terminate.\n"
	 << "There are still reservations in the reservations list.\n";
}
bool reservationForToday() {
    string prompt = "Is the reservation for today (Y) or tomorrow (N)?\n";
    bool valid = false;
    string s;
    do {
	cout << prompt;
	getline(cin, s);
	valid = (!s.empty() && (s == "N" || s == "n" ||
				s == "Y" || s == "y"));
    } while (!valid);
    return (s == "Y" || s == "y");
}
