// This is the file employee.cpp
// This is the implementation for the class Employee.
// The interface for the class Employee is in the header file employee.h
#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using namespace std;

// Body is deliberatly empty
Employee::Employee(): name("No name yet"), ssn("No number yet"), netPay(0) {}
Employee::Employee(const string& name, const string& ssn) {
    this->name = name;
    this->ssn = ssn;
}
string Employee::getName() const {
    return name;
}
string Employee::getSSN() const {
    return ssn;
}
double Employee::getNetPay() const {
    return netPay;
}
void Employee::setName(const string& newName) {
    name = newName;
}
void Employee::setSSN(const string& newSSN) {
    ssn = newSSN;
}
void Employee::setNetPay(double newNetPay) {
    netPay = newNetPay;
}
void Employee::printCheck() const {
    cout << "\nERROR: printCheck FUNCTION CALLED FOR AN\n"
	 << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
	 << "Check with the author of this program about this bug.\n";
    exit(1);
}
