#include <iostream>
using namespace std;

int main() {
    int countDown;

    cout << "How many greetings do you want? ";
    cin >> countDown;

    do {
	cout << "Hello ";
	countDown -= 1;
    } while (countDown > 0); // must include semicolon

    cout << endl;
    cout << "That's all!\n";

    return 0;
}
