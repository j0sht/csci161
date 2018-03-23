#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <iostream>
using namespace std;
class Student: public Person {
public:
    Student();
    Student(string name, int credits, double gpa);
    Student(const Student& student);
    Student& operator =(const Student& rightSide);
    int getCredits() const { return credits; }
    void setCredits(int credits) { this->credits = credits; }
    double getGPA() const { return gpa; }
    void setGPA(double gpa) { this->gpa = gpa; }
    void display() const;
private:
    int credits;
    double gpa;
};
#endif
