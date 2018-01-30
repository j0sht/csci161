// Program to demonstrate the CDAccount structure type
#include <iostream>
using namespace std;

struct Date {
    int month, day, year;
};

// Structure for a bank certificate of deposit:
struct CDAccount {
    double balance;
    double interestRate;
    int term; // months until maturity
    Date maturity; // date when CD matures
    double balanceMaturity;
};

// Postcondition: theAccount.balance, theAccount.interestRate, and
//  the Account.term have been given values that the user entered
//  at the keyboard
void getCDData(CDAccount &theAccount);

// Postcondition: theDate.month, theDate.day, and theDate.year
//  have been given values that the user entered at the keyboard
void getDate(Date &date);

int main() {
    CDAccount account;
    cout << "Enter account data on the day account was opened:\n";
    getCDData(account);

    double rateFraction, interest;
    rateFraction = account.interestRate / 100.0;
    interest = account.balance * (rateFraction * (account.term / 12.0));
    account.balanceMaturity = account.balance + interest;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "When your CD matured on "
	 << account.maturity.month << "-" << account.maturity.day
	 << "-" << account.maturity.year << endl
	 << "it had a balance of $"
	 << account.balanceMaturity << endl;
    return 0;
}

// Uses iostream
void getCDData(CDAccount &theAccount) {
    cout << "Enter account initial balance: $";
    cin >> theAccount.balance;
    cout << "Enter account interest rate: ";
    cin >> theAccount.interestRate;
    cout << "Enter the number of months until maturity: ";
    cin >> theAccount.term;
    cout << "Enter the maturity date:\n";
    getDate(theAccount.maturity);
}

// Uses iostream
void getDate(Date &date) {
    cout << "Enter month: ";
    cin >> date.month;
    cout << "Enter day: ";
    cin >> date.day;
    cout << "Enter year: ";
    cin >> date.year;
}
