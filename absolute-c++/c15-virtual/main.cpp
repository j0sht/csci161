#include <iostream>
using namespace std;

class A {
public:
    virtual void eat() { cout << "Class A" << endl; }
};
class B: public A {};
class C: public B {
public:
    virtual void eat() { cout << "Class C" << endl; }
};

int main() {
    A a; B b; C c;
    a.eat(); // When not virtual or virtual: Class A
    b.eat(); // When not virtual or virtual: Class A
    c.eat(); // When not virtual or virtual: Class C
    A* as[3] = { &a, &b, &c };
    for (int i = 0; i < 3; i++)
	// When not virtual: all print Class A
	// When virtual: last prints Class C
	as[i]->eat(); 

    return 0;
}
