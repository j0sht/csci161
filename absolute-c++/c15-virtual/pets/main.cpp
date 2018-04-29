// Program to illustrate use of virtual function to defeat the
//  slicing problem.
#include <string>
#include <iostream>
using namespace std;

// Member variables are public to keep example simple
class Pet {
public:
    string name;
    virtual void print() const;
};

class Dog: public Pet {
public:
    string breed;
    // keyword virtual is not needed, but inserted for clarity
    virtual void print() const;
};

int main() {
    Dog vdog;
    Pet vpet;
    vdog.name = "Tiny";
    vdog.breed = "Great Dane";
    vpet = vdog;
    cout << "The slicing problem:\n";
    // vpet.breed; is illegal since class Pet has no member named breed.
    vpet.print();
    cout << "Note that it was print from Pet that was invoked.\n";
    cout << "The slicing problem defeated:\n";
    Pet *ppet;
    Dog *pdog;
    pdog = new Dog;
    pdog->name = "Tiny";
    pdog->breed = "Great Dane";
    ppet = pdog;
    // Two calls to print, print the same thing
    ppet->print();
    pdog->print();
    // The following, which accesses member variables directly
    //  rather than via virtual functions, would produce an error:
    // cout << "name: " << ppet->name << " breed: "
    // 	 << ppet->breed << endl;
    // It generates an error message saying class Pet has no member
    //  named breed.
    return 0;
}

void Dog::print() const {
    cout << "Name: " << name << endl
	 << "Breed: " << breed << endl;
}
void Pet::print() const {
    cout << "Name: " << name << endl;
}
