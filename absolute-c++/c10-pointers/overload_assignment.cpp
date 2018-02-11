#include <iostream>
#include <cstdlib>
using namespace std;

// Object of this class are partially filled arrays of doubles
class PFArrayD {
public:
    PFArrayD(); // Initializes with a capacity of 50
    PFArrayD(int size);
    PFArrayD(const PFArrayD& pfaObject); // copy constructor
    // Precondition: The array is not full
    // Postcondition: The element has been added
    void addElement(double element);
    // Returns true if the array is full, false otherwise
    bool full() const { return (capacity == used); }
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    // Empties the array
    void emptyArray() { used = 0; }
    // Read and change access to elements 0 through numberUsed - 1
    double& operator [](int index);
    PFArrayD& operator =(const PFArrayD& rightSide); // Overloaded assignment
    ~PFArrayD();
private:
    double *a; // for an array of doubles
    int capacity; // for the size of the array
    int used; // for the number of array positions currently in use
};

// Conducts one test of the class PFArrayD
void testPFArrayD();

int main() {
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do {
	testPFArrayD();
	cout << "Test again? (y/n) ";
	cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));
    return 0;
}

// Definition for the member functions for the class PFArrayD
// They require the following include and using directives:
// #include <iostream>
// #include <cstdlib>
// using std::cout;
PFArrayD::PFArrayD(): capacity(50), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(int size): capacity(size), used(0) {
    a = new double[capacity];
}

// Copy constructor
PFArrayD::PFArrayD(const PFArrayD& pfaObject) {
    capacity = pfaObject.capacity;
    used = pfaObject.used;
    a = new double[capacity];
    for (int i = 0; i < used; i++)
	a[i] = pfaObject.a[i];
}

void PFArrayD::addElement(double element) {
    if (used >= capacity) {
	cout << "Attempt to exceed capacity in PFArrayD.\n";
	exit(0);
    }
    a[used] = element;
    used++;
}

double& PFArrayD::operator [](int index) {
    if (index >= used) {
	cout << "Illegal index in PFArrayD.\n";
	exit(0);
    }
    return a[index];
}

// Overloaded assignment
PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide) {
    // Also checks for the case of have the same object
    //  on both sides of the assignment operator
    if (capacity != rightSide.capacity) {
	delete [] a;
	a = new double[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
	a[i] = rightSide.a[i];

    return *this;
}

PFArrayD::~PFArrayD() {
    delete [] a;
}

void testPFArrayD() {
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full())) {
	temp.addElement(next);
	cin >> next;
    }

    cout << "You entered the following "
	 << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
	cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}
