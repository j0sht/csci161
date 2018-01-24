/*
 * File: assignment1.cpp
 * Author: Joshua Tate
 * Date: January 18, 2018
 * Updated: January 23, 2018
 *
 * Purpose: Program to help the dispatcher in a taxi company to manage
 *          taxi reservations in one day.
 */
#include <iostream>
#include <iomanip> // for setfill and setw
using namespace std;

/* CLASS DEFINTIONS */
// Reservation class definition
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

// Linked list class definition
class LinkedList {
public:
    /* Constructor */
    LinkedList() {
        head = NULL;
	tail = NULL;
        processed = 0;
    }

    /* Public Methods */
    // Returns true if list is empty, otherwise false
    bool isEmpty();
    // Returns processed count
    int getProcessed();
    // Insert's data into list based on data's pick up time
    //  sorted from earliest to latest pick up time
    void insert(ReservationPtr data);
    // Display's list contents
    void display();
    // Remove's the earliest pick up time from the list
    void removeEarliest();
private:
    // Node definition and convenience typedef for Node*
    struct Node {
	ReservationPtr data;
	Node *prev;
	Node *next;
    };
    typedef Node* NodePtr;

    /* LinkedList member variables */
    // Pointers to head and tail of list
    NodePtr head, tail;
    // Integer to keep track of processed reservations
    int processed;

    /* Private Methods */
    // Informs user there are no reservations in the list
    void printNoReservationsMessage();
    // Sets up node to be the first node in an empty list
    /* Assumes that node is not NULL */
    void setUpFirstNodeWith(Node* node);
    // Sets tail of the list to given node
    /* Assumes that tail and node are not NULL */
    void setTailTo(NodePtr node);
    // Sets head of the list to given node
    /* Assumes that head and node are not NULL */
    void setHeadTo(NodePtr node);
    // Inserts given node before given after node
    /* Assumes that node and after are not NULL */
    void insertBefore(NodePtr node, NodePtr after);
    // Removes and deallocates head and its data
    /* Assumes that head is not NULL when called */
    void removeHead();
};

/* CLASS METHOD IMPLEMENTATIONS */
/* Reservation Method Implementations */
// Public reservation methods
void Reservation :: userSetValues() {
    hour = getValidHour();
    minute = getValidMinute();
    location = getValidString("Please enter the pick up location\n");
    contact = getValidString("Please enter the name of the contact\n");
}
void Reservation :: printPickUpTime() {
    // Display reservation data
    cout << "    pick up time: "
	 << hour << ":" << setfill('0') << setw(2) << minute << endl
	 << "pick up location: " << location << endl
	 << "    contact name: " << contact << endl;
}
int Reservation :: getTime() {
    // Return total minutes
    return (hour * 60) + minute;
}
bool Reservation :: timeIsLessThan(Reservation* other) {
    return this->getTime() < other->getTime();
}
// Private reservation methods
int Reservation :: getIntInRange(int min, int max, string prompt) {
    // val represents value to be returned
    int val;
    // valid is set to true when user enters a value in range min..max
    bool valid = false;
    // garbage will hold extraneous data in cin
    string garbage;
    // Display prompt
    cout << prompt;
    while (!valid) {
	// Get value
	cin >> val;
	// Collect garbage
	getline(cin, garbage);
	// Set valid to true if val in range min..max
	valid = ((val >= min) && (val <= max));
	// If not valid, explain to user value must be in range min..max
	if (!valid)
	    cout << "The number must be in the range of "
		 << min << " and " << max << ". Enter again.\n";
    }
    // Return valid entered value
    return val;
}
int Reservation :: getValidHour() {
    string prompt = "Please enter the hour of the pick up time.\n";
    return getIntInRange(0, 23, prompt);
}
int Reservation :: getValidMinute() {
    string prompt = "Please enter the minute of the pick up time.\n";
    return getIntInRange(0, 59, prompt);
}
string Reservation :: getValidString(string prompt) {
    // s represents string to be returned
    string s = "";
    // Display prompt
    cout << prompt;
    while (s.empty()) {
	// Get string from user
	getline(cin, s);
	// If string given is empty, tell user it cannot be
	if (s.empty())
	    cout << "The string must NOT be an empty one. "
		 << "Enter again.\n";
    }
    // Return non empty string
    return s;
}

/* LinkedList Method Implementations */
// Public linked list methods
bool LinkedList :: isEmpty() {
    return (head == NULL);
}
int LinkedList :: getProcessed() {
    return processed;
}
void LinkedList :: insert(ReservationPtr data) {
    // Create new node
    NodePtr node = new Node;
    // Add node data
    node->data = data;
    // Create tmp node to iterate through list,
    //  starting with current head
    NodePtr tmp = head;
    // Iterate through list while tmp is not NULL and
    //  tmp's time is less than the new data's time
    while (tmp && tmp->data->timeIsLessThan(data))
	tmp = tmp->next;
    // Check if it is the first element
    if (!head)
	setUpFirstNodeWith(node);
    // Not the first element
    else {
	// Check if it is the back of the list
	if (tmp == NULL) {
	    setTailTo(node);
	}
	// Check if it is the front of the list
	else if (tmp == head) {
	    setHeadTo(node);
	}
	// It is between two nodes
	else {
	    insertBefore(node, tmp);
	}
    }
}
void LinkedList :: display() {
    if (this->isEmpty()) {
	printNoReservationsMessage();
    } else {
	// Print pick up time for each node in the list
	NodePtr tmp = head;
	while (tmp) {
	    tmp->data->printPickUpTime();
	    cout << "------------\n";
	    tmp = tmp->next;
	}
    }
}
void LinkedList :: removeEarliest() {
    if (this->isEmpty()) {
	printNoReservationsMessage();
    } else {
	// Display earliest pick up time
	head->data->printPickUpTime();
	cout << "The information of this reservation has passed to "
	     << "a taxi driver.\n";
	// Delete head - the node with the earliest pick up time
	removeHead();
    }
}
// Private linked list methods
void LinkedList :: printNoReservationsMessage() {
    // Tell user there are reservations in the list
    cout << "\nThere is currently no reservation in the "
	 << "reservation list.\n\n";
}
void LinkedList :: setUpFirstNodeWith(NodePtr node) {
    // Set node's next to head
    node->next = head;
    // Set node's prev to NULL indicating head
    node->prev = NULL;
    // Set head and tail to the first node
    head = node;
    tail = node;
}
void LinkedList :: setTailTo(NodePtr node) {
    // Point new node's next to NULL indicating tail
    node->next = NULL;
    // Point current tail's next to new node
    tail->next = node;
    // Point new node's prev to current tail
    node->prev = tail;
    // Set tail to new node
    tail = node;
}
void LinkedList :: setHeadTo(NodePtr node) {
    // Set node's next to current head
    node->next = head;
    // Set node's prev to NULL indicating head
    node->prev = NULL;
    // Set current head's prev to node
    head->prev = node;
    // Set head to new node
    head = node;
}
void LinkedList :: insertBefore(NodePtr node, NodePtr after) {
    // Point after node's prev node's next to new node
    after->prev->next = node;
    // Point new node's prev to after node's prev
    node->prev = after->prev;
    // Point new node's next to after
    node->next = after;
    // Point after's prev to new node
    after->prev = node;
}
void LinkedList :: removeHead() {
    // Create victim to remove
    NodePtr victim = head;
    // Set head to next node in the list
    head = head->next;
    // Check if list is not empty
    if (head)
	// Set new head prev to NULL indicating head of list
	head->prev = NULL;
    // Remove victim node
    delete victim->data;
    victim->data = NULL;
    victim->next = NULL;
    delete victim;
    victim = NULL;
    // Increment processed
    processed++;
}

/* GLOBAL FUNCTION HEADERS */
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
void printProcessedReservationCount(LinkedList list);

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
void printProcessedReservationCount(LinkedList list) {
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
