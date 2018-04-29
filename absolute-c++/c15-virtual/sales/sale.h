// This is the header file sale.h
// This is the interface for the class Sale
// Sale is a class for simple sales.
#ifndef SALE_H
#define SALE_H

class Sale {
public:
    Sale();
    Sale(double thePrice);
    double getPrice() const;
    void setPrice(double newPrice);
    virtual double bill() const;
    // Returns the savings if you buy other instead of
    //  calling object.
    double savings(const Sale& other) const;
private:
    double price;
};
// Compares two sales to see which is larger
bool operator <(const Sale& first, const Sale& second);
#endif
