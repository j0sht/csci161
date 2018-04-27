#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3)
	exit(1);
    int arg1Len = strlen(argv[1]);
    int arg2Len = strlen(argv[2]);
    int shortest = (arg1Len < arg2Len) ? arg1Len : arg2Len;
    int i;
    for (i = 0; i < shortest; i++) {
	if (tolower(argv[1][i]) != tolower(argv[2][i])) {
	    cout << "The two strings become different "
		 << "at position " << i << ".\n";
	    return 0;
	}
    }

    if (arg1Len != arg2Len)
	cout << "The two string become different "
	     << "at position " << i << ".\n";
    else
	cout << "The two strings are the same.\n";
    return 0;
}
