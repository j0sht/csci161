/*
 * File: main.cpp
 * Author: Joshua Tate
 * Date: January 18, 2018
 * Updated: n/a
 *
 * Purpose: Program to help the dispatcher in a taxi company to manage
 *          taxi reservations in one day.
 *
 * Notes: n/a (any additional notes on the use of the file)
 *
 * References: n/a (optional - a list fo related reference materials)
 */
#include <iostream>
#include <cctype> // for tolower()
using namespace std;

// Display's welcome message to user
void welcome();

// Display's list of acceptable commands to user
void displayMenu();

// Return's given user command
char getCommand();

// Submit new taxi reservation
void submitNewReservation();

// Get integer in range min..max inclusive
int getIntInRange(int min, int max, string prompt);

// Get hour between 0 and 23
int getValidHour();

// Get minute between 0 and 59
int getValidMinute();

// Get non-empty string
string getValidString(string prompt);

// Pick up passenger and remove from list
void pickUpPassenger();

// List all reservations in list
void listAllReservations();

// Display's processed reservations
void displayProcessedReservations();

// Check if reservations are still on the list
bool reservationsExist();

int main() {
    welcome();
    bool running = true;
    while (running) {
	char cmd = getCommand();
	switch (cmd) {
	case 's':
	    submitNewReservation();
	    break;
	case 'p':
	    pickUpPassenger();
	    break;
	case 'l':
	    listAllReservations();
	    break;
	case 'h':
	    break;
	case 't':
	    running = reservationsExist();
	    displayProcessedReservations();
	    break;
	default:
	    cout << "Unknown command. Try again.\n";
	}
    }
    return 0;
}

void welcome() {
    cout << "\n*** Welcome to Taxi Reservation Management System ***\n";
}

char getCommand() {
    displayMenu();
    cout << "Please enter your command: ";
    char cmd;
    cin >> cmd;
    string garbage;
    getline(cin, garbage);
    return tolower(cmd);
}

void displayMenu() {
    cout << endl
	 << "Enter S to submit a new reservation\n"
	 << "   or P to pick up the passenger(s)\n"
	 << "   or L to list all reservations\n"
	 << "   or H for help (displays this menu)\n"
	 << "   or T to terminate this program\n\n"
	 << "-----------------------------------\n";
}

// Submit new taxi reservation
void submitNewReservation() {
    cout << "Submitting reservation...\n\n";
    // Get hour of pick up time
    int hour = getValidHour();
    int minute = getValidMinute();
    string location, contact;
    location = getValidString("Please enter the pick up location\n");
    contact = getValidString("Please enter the name of the contact\n");
    cout << "Will pick up " << contact << " from " << location
	 << " at " << hour << ":" << minute << endl;
    cout << "Reservation successfully added into the list.\n";
}

// Pick up passenger and remove from list
void pickUpPassenger() {
    cout << "Picking up passenger...\n\n";
}

// List all reservations in list
void listAllReservations() {
    cout << "Listing all reservations...\n\n";
}

// Display's processed reservations
void displayProcessedReservations() {
    cout << "Displaying processed reservations...\n\n";
}

// Check if reservations are still on the list
bool reservationsExist() {
    return false;
}

int getIntInRange(int min, int max, string prompt) {
    int val;
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

// Get hour between 0 and 23
int getValidHour() {
    string prompt = "Please enter the hour of the pick up time.\n";
    return getIntInRange(0, 23, prompt);
}

// Get minute between 0 and 59
int getValidMinute() {
    string prompt = "Please enter the minute of the pick up time.\n";
    return getIntInRange(0, 59, prompt);
}

// Get non-empty string
string getValidString(string prompt) {
    string s = "";
    cout << prompt;
    while (s.empty()) {
	getline(cin, s);
	if (s.empty())
	    cout << "The string must NOT be an empty one. Enter again.\n";
    }
    return s;
}
