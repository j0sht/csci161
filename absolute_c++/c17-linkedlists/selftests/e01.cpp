#include <iostream>
using namespace std;

struct Box {
    string name;
    int number;
    Box *next;
};
typedef Box* BoxPtr;

int main() {
    BoxPtr head;
    head = new Box;
    head->name = "Sally";
    head->number = 18;

    // head->name == (*head).name
    cout << (*head).name << endl;
    cout << head->name << endl;
    cout << (*head).number << endl;
    cout << head->number << endl;
    delete head;

    return 0;
}
