/*
 * File: main.cpp
 * Author: Joshua Tate
 * Date: March 15, 2018
 * Updated: March 20, 2018
 *
 * Purpose:
 *    - This file contains the main program
 */
#include "url.h"
#include "urlstack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const string BACK = "back";
const string FWD = "forward";
const string CLICK = "click";
const string EXIT = "exit";
const string PROMPT = "command$ ";

void displayCurrentURL(const URLStack& stack);

int main(int argc, char** argv) {
    if (argc != 2) {
	cout << "usage: " << argv[0] << " starting_url\n";
	exit(1);
    }
    URLStack backStack(new URL(argv[1])), forwardStack;
    displayCurrentURL(backStack);
    string userInput;
    do {
	cout << PROMPT;
	cin >> userInput;
	if (userInput == BACK) {
	    if (backStack.getCount() == 1)
		cout << "Can't move back any more.\n";
	    else {
		URLPtr url = backStack.pop();
		forwardStack.push(url);
		displayCurrentURL(backStack);
	    }
	} else if (userInput == FWD) {
	    try {
		URLPtr url = forwardStack.pop();
		backStack.push(url);
		displayCurrentURL(backStack);
	    } catch (EmptyStack& e) {
		cout << "Can't move forward any more.\n";
	    }
	} else if (userInput == CLICK) {
	    URLPtr url = new URL;
	    cin >> *url;
	    string garbage;
	    getline(cin, garbage);
	    backStack.push(url);
	    forwardStack.dump();
	    displayCurrentURL(backStack);
	} else if (userInput != EXIT) {
	    cout << "Uknown command, try again.\n";
	    string garbage;
	    getline(cin, garbage);
	}
    } while (userInput != EXIT);
    return 0;
}

void displayCurrentURL(const URLStack& stack) {
    cout << "You are viewing: " << stack.peek() << endl;
}
