#include "person.h"
#include "student.h"
#include <iostream>
using namespace std;

int main() {
    Person p1("Person 1");
    Student s1("Student 1", 20, 4.0);
    p1.display();
    s1.display();
    p1.setName("Josh");
    s1.setName("John");
    cout << p1.getName() << endl;
    cout << s1.getName() << endl;
    s1.setCredits(30);
    cout << s1.getCredits() << endl;
    s1.setGPA(3.3);
    cout << s1.getGPA() << endl;
    Student s2 = s1;
    Person p2(p1);
    p2.display();
    s2.display();
    return 0;
}
