#include "student.h"
#include <iostream>
using namespace std;
Student::Student(): Person() {
    credits = 0;
    gpa = 0;
}
Student::Student(string name, int credits, double gpa): Person(name) {
    this->credits = credits;
    this->gpa = gpa;
}
Student::Student(const Student& student) {
    name = student.name;
    credits = student.credits;
    gpa = student.gpa;
}
Student& Student::operator =(const Student& rightSide) {
    if (this == &rightSide)
	return *this;
    name = rightSide.name;
    credits = rightSide.credits;
    gpa = rightSide.gpa;
    return *this;
}
void Student::display() const {
    cout << "Person named: " << name
	 << " with " << credits << " earned so far. GPA = "
	 << gpa << endl;
}
ostream& operator <<(ostream& outs, const Student& student) {
    outs << "Person named: " << student.name
	 << " with " << student.credits << " earned so far. GPA = "
	 << student.gpa;
    return outs;
}
istream& operator >>(istream& ins, Student& student) {
    cout << "Enter student's name: ";
    ins >> student.name;
    cout << "Enter credits earned: ";
    ins >> student.credits;
    cout << "Enter GPA: ";
    ins >> student.gpa;
    return ins;
}
