/*
 * File: assignment1.cpp
 * Author: Joshua Tate
 * Date: January 18, 2018
 * Updated: January 22, 2018
 *
 * Purpose: Program to help the dispatcher in a taxi company to manage
 *          taxi reservations in one day.
 */
#include <iostream>
using namespace std;

/* DATA MODELS */
// Reservation
class Reservation {
public:
    void userSetValues() {
        hour = getValidHour();
        minute = getValidMinute();
        location = getValidString("Please enter the pick up location\n");
        contact = getValidString("Please enter the name of the contact\n");
    }
    void printPickUpTime() {
	cout << "    pick up time: "
	     << hour << ":" << minute << endl
	     << "pick up location: " << location << endl
	     << "    contact name: " << contact << endl
	     << "------------\n";
    }
    int getTime() {
	return (hour * 60) + minute;
    }
    bool timeIsLessThan(Reservation* other) {
	return this->getTime() < other->getTime();
    }
private:
    int hour, minute;
    string location, contact;

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
};
typedef Reservation* ReservationPtr;

// Linked list
class LinkedList {
private:
    // Node
    struct Node {
	ReservationPtr data;
	Node *prev;
	Node *next;
    };
    typedef Node* NodePtr;

    // instance variables
    NodePtr head, earliest;
    int processed;
    void printNoReservationsMessage() {
	// Tell user there are reservations in the list
	cout << "\nThere is currently no reservation in the "
	     << "reservation list.\n\n";
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
        } else if (data->timeIsLessThan(earliest->data)) {
	    // Set new earliest pick up time
	    earliest = node;
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
	        tmp->data->printPickUpTime();
                tmp = tmp->next;
            }
        }
    }
    void removeEarliest() {
        if (this->isEmpty()) {
	    printNoReservationsMessage();
        } else {
	    earliest->data->printPickUpTime();
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
		// Check if current iteration is less than earliest
                if (tmp->data->timeIsLessThan(earliest->data)) {
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
void printMenu();
// Get user's command character
char getCommand();
// Submit new taxi reservation
void submitNewReservation(LinkedList &list);
// Tell user that reservations exist
void printReservationsExistMessage();
// Display's processed reservations
void printProcessedReservationCount(LinkedList list);

/* MAIN */
int main() {
    bool running = true;
    LinkedList list = LinkedList();
    welcome();
    printMenu();
    while (running) {
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
    cout << "-----------------------------------\n";
    cout << "Please enter your command: ";
    char cmd;
    cin >> cmd;
    string garbage;
    getline(cin, garbage);
    return cmd;
}

void printMenu() {
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
    data->userSetValues();
    list.insert(data);
    cout << "Reservation successfully added into the list.\n";
}

void printProcessedReservationCount(LinkedList list) {
    cout << "The total number of reservations processed is "
	 << list.getProcessed() << ".\n";
}

void printReservationsExistMessage() {
    cout << "\nProgram can not terminate.\n"
	 << "There are still reservations in the reservations list.\n";
}
