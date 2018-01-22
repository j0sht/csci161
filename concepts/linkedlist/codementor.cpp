// Tutorial from: https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

struct Node {
    int data;
    Node *next;
};

class List {
private:
    Node *head, *tail;
public:
    List() {
	head = NULL;
	tail = NULL;
    }
    // createNode adds a new node with value to the end of the list
    void createNode(int value) {
	Node *temp = new Node;
	temp->data = value;
	temp->next = NULL;
	// If head is NULL, the list is empty
	if (head == NULL) {
	    // head and tail should both point to the only
	    //  node in the list
	    head = temp;
	    tail = temp;
	    temp = NULL; // point temp to NULL to avoid dangling pointer?
	} else {
	    // Point current tail's next to new node
	    tail->next = temp;
	    // Point tail to new node
	    tail = temp;
	}
    }
    void display() {
	Node *temp = head;
	while (temp != NULL) {
	    cout << temp->data << "\t";
	    temp = temp->next;
	}
    }
    void insertStart(int value) {
	Node *temp = new Node;
	temp->data = value;
	temp->next = head;
	head = temp;
    }
};
