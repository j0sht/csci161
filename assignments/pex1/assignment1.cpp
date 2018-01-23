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
	     << "    contact name: " << contact << endl;
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
		cout << "The string must NOT be an empty one. "
		     << "Enter again.\n";
	}
	return s;
    }
};
typedef Reservation* ReservationPtr;

// Linked list
class LinkedList {
public:
    LinkedList() {
        head = NULL;
	tail = NULL;
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
	// Create tmp node to iterate through list,
	//  starting with current head
	NodePtr tmp = head;
	// Search for position to insert based on pick up time
	while (tmp && tmp->data->timeIsLessThan(data))
	    tmp = tmp->next;
	// Check if it is the first element
	if (!head) {
	    // Set node's next to head
	    node->next = head;
	    // Set node's prev to NULL indicating head
	    node->prev = NULL;
	    // Set node and tail to the first node
	    head = node;
	    tail = node;
	}
	// Not the first element
	else {
	    // Check if back of the list
	    if (tmp == NULL) {
		// Point new node's next to NULL
		node->next = NULL;
		// Point current tail's next to new node
		tail->next = node;
		// Point new node's prev to current tail
		node->prev = tail;
		// Set tail to new node
		tail = node;
	    }
	    // Check if front of the list
	    else if (tmp == head) {
		// Set node's next to current head
		node->next = head;
		// Set current head's prev to node
		head->prev = node;
		// Set head to new node
		head = node;
	    }
	    // Between two nodes
	    else {
		// Point tmp node's prev node's next to new node
		tmp->prev->next = node;
		// Point new node's prev to tmp node's prev
		node->prev = tmp->prev;
		// Point new node's next to tmp 
		node->next = tmp;
		// Point tmp's prev to new node
		tmp->prev = node;
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
	        tmp->data->printPickUpTime();
		cout << "------------\n";
                tmp = tmp->next;
            }
        }
    }
    void removeEarliest() {
        if (this->isEmpty()) {
	    printNoReservationsMessage();
        } else {
	    // Process head
	    head->data->printPickUpTime();
	    cout << "The information of this reservation has passed to "
		 << "a taxi driver.\n";
	    // Create victim to remove
	    NodePtr victim = head;
	    // Set head to next node in the list
	    head = head->next;
	    // Check if list is not empty
	    if (head) {
		head->prev = NULL;
	    }
	    // Remove victim node
	    delete victim->data;
	    victim->next = NULL;
	    delete victim;
	    // Increment processed
            processed++;
        }
    }
private:
    // Node
    struct Node {
	ReservationPtr data;
	Node *prev;
	Node *next;
    };
    typedef Node* NodePtr;

    // instance variables
    NodePtr head, tail;
    int processed;

    // private instance method
    void printNoReservationsMessage() {
	// Tell user there are reservations in the list
	cout << "\nThere is currently no reservation in the "
	     << "reservation list.\n\n";
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
