/*
 * Give a function definition corresponding to the following function
 *  declaration:
 *
 *  // Fills newShoe with values read from the keyboard
 *  void readShoeRecord(ShoeType &newShoe);
 */
#include <iostream>
using namespace std;

struct ShoeType {
    char style;
    double price;
};

void readShoeRecord(ShoeType &newShoe) {
    cout << "Enter style character: ";
    cin >> newShoe.style;
    cout << "Enter price: ";
    cin >> newShoe.price;
}

int main() {
    ShoeType s1;
    readShoeRecord(s1);
    cout << "Style: " << s1.style << "; Price: $" << s1.price << endl;
    return 0;
}
