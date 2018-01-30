/*
 * Give a function definition corresponding to the following function
 *  declaration:
 *
 *  // Returns a structure that is the same as its argument,
 *  //  but with the price reduced by 10%
 *  ShoeType discount(ShoeType oldRecord);
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

ShoeType discount(ShoeType oldRecord) {
    ShoeType sale = { oldRecord.style,
		      oldRecord.price - (oldRecord.price * 0.10) };
    return sale;
}

int main() {
    ShoeType s1;
    readShoeRecord(s1);
    cout << "Style: " << s1.style << "; Regular Price: $"
	 << s1.price << endl;
    ShoeType sale = discount(s1);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Sale price: $" << sale.price << endl;
    return 0;
}
