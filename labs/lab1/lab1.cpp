#include <iostream>
using namespace std;

// Data
struct Record {
    int id;
    string name;
};

struct Node {
    Record *data;
    Node *next;
};

// Read user input and create a new data record
Record *readData() {
    string restOfLine;
    Record *data = new Record;
    cout << "Please enter the id: ";
    cin >> data->id;
    getline(cin, restOfLine);
    cout << "Please enter the name: ";
    getline(cin, data->name);
    return data;
}

Node *createEmptyList() {
    Node *ptr = new Node;
    ptr->next = NULL;
    ptr->data = NULL;
    return ptr;
}

char userCmdInput() {
    string garbage;
    char cmd;
    cout << "Enter 'E' to enter data record\n"
	 << "   or 'D' to display records\n"
	 << "   or 'T' to terminate program\n\n"
	 << "------------------------------\n"
	 << "Please enter your command: ";
    cin >> cmd;
    getline(cin, garbage);
    return cmd;
}

void insert(Node* &head, Record *data) {
    Node *newNode = new Node;
    newNode->next = head;
    newNode->data = data;
    head = newNode;
}

void display(Node *head) {
    if (head) {
	Node *ptr = head;
	while (ptr->next != NULL) {
	    cout << "-------------------\n"
		 << "  ID: " << ptr->data->id << endl
		 << "  Name: " << ptr->data->name << endl;
	    ptr = ptr->next;
	}
    }
}

void destroy(Node* &head) {
    Node *ptr = head;
    while (ptr->next != NULL) {
	Node *victim = ptr;
	ptr = ptr->next;
	delete victim->data;
	delete victim;
    }
    delete ptr->data;
    delete ptr;
    head = NULL;
}

/* MAIN */
int main() {
    Record *data;
    Node *list = createEmptyList();
    char cmd;
    cmd = userCmdInput();
    while (cmd != 'T') {
	if (cmd == 'E') {
	    data = readData();
	    insert(list, data);
	} else if (cmd == 'D') {
	    display(list);
	}
	cmd = userCmdInput();
    }
    destroy(list);
    cout << "Contents of list after destroy:\n";
    display(list);
    cout << "Done.\n";
    return 0;
}
/* END MAIN */
