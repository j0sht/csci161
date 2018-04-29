// This is the header file salariedEmployee.h
// This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"
using namespace std;

class SalariedEmployee: public Employee {
public:
    SalariedEmployee();
    SalariedEmployee(const string& name, const string& ssn,
		     double theWeeklySalary);
    double getSalary() const;
    void setSalary(double newSalary);
    void printCheck();
private:
    double salary; // weekly
};
#endif
