#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Class for amounts of money in U.S. currency
class Money {
public:
    Money();
    Money(double amount);
    Money(int dollars, int cents);
    Money(int dollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    void input(); // Reads the dollar sign as well as the amount number
    void output() const;
    // Operators for Money
    friend const Money operator +(const Money &amount1,
				  const Money &amount2);
    friend const Money operator -(const Money &amount1,
				  const Money &amount2);
    friend bool operator ==(const Money &amount1, const Money &amount2);
    friend const Money operator -(const Money &amount);
private:
    int dollars;
    int cents;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};

int main() {
    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    yourAmount.input();
    cout << "Your amount is ";
    yourAmount.output();
    cout << endl;
    cout << "My amount is ";
    myAmount.output();
    cout << endl;

    if (yourAmount == myAmount)
	cout << "We have the same amount.\n";
    else
	cout << "One of us is richer.\n";

    Money ourAmount = yourAmount + myAmount;
    yourAmount.output(); cout << " + "; myAmount.output();
    cout << " equals "; ourAmount.output(); cout << endl;

    Money diffAmount = yourAmount - myAmount;
    yourAmount.output(); cout << " - "; myAmount.output();
    cout << " equals "; diffAmount.output(); cout << endl;
    return 0;
}

// No need to use friend keyword here
const Money operator +(const Money &amount1, const Money &amount2) {
    // Friends have direct access to member variables
    int allCents1 = amount1.cents + amount1.dollars * 100;
    int allCents2 = amount2.cents + amount2.dollars * 100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents); // Money can be negative
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if (sumAllCents < 0) {
	finalDollars = -finalDollars;
	finalCents = -finalCents;
    }
    // Constructors can return an object
    return Money(finalDollars, finalCents);
}

const Money operator -(const Money &amount1, const Money &amount2) {
    int allCents1 = amount1.cents + amount1.dollars * 100;
    int allCents2 = amount2.cents + amount2.dollars * 100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if (diffAllCents < 0) {
	finalDollars = -finalDollars;
	finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
    return ((amount1.dollars == amount2.dollars) &&
	    (amount1.cents == amount2.cents));
}

const Money operator -(const Money &amount) {
    return Money(-amount.dollars, -amount.cents);
}

// Constructors
Money::Money(): dollars(0), cents(0) {}
Money::Money(double amount): dollars(dollarsPart(amount)),
			     cents(centsPart(amount)) {}
Money::Money(int dollars) {
    this->dollars = dollars;
}

// Uses cstdlib
Money::Money(int dollars, int cents) {
    if ((dollars < 0 && cents > 0) || (dollars > 0 && cents < 0)) {
	cout << "Inconsisten money data.\n";
	exit(1);
    }
    this->dollars = dollars;
    this->cents = cents;
}

double Money::getAmount() const {
    return (dollars + (cents * 0.01));
}

int Money::getDollars() const {
    return dollars;
}

int Money::getCents() const {
    return cents;
}

// Uses iostream and cstdlib
void Money::output() const {
    int absDollars = abs(dollars);
    int absCents = abs(cents);
    if (dollars < 0 || cents < 0)
	cout << "$-";
    else
	cout << '$';
    cout << absDollars;

    if (absCents >= 10)
	cout << '.' << absCents;
    else
	cout << '.' << '0' << absCents;
}

// Uses iostream and cstdlib
void Money::input() {
    char dollarSign;
    cin >> dollarSign;
    if (dollarSign != '$') {
	cout << "No dollar sign in Money input.\n";
	exit(1);
    }
    double amountAsDouble;
    cin >> amountAsDouble;
    dollars = dollarsPart(amountAsDouble);
    cents = centsPart(amountAsDouble);
}

int Money::dollarsPart(double amount) const {
    return static_cast<int>(amount);
}

// Uses cmath
int Money::centsPart(double amount) const {
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100;
    // % can misbehave on negatives
    if (amount < 0)
	intCents = -intCents;
    return intCents;
}

// Uses cmath
int Money::round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}
