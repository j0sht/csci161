// This is the header file for hourlyEmployee.h
// This is the interface for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <string>
#include "employee.h"
using namespace std;

// The defintion of a derived class begins like any other class
//  definition but adds a colon, the reserved word public and the
//  name of the base class to the first line of the class definition.
// The derived class automatically receives all the member variables
//  and member functions of the base class (such as Employee) and
//  can add additional member variables and member functions.
// The definition of the classs HourlyEmployee does not mention the
//  member variables name, ssn, and netPay but every object of the class
//  HourlyEmployee has these member variables. You should not redeclare them.
// HourlyEmployee also inherits all the member functions from the class
//  Employee.
class HourlyEmployee: public Employee {
public:
    HourlyEmployee();
    HourlyEmployee(const string& name, const string& ssn,
		   double wageRate, double hours);
    void setRate(double newWageRate);
    double getRate() const;
    void setHours(double hoursWorked);
    double getHours() const;
    // Only list the declaration of an inherited member function
    //  if you want to change the definition of the function.
    void printCheck();
private:
    double wageRate;
    double hours;
};
#endif
