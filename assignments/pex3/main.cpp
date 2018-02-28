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
void printMenu();
// Get user's command character
char getCommand();
// Submit new taxi reservation based on user's input
void submitNewReservation(ReservationList &today,
			  ReservationList &tomorrow);
// Displays contents of list
void displayListContents(const ReservationList &list);
// Pick's up earliest passenger from list
void pickUpFrom(ReservationList &list);
// Checks if list is empty, then explains to user that program cannot terminate
//  if it is not empty, else displays the proccessed count. Returns true
//  if the list is empty, otherwise false.
bool attemptToTerminateWith(const ReservationList &list);
// Tell user that reservations exist
void printReservationsExistMessage();
// Display's processed reservations
void printProcessedReservationCount(const ReservationList& list);
// Check if reservation is for today or tomorrow
bool reservationForToday();

/* MAIN */
int main() {
    // running is set to false when user attempts to terminate program
    //  and the list is empty
    bool running = true;
    ReservationList todaysList, tomorrowsList;
    welcome();
    if (!todaysList.readReservations(filename))
	cout << "Can't open " << filename << " to read data.\n"
	     << "Assuming that there is no reservation made yesterday.\n";
    printMenu();
    while (running) {
	// Get user command and perform appropriate action
        char cmd = getCommand();
        switch (cmd) {
	case 's': case 'S':
	    submitNewReservation(todaysList, tomorrowsList);
	    break;
	case 'p': case 'P':
	    pickUpFrom(todaysList);
	    break;
	case 'l': case 'L':
	    displayListContents(todaysList);
	    break;
	case 'h': case 'H':
	    printMenu();
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
    // Prompt user to enter command
    cout << "-----------------------------------\n";
    cout << "Please enter your command: ";
    // Get command from stdin
    char cmd;
    cin >> cmd;
    // Remove extraneous info in stdin buffer
    string garbage;
    getline(cin, garbage);
    // Return entered command
    return cmd;
}
void printMenu() {
    // Display available options to user
    cout << endl
	 << "Enter S to submit a new reservation\n"
	 << "   or P to pick up the passenger(s)\n"
	 << "   or L to list all reservations\n"
	 << "   or H for help (displays this menu)\n"
	 << "   or T to terminate this program\n\n";
}
void submitNewReservation(ReservationList &todaysList,
			  ReservationList &tomorrowsList) {
    // Create reservation
    ReservationPtr data = new Reservation;
    // Get user to set values for reservation
    data->userSetValues();
    if (reservationForToday()) {
	todaysList.insert(data);
	cout << "Reservation successfully added today's list.\n";
    } else {
	tomorrowsList.insert(data);
	cout << "Reservation successfully added to tomorrow's list.\n";
    }
}
void displayListContents(const ReservationList& list) {
    try {
        list.display();
    } catch (const ReservationListEmpty& e) {
	cout << e.description() << endl;
    }
}
void pickUpFrom(ReservationList& list) {
    try {
        list.removeEarliest();
    } catch (const ReservationListEmpty& e){
	cout << e.description() << endl;
    }
}
bool attemptToTerminateWith(const ReservationList& list) {
    bool notEmpty = !list.isEmpty();
    if (notEmpty) {
	printReservationsExistMessage();
    } else {
	printProcessedReservationCount(list);
    }
    return notEmpty;
}
void printProcessedReservationCount(const ReservationList& list) {
    // Show user processed reservation count
    cout << "The total number of reservations processed is "
	 << list.getProcessed() << ".\n";
}
void printReservationsExistMessage() {
    // Inform user that the program cannot terminate until
    //  there are no more reservations
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
