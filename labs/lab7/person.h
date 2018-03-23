#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person {
public:
    Person();
    Person(string name);
    Person(const Person& person);
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    virtual void display() const;
protected:
    string name;
};
#endif
