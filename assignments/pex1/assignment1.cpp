/*
 * File: assignment1.cpp
 * Author: Joshua Tate
 * Date: January 18, 2018
 * Updated: January 21, 2018
 *
 * Purpose: Program to help the dispatcher in a taxi company to manage
 *          taxi reservations in one day.
 */
#include <iostream>
#include <cctype> // for tolower()
using namespace std;

/* DATA MODELS */
// Reservation
struct Reservation {
    int hour, minute;
    string location, contact;
};
typedef Reservation* ReservationPtr;

// Node
struct Node {
    ReservationPtr data;
    Node *prev;
    Node *next;
};
typedef Node* NodePtr;

// Linked list
class LinkedList {
private:
    NodePtr head, earliest;
    int processed;
    void printNoReservationsMessage() {
	// Tell user there are reservations in the list
	cout << "\nThere is currently no reservation in the "
	     << "reservation list.\n\n";
    }
    void printPickUpTime(ReservationPtr data) {
	int hour = data->hour;
	int minute = data->minute;
	string location = data->location;
	string contact = data->contact;
	cout << "    pick up time: "
	     << hour << ":" << minute << endl
	     << "pick up location: " << location << endl
	     << "    contact name: " << contact << endl
	     << "------------\n";
    }
public:
    LinkedList() {
        head = NULL;
        earliest = NULL;
        processed = 0;
    }
    bool isEmpty() {
        return (head == NULL);
    }
    int getProcessed() {
        return processed;
    }
    void insert(ReservationPtr data) {
        // Create new node
        NodePtr node = new Node;
        // Add node data
        node->data = data;
        // Point next to current head, and prev to NULL
        node->next = head;
        node->prev = NULL;
        // If head is not NULL, point current head prev to new node
        if (head) {
            head->prev = node;
        }
        // Point head to new node
        head = node;
        // Check if earliest is NULL
        if (!earliest) {
            // Set new record to earliest
            earliest = node;
        } else {
            // Check if new reservations time is earlier than earliest
            int earliestHour = earliest->data->hour * 60;
            int earliestMin = earliest->data->minute;
            int earliestTime = earliestHour + earliestMin;
            int newTime = (data->hour * 60) + data->minute;
            if (newTime < earliestTime) {
                // Set new earliest pick up time
                earliest = node;
            }
        }
    }
    void display() {
        // Check if list is empty
        if (this->isEmpty()) {
            printNoReservationsMessage();
        } else {
            // Head is not NULL, display list
            NodePtr tmp = head;
            while (tmp) {
		printPickUpTime(tmp->data);
                tmp = tmp->next;
            }
        }
    }
    void removeEarliest() {
        if (this->isEmpty()) {
	    printNoReservationsMessage();
        } else {
	    printPickUpTime(earliest->data);
	    cout << "The information of this reservation has passed to "
		 << "a taxi driver.\n";
	    // Check if not the front of the list
            if (earliest->prev) {
		// Set previous node's next to current earliest's next
                earliest->prev->next = earliest->next;
		// Check if next is not NULL
                if (earliest->next) {
		    // Set next's prev node to current earliests prev node
                    earliest->next->prev = earliest->prev;
		}
            } else { // At the front of the list
		// Check if earliest is not the back of the list
                if (earliest->next) {
		    // Set earliest's next node's prev node to NULL
		    //  indicating head of the list
                    earliest->next->prev = NULL;
                }
		// Set head to earliest's next node
                head = earliest->next;
            }
	    // Delete allocated memory related to earliest node
            delete earliest->data;
	    earliest->prev = NULL;
	    earliest->next = NULL;
            delete earliest;
            // Find new earliest pick up time
            earliest = head;
            NodePtr tmp = head;
	    // Check if list is not empty
            if (earliest) {
		// Set tmp to head's next node to compare against
                tmp = earliest->next;
	    }
	    // Loop through list and set new earliest reservation
            while (tmp) {
		// currTime represents current iterations time
                int currHour = tmp->data->hour * 60;
                int currTime = currHour + tmp->data->minute;
		// earTime represents the current earliest's time
                int earHour = earliest->data->hour * 60;
                int earTime = earHour + earliest->data->minute;
		// Check if currTime is less than earTime
                if (currTime < earTime) {
		    // Set earliest to current iteration
                    earliest = tmp;
                }
                tmp = tmp->next;
            }
	    // Increment processed
            processed++;
        }
    }
};

/* GLOBAL FUNCTION HEADERS */
// Display's welcome message to user
void welcome();
// Display's list of acceptable commands to user
void displayMenu();
// Get user's command character
char getCommand();
// Get integer in range min..max inclusive
int getIntInRange(int min, int max, string prompt);
// Get hour between 0 and 23 from user
int getValidHour();
// Get minute between 0 and 59 from user
int getValidMinute();
// Get non-empty string 
string getValidString(string prompt);
// Submit new taxi reservation
void submitNewReservation(LinkedList &list);
// Check if reservations are still on the list
void reservationsExist();
// Display's processed reservations
void displayProcessedReservations(LinkedList list);

/* MAIN */
int main() {
    bool running = true;
    LinkedList list = LinkedList();
    welcome();
    displayMenu();
    while (running) {
        char cmd = getCommand();
        switch (cmd) {
	case 's':
	    submitNewReservation(list);
	    break;
	case 'p':
	    list.removeEarliest();
	    break;
	case 'l':
	    list.display();
	    break;
	case 'h':
	    displayMenu();
	    break;
	case 't':
	    running = !list.isEmpty();
	    if (running) {
		reservationsExist();
	    } else {
		displayProcessedReservations(list);
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
    cout << "-----------------------------------\n";
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
	 << "   or T to terminate this program\n\n";
}

void submitNewReservation(LinkedList &list) {
    // Create reservation
    ReservationPtr data = new Reservation;
    data->hour = getValidHour();
    data->minute = getValidMinute();
    data->location = getValidString("Please enter the pick up location\n");
    data->contact = getValidString("Please enter the name of the contact\n");
    list.insert(data);
    cout << "Reservation successfully added into the list.\n";
}

void displayProcessedReservations(LinkedList list) {
    cout << "The total number of reservations processed is "
	 << list.getProcessed() << ".\n";
}

void reservationsExist() {
    cout << "\nProgram can not terminate.\n"
	 << "There are still reservations in the reservations list.\n";
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

int getValidHour() {
    string prompt = "Please enter the hour of the pick up time.\n";
    return getIntInRange(0, 23, prompt);
}

int getValidMinute() {
    string prompt = "Please enter the minute of the pick up time.\n";
    return getIntInRange(0, 59, prompt);
}

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
