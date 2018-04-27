#include <iostream>
using namespace std;

class ComplexNumber {
public:
    ComplexNumber(double real, double imaginary);
    ComplexNumber();

    const ComplexNumber operator +(const ComplexNumber &n2) const;
    const ComplexNumber operator -(const ComplexNumber &n2) const;
    const ComplexNumber operator *(const ComplexNumber &n3) const;
    const ComplexNumber operator -() const;
    bool  operator ==(const ComplexNumber &n2) const;
    ComplexNumber operator ++();
    double& operator [](int index);
    friend ostream& operator <<(ostream &outs, const ComplexNumber &n);
    friend istream& operator >>(istream &ins, ComplexNumber &n);
private:
    double real, imaginary;
};
