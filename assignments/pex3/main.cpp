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
#include "linkedlist.h"
using namespace std;

// Display's welcome message to user
void welcome();
// Display's list of acceptable commands to user
void printMenu();
// Get user's command character
char getCommand();
// Submit new taxi reservation based on user's input
void submitNewReservation(LinkedList &list);
// Tell user that reservations exist
void printReservationsExistMessage();
// Display's processed reservations
void printProcessedReservationCount(const LinkedList& list);

/* MAIN */
int main() {
    // running is set to false when user attempts to terminate program
    //  and the list is empty
    bool running = true;
    // list to manage reservations
    LinkedList list = LinkedList();
    // welcome user to program and display menu
    welcome();
    printMenu();
    while (running) {
	// Get user command and perform appropriate action
        char cmd = getCommand();
        switch (cmd) {
	case 's': case 'S':
	    submitNewReservation(list);
	    break;
	case 'p': case 'P':
	    list.removeEarliest();
	    break;
	case 'l': case 'L':
	    list.display();
	    break;
	case 'h': case 'H':
	    printMenu();
	    break;
	case 't': case 'T':
	    running = !list.isEmpty();
	    if (running) {
		printReservationsExistMessage();
	    } else {
		printProcessedReservationCount(list);
	    }
	    break;
	default:
	    cout << "Unknown command. Try again.\n";
        }
    }
    return 0;
}

/* GLOBAL FUNCTION DEFINITIONS */
void welcome() {
    cout << "\n*** Welcome to Taxi Reservation Management System ***\n";
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
void submitNewReservation(LinkedList &list) {
    // Create reservation
    ReservationPtr data = new Reservation;
    // Get user to set values for reservation
    data->userSetValues();
    // Insert reservation into list
    list.insert(data);
    // Inform user reservation was successfully added
    cout << "Reservation successfully added into the list.\n";
}
void printProcessedReservationCount(const LinkedList& list) {
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
