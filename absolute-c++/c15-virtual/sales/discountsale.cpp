// This is the implementation for the class DiscountSale.
// This is the file discountsale.cpp
// The interface for the class DiscountSale is in the header file
//  discountsale.h
#include "discountsale.h"

DiscountSale::DiscountSale(): Sale(), discount(0) {}
DiscountSale::DiscountSale(double thePrice, double theDiscount):
    Sale(thePrice), discount(theDiscount) {}
double DiscountSale::getDiscount() const {
    return discount;
}
void DiscountSale::setDiscount(double newDiscount) {
    discount = newDiscount;
}
// You do not repeat the qualifier virtual in the function definition
double DiscountSale::bill() const {
    double fraction = discount / 100;
    return (1 - fraction) * getPrice();
}
