// This is the header file employee.h
// This is the interface for the class Employee.
// This is primarily intended to be used as a base class to derive
//  classes for different kinds of employees
/*
 * This is an improved version of the Employee class
 *
 * Using pure virtual functions, the class has been made an abstract class
 *
 * With pure virtual functions, the compiler enforces a ban on calling
 *  Employee::printCheck()
 */
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
    // The word virtual and the '= 0' in the function heading
    //  tells the compiler that this is a pure virtual function.
    // Any class that has one or more pure virtual functions is
    //  considered an abstract class in C++
    virtual void printCheck() = 0;
private:
    string name;
    string ssn;
    double netPay;
};
#endif
