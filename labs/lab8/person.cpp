#include "person.h"
#include <iostream>
using namespace std;
Person::Person() {
    name = "";
}
Person::Person(string name) {
    this->name = name;
}
Person::Person(const Person& person) {
    name = person.name;
}
void Person::display() const {
    cout << "Person named: " << name << endl;
}
