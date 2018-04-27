#include <iostream>
#include "complexNumber.h"
using namespace std;

int main()
{
    ComplexNumber n1(3.5, 7.0); // 3.5 + 7.0i
    ComplexNumber n2;  // 0 + 0i, default constructor

    cout << "Two complex numbers: \n"
         << "number 1: " << n1 << endl // output operator
	 << "number 2: " << n2 << endl;
    cout << "Enter a complex number\n";
    cin >> n1; // input operator
    cout << "Enter another complex number\n";
    cin >> n2;

    ComplexNumber n3 = (++n2); // incremental operator and copy contructor
    ComplexNumber n4 = -n1; // negation and copy constructor
    cout << n3 << " + " << n4 << " = " << n3+n4 << endl;
    cout << n3 << " - " << n4 << " = " << n3-n4 << endl;
    cout << n3 << " * " << n4 << " = " << n3*n4 << endl;

    if (n1 == n2) // equality comparison
        cout << "number 1 and number 2 are the same.\n";
    else
        cout << "number 1 and number 2 are NOT the same.\n";

    n3[0] = 10.5; // change the real part to 10.5, overload index operator []
    n3[1] = n3[0]; // change the imaginary part
                   // to be the same as the real part
    cout << "Now the number becomes: " << n3 << endl;

    return 0;
}
