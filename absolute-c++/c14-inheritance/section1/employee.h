// This is the header file employee.h
// This is the interface for the class Employee.
// This is primarily intended to be used as a base class to derive
//  classes for different kinds of employees
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
public:
    Employee();
    Employee(const string& name, const string& ssn);
    string getName() const;
    string getSSN() const;
    double getNetPay() const;
    void setName(const string& newName);
    void setSSN(const string& newSSN);
    void setNetPay(double newNetPay);
    void printCheck() const;
private:
    string name;
    string ssn;
    double netPay;
};
#endif
