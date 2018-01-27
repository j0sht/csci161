/*
 *  Write a void function definition for a function called addTax.
 *
 *  The function addTax has two formal parameters: taxRate, which is the
 *   amount of sales tax expressed as a percentage; and cost which is the
 *   cost of an item before tax.
 *
 *  The function changes the value of cost so that it includes sales tax.
 */
#include <iostream>
using namespace std;

void addTax(double taxRate, double &cost);

int main() {
    double cost = 1.00;
    double taxRate = 0.05;
    cout << "Cost before 5% sales tax: " << cost << endl;
    addTax(taxRate, cost);
    cout << "Cost after 5% sales tax: " << cost << endl;
    return 0;
}

void addTax(double taxRate, double &cost) {
    cost += cost * taxRate;
}
