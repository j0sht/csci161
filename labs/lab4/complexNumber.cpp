#include <iostream>
#include <cstdlib>
#include "complexNumber.h"
using namespace std;

ComplexNumber::ComplexNumber(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

ComplexNumber::ComplexNumber() {
    real = imaginary = 0;
}

const ComplexNumber ComplexNumber::operator +(const ComplexNumber &n2) const
{
    return ComplexNumber(real + n2.real, imaginary + n2.imaginary);
}

const ComplexNumber ComplexNumber::operator -(const ComplexNumber &n2) const
{
    return ComplexNumber(real - n2.real, imaginary - n2.imaginary);
}

const ComplexNumber ComplexNumber::operator *(const ComplexNumber &n2) const
{
    double newReal = (real * n2.real) - (imaginary * n2.imaginary);
    double newI = (imaginary * n2.imaginary) + (real * n2.real);
    return ComplexNumber(newReal, newI);
}

const ComplexNumber ComplexNumber::operator -() const {
    return ComplexNumber(-real, -imaginary);
}

bool ComplexNumber::operator ==(const ComplexNumber &n2) const {
    return (real == n2.real) && (imaginary == n2.imaginary);
}

ComplexNumber ComplexNumber::operator ++() {
    real++;
    imaginary++;
    return ComplexNumber(real, imaginary);
}

double& ComplexNumber::operator [](int index) {
    switch (index) {
    case 0:
	return real;
    case 1:
	return imaginary;
    default:
	cout << "Illegal index value.\n";
	exit(1);
    }
}

ostream& operator <<(ostream &outs, const ComplexNumber &n) {
    outs << n.real << "+" << n.imaginary << "i";
    return outs;
}

istream& operator >>(istream &ins, ComplexNumber &n) {
    cout << "Enter real number: ";
    ins >> n.real;
    cout << "Enter imaginary part: ";
    ins >> n.imaginary;
    return ins;
}
