/*
 * File: main.cpp
 * Author: Joshua Tate
 * Date: January 18, 2018
 * Updated: January 21, 2018
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
    void insert(int hour, int minute, string location, string contact) {
        // Create reservation data
        ReservationPtr data = new Reservation;
        data->hour = hour;
        data->minute = minute;
        data->location = location;
        data->contact = contact;
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
        if (earliest == NULL) {
            // Set new record to earliest
            earliest = node;
        } else {
            // Check if new reservations time is earlier than earliest
            int earliestHour = earliest->data->hour;
            earliestHour *= 60;
            int earliestMin = earliest->data->minute;
            int earliestTime = earliestHour + earliestMin;
            int newTime = (hour*60) + minute;
            if (newTime < earliestTime) {
                // New earliest pick up time
                earliest = node;
            }
        }
    }
    void display() {
        // Check if list is empty
        if (this->isEmpty()) {
            // Tell user there are reservations in the list
            cout << "\nThere is currently no reservation in the "
            << "reservation list.\n\n";
        } else {
            // Head is not NULL, display list
            NodePtr tmp = head;
            while (tmp != NULL) {
                int hour = tmp->data->hour;
                int minute = tmp->data->minute;
                string location = tmp->data->location;
                string contact = tmp->data->contact;
                cout << "    pick up time: "
                << hour << ":" << minute << endl
                << "pick up location: " << location << endl
                << "    contact name: " << contact << endl
                << "------------\n";
                tmp = tmp->next;
            }
        }
    }
    void removeEarliest() {
        if (this->isEmpty()) {
            // Tell user there are reservations in the list
            cout << "\nThere is currently no reservation in the "
            << "reservation list.\n\n";
        } else {
            int hour = earliest->data->hour;
            int minute = earliest->data->minute;
            string location = earliest->data->location;
            string contact = earliest->data->contact;
            cout << "    pick up time: "
            << hour << ":" << minute << endl
            << "pick up location: " << location << endl
            << "    contact name: " << contact << endl
            << "The information of this reservation has passed to "
            << "a taxi driver.\n";
            if (earliest->prev != NULL) { // Not at front of list
                earliest->prev->next = earliest->next;
                if (earliest->next)
                    earliest->next->prev = earliest->prev;
            } else { // At the front of the list
                if (earliest->next) {
                    earliest->next->prev = NULL;
                }
                head = earliest->next;
            }
            delete earliest->data;
            delete earliest;
            // Find new earliest
            earliest = head;
            NodePtr tmp = head;
            if (earliest)
                tmp = earliest->next;
            while (tmp != NULL) {
                int currHour = tmp->data->hour * 60;
                int currTime = currHour + tmp->data->minute;
                int earHour = earliest->data->hour * 60;
                int earTime = earHour + earliest->data->minute;
                if (currTime < earTime) {
                    earliest = tmp;
                }
                tmp = tmp->next;
            }
            processed++;
        }
    }
};

// Display's welcome message to user
void welcome();

// Display's list of acceptable commands to user
void displayMenu();

// Return's given user command
char getCommand();

// Submit new taxi reservation
void submitNewReservation(LinkedList &list);

// Get integer in range min..max inclusive
int getIntInRange(int min, int max, string prompt);

// Get hour between 0 and 23
int getValidHour();

// Get minute between 0 and 59
int getValidMinute();

// Get non-empty string
string getValidString(string prompt);

// Pick up passenger and remove from list
void pickUpPassenger(LinkedList &list);

// List all reservations in list
void listAllReservations(LinkedList list);

// Display's processed reservations
void displayProcessedReservations(LinkedList list);

// Check if reservations are still on the list
void reservationsExist();

/* MAIN */
int main() {
    welcome();
    displayMenu();
    bool running = true;
    LinkedList list = LinkedList();
    while (running) {
        char cmd = getCommand();
        switch (cmd) {
            case 's':
                submitNewReservation(list);
                break;
            case 'p':
                pickUpPassenger(list);
                break;
            case 'l':
                listAllReservations(list);
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
/* END MAIN */

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

// Submit new taxi reservation
void submitNewReservation(LinkedList &list) {
    // Get hour of pick up time
    int hour = getValidHour();
    int minute = getValidMinute();
    string location, contact;
    location = getValidString("Please enter the pick up location\n");
    contact = getValidString("Please enter the name of the contact\n");
    list.insert(hour, minute, location, contact);
    cout << "Reservation successfully added into the list.\n";
}

// Pick up passenger and remove from list
void pickUpPassenger(LinkedList &list) {
    list.removeEarliest();
}

// List all reservations in list
void listAllReservations(LinkedList list) {
    list.display();
}

// Display's processed reservations
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
