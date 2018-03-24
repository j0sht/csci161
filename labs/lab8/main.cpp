#include "person.h"
#include "student.h"
#include "queue.h"
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int size;
    cout << "Enter queue size: ";
    cin >> size;
    MyQueue<Student> queue(size);
    bool running = true;
    while (running) {
	cout << "Options:\n"
	     << "  (E)nqueue\n"
	     << "  (D)equeue\n"
	     << "  (V)iew next\n"
	     << "  (P)rint queue\n"
	     << "  (Q)uit\n\n"
	     << "command$ ";
	char cmd;
	cin >> cmd;
	switch(tolower(cmd)) {
	case 'e':
	    if (queue.isFull()) {
		cout << "======================================\n"
		     << "Queue is full. Cannot add new student.\n"
		     << "======================================\n";
	    } else {
		Student& newStudent = *(new Student);
		cin >> newStudent;
		queue.enqueue(newStudent);
	    }
	    break;
	case 'd':
	    if (queue.isEmpty()) {
		cout << "========================================\n"
		     << "Queue is empty. Cannot remove a student.\n"
		     << "========================================\n";
	    } else {
		Student& student = queue.dequeue();
		cout << "DEQUEUED:\n    " << student << endl;
		delete &student;
	    }
	    break;
	case 'v':
	    if (queue.isEmpty()) {
		cout << "=========================================\n"
		     << "Queue is empty. Cannot view next student.\n"
		     << "=========================================\n";
	    } else {
		cout << "NEXT IN QUEUE:\n    " << queue.peek() << endl;
	    }
	    break;
	case 'p':
	    if (queue.isEmpty()) {
		cout << "===================================\n"
		     << "Queue is empty. Nothing to display.\n"
		     << "===================================\n";
	    } else {
		cout << "QUEUE:\n";
		queue.display();
	    }
	    break;
	case 'q':
	    running = false;
	    break;
	default:
	    cout << "Unknown command. Try again.\n";
	}
    }
    cout << "Goodbye!\n";
    return 0;
}
