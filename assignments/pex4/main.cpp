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
#include <algorithm> // for transform
using namespace std;

const string BACK = "back";
const string FWD = "forward";
const string CLICK = "click";
const string EXIT = "exit";
const string PROMPT = "command$ ";

// Converts string to lower case
void convertToLowercase(string& s);
// Displays top URL of stack
void displayCurrentURL(const URLStack& stack);
// Pop's url from s1 and pushes it onto s2, then displays top of s1 if n == 1,
//  or top of s2 if n == 2, otherwise displays nothing
void popPushDisplay(URLStack& s1, URLStack & s2, int n) throw (EmptyStack);
// Removes trailing input from cin
void removeTrailingInput();

int main(int argc, char** argv) {
    if (argc != 2) {
	cout << "usage: " << argv[0] << " starting_url\n";
	exit(1);
    }
    URLRef firstURL = *(new URL(argv[1]));
    URLStack backStack(firstURL), forwardStack;
    displayCurrentURL(backStack);
    string userInput;
    do {
	cout << PROMPT;
	cin >> userInput;
	convertToLowercase(userInput);
	if (userInput == BACK)
	    if (backStack.getCount() == 1)
		cout << "Can't move back any more.\n";
	    else
		popPushDisplay(backStack, forwardStack, 1);
	else if (userInput == FWD)
	    try {
		popPushDisplay(forwardStack, backStack, 2);
	    } catch (EmptyStack& e) {
		cout << "Can't move forward any more.\n";
	    }
	else if (userInput == CLICK) {
	    URLRef url = *(new URL);
	    cin >> url;
	    backStack.push(url);
	    forwardStack.deleteAll();
	    displayCurrentURL(backStack);
	} else if (userInput != EXIT)
	    cout << "Uknown command, try again.\n";
	removeTrailingInput();
    } while (userInput != EXIT);
    return 0;
}

void convertToLowercase(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}
void displayCurrentURL(const URLStack& stack) {
    cout << "You are viewing: " << stack.peek() << endl;
}
void popPushDisplay(URLStack& s1, URLStack& s2, int n) throw (EmptyStack) {
    URLRef url = s1.pop();
    s2.push(url);
    if (n == 1)
	displayCurrentURL(s1);
    else if (n == 2)
	displayCurrentURL(s2);
}
void removeTrailingInput() {
    string garbage;
    getline(cin, garbage);
}
