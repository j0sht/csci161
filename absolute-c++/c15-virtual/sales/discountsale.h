// This is the file discountsale.h
// This is the interface for the class DiscountSale.
#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"

class DiscountSale: public Sale {
public:
    DiscountSale();
    // Discount is expressed as a percentage of the price
    // A negative discount is a price increase.
    DiscountSale(double thePrice, double theDiscount);
    double getDiscount() const;
    void setDiscount(double newDiscount);
    // Since bill was declared virtual in the base class,
    //  it is automatically virtual in the derived class DiscountSale.
    // You can add the modifier virtual to the declaration of bill or
    //  omit it here; in either case bill is virtual in DiscountSale.
    double bill() const;
private:
    double discount;
};
#endif
