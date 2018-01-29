// Law office billing program.
#include <iostream>
using namespace std;

// Dollars per quarter
const double RATE = 150.0;

// Returns the charges for hoursWorked hours and
//  minutesWorked minutes of legal services.
double fee(int hoursWorked, int minutesWorked);

int main() {
    int hours, minutes;
    double bill;

    cout << "Welcome to the law office of\n"
	 << "Dewey, Cheatham, and Howe.\n"
	 << "The law office with a heart.\n"
	 << "Enter the hours and minutes"
	 << " of your consultation:\n";
    cin >> hours >> minutes;

    // the value of minutes will not be affected by call to fee
    bill = fee(hours, minutes);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "For " << hours << " hours and " << minutes
	 << " minutes, your bill is $" << bill << endl;

    return 0;
}

double fee(int hoursWorked, int minutesWorked) {
    int quarterHours;

    // minutesWorked is a local variable intialized to
    //  the value of minutes in main
    minutesWorked = hoursWorked * 60 + minutesWorked;
    quarterHours = minutesWorked/15;
    return (quarterHours * RATE);
}
