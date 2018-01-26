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
	count = 0;
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
    void setCount(int count) {
	this->count = count;
    }
    int getCount() {
	return count;
    }
    void display() {
	NodePtr tmp = head;
	cout << "List count: " << count << endl;
	while (tmp) {
	    string term, def;
	    term = tmp->data->getTerm();
	    def = tmp->data->getDefinition();
	    cout << term << ": " << def << endl;
	    tmp = tmp->next;
	}
    }
private:
    struct Node {
	TechTermPtr data;
	Node *next;
    };
    typedef Node* NodePtr;
    // Instance variables
    NodePtr head;
    int count;
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
    list.setCount(count);
    for (int i = 0; i < list.getCount(); i++) {
	string term, definition;
	inputStream >> term;
	inputStream >> garbage;
	getline(inputStream, definition);
	TechTermPtr techTerm = new TechTerm(term, definition);
	list.insert(techTerm);
    }
    string keyword;
    do {
	cout << "Enter keyword or 'exit' to quit: ";
	cin >> keyword;
	getline(cin, garbage);
	if (keyword == "exit")
	    continue;
	TechTermPtr term = list.search(keyword);
	if (term)
	    term->printTechTerm();
	else
	    cout << "Could not find " << keyword
		 << ". Try another term.\n";
    } while (keyword != "exit");
    return 0;
}
