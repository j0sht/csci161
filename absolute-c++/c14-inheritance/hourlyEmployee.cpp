// This is the file hourlyEmployee.cpp
// This is the implementation for the class HourlyEmployee.
// The interface for the class HourlyEmployee is in the header
//  file hourlyEmployee.h
#include <string>
#include <iostream>
#include "hourlyEmployee.h"
using namespace std;

// Body deliberately empty
// If a constructor definition for a derived class does not include
//  an invocation of a constructor for the base class, then the default
//  (zero-argument) version of the base class constructor will be
//  invoked automatically.
// The default initializer could have been written as
//  HourlyEmployee(): wageRate(0), hours(0) {}
// However, convention dictates you should include call to base
//  class constructor
HourlyEmployee::HourlyEmployee(): Employee(), wageRate(0), hours(0) {}
HourlyEmployee::HourlyEmployee(const string& name, const string& ssn,
			       double wageRate, double hours):
    Employee(name, ssn) {
    this->wageRate = wageRate;
    this->hours = hours;
}
void HourlyEmployee::setRate(double newWageRate) {
    wageRate = newWageRate;
}
double HourlyEmployee::getRate() const {
    return wageRate;
}
void HourlyEmployee::setHours(double hoursWorked) {
    hours = hoursWorked;
}
double HourlyEmployee::getHours() const {
    return hours;
}
// Note that C++ allows you to drop the const on the function
//  when it is redefined in a derived class.
void HourlyEmployee::printCheck() {
    setNetPay(hours * wageRate);
    cout << "\n_________________________________________\n"
	 << "Pay to the order of " << getName() << endl
	 << "The sum of " << getNetPay() << " Dollars\n"
	 << "\n_________________________________________\n"
	 << "Cheque Stub: NOT NEGOTIABLE\n"
	 << "Employee number: " << getSSN() << endl
	 << "Hourly employee.\nHours worked: " << hours
	 << " Rate: " << wageRate << " Pay: " << getNetPay() << endl
	 << "\n_________________________________________\n";
}
