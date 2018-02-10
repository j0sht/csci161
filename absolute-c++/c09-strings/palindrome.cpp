// Test for palindrome property
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Interchanges the values of v1 and v2
void swap(char &v1, char &v2);

// Returns a copy of s but with characters in reverse order
string reverse(const string &s);

// Returns a copy of s with any occurrences of characters
//  in the string punct removed
string removePunct(const string &s, const string &punct);

// Returns a copy of s that has all uppercase characters changed
//  to lowercase, with other characters unchanged
string makeLower(const string &s);

// Returns true if s is a palindrome; false otherwise.
bool isPal(const string &s);

int main() {
    string str;
    cout << "Enter a candidate for palindrome test\n"
	 << "followed by pressing Return.\n";
    getline(cin, str);

    if (isPal(str))
	cout << "\"" << str + "\" is a palindrome.";
    else
	cout << "\"" << str + "\" is not a palindrome.";
    cout << endl;

    return 0;
}

void swap(char &v1, char &v2) {
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string reverse(const string &s) {
    int start = 0;
    int end = s.length();
    string temp(s);

    while (start < end) {
	end--;
	swap(temp[start], temp[end]);
	start++;
    }

    return temp;
}

// Uses <cctype> and <string>
string makeLower(const string &s) {
    string temp(s);
    for (int i = 0; i < s.length(); i++)
	temp[i] = tolower(s[i]);
    return temp;
}

string removePunct(const string &s, const string &punct) {
    string noPunct; // initialized to empty string
    int sLength = s.length();
    int punctLength = punct.length();
    for (int i = 0; i < sLength; i++) {
	string aChar = s.substr(i, 1); // A one-character string
	// Find location of successive characters of src in punct
	int location = punct.find(aChar, 0);
	if (location < 0 || location >= punctLength)
	    noPunct = noPunct + aChar; // aChar is not in punct, keep it
    }
    return noPunct;
}

// uses functions makeLower, removePunct
bool isPal(const string &s) {
    string punct(",;:.?!'\" "); // includes a blank
    string str(s);
    str = makeLower(str);
    string lowerStr = removePunct(str, punct);

    return (lowerStr == reverse(lowerStr));
}
