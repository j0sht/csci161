#include <iostream>
#include <fstream>
using namespace std;

class TechTerm {
public:
    TechTerm(string term, string definition) {
	this->term = term;
	this->definition = definition;
    }
    string getTerm() {
	return term;
    }
    string getDefinition() {
	return definition;
    }
    void printTechTerm() {
	cout << term << ":" << definition << endl;
    }
private:
    string term, definition;
};
typedef TechTerm* TechTermPtr;

class LinkedList {
public:
    LinkedList() {
	head = NULL;
    }
    ~LinkedList() {
	while (head) {
	    NodePtr victim = head;
	    head = head->next;
	    delete victim->data;
	    delete victim;
	}
    }
    void insert(TechTermPtr techTerm) {
	NodePtr node = new Node;
	node->data = techTerm;
	node->next = head;
	head = node;
    }
    TechTermPtr search(string keyword) {
	NodePtr tmp = head;
	while (tmp) {
	    if (tmp->data->getTerm() == keyword)
		return tmp->data;
	    tmp = tmp->next;
	}
	return NULL;
    }
private:
    struct Node {
	TechTermPtr data;
	Node *next;
    };
    typedef Node* NodePtr;
    // Instance variables
    NodePtr head;
};

int main() {
    ifstream inputStream;
    inputStream.open("TechDictionary.txt");
    LinkedList list = LinkedList();
    // Get number of terms
    int count;
    inputStream >> count;
    string garbage;
    getline(inputStream, garbage);
    for (int i = 0; i < count; i++) {
	string term, definition;
	inputStream >> term;
	inputStream >> garbage;
	getline(inputStream, definition);
	TechTermPtr techTerm = new TechTerm(term, definition);
	list.insert(techTerm);
    }
    string keyword;
    do {
	cout << "Enter keyword or 'shutdown' to quit: ";
	cin >> keyword;
	getline(cin, garbage);
	if (keyword == "shutdown")
	    continue;
	TechTermPtr term = list.search(keyword);
	if (term)
	    term->printTechTerm();
	else
	    cout << "Could not find " << keyword
		 << ". Try another term.\n";
    } while (keyword != "shutdown");
    return 0;
}
