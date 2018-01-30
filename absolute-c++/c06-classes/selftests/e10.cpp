/*
 * Write an appropriate definition for the member function set
 */
#include <iostream>
using namespace std;

class Temperature {
public:
    // Sets the member variables to the values given as arguments
    void set(double newDegrees, char newScale);
    double degrees;
    char scale; // 'F' for Fahrenheit or 'C' for Celsius
};

int main() {
    Temperature t;
    t.set(22, 'C');
    cout << "It is " << t.degrees << t.scale << endl;
    return 0;
}

void Temperature::set(double newDegrees, char newScale) {
    degrees = newDegrees;
    scale = newScale;
}
