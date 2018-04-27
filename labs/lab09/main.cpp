#include "dictionary.h"
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

int main() {
    ifstream inputStream;
    inputStream.open("TechDictionary.txt");
    Dictionary<string, TechTerm>  dict;
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
	TechTerm& techTerm = *(new TechTerm(term, definition));
	dict.insert(techTerm.getTerm(), techTerm);
    }
    inputStream.close();
    string keyword;
    do {
	cout << "Enter keyword or 'shutdown' to quit: ";
	cin >> keyword;
	getline(cin, garbage);
	if (keyword == "shutdown")
	    continue;
	try {
	    TechTerm& term = dict.valueForKey(keyword);
	    term.printTechTerm();
	} catch (ValueNotFound& e) {
	    cout << "Could not find " << keyword
		 << ". Try another term.\n";
	}
    } while (keyword != "shutdown");
    return 0;
}
