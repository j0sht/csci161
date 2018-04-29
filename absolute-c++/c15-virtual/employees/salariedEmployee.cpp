// This is the file salariedEmployee.cpp
// This is the implementation for the class SalariedEmployee.
// The interface for SalariedEmployee is in the header file
//  salariedEmployee.h
#include <iostream>
#include <string>
#include "salariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(): Employee(), salary(0) {}
SalariedEmployee::SalariedEmployee(const string& name,
				   const string& ssn,
				   double theWeeklySalary):
    Employee(name, ssn), salary(theWeeklySalary) {}

double SalariedEmployee::getSalary() const {
    return salary;
}
void SalariedEmployee::setSalary(double newSalary) {
    salary = newSalary;
}
void SalariedEmployee::printCheck() {
    setNetPay(salary);
    cout << "\n_________________________________________\n"
	 << "Pay to the order of " << getName() << endl
	 << "The sum of " << getNetPay() << " Dollars\n"
	 << "\n_________________________________________\n"
	 << "Cheque Stub: NOT NEGOTIABLE\n"
	 << "Employee number: " << getSSN() << endl
	 << "Salaried Employee. Regular Pay: " << salary << endl
	 << "\n_________________________________________\n";
}
