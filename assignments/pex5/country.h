/*
 * File: country.h
 * Author: Joshua Tate
 * Date: April 2, 2018
 * Updated: April 11, 2018
 *
 * Purpose:
 *    - This file contains the definition of a Country, which consists of:
 *        - name (string*): The country's name.
 *        - capital (string*): Name of the capital of the country.
 *        - language (string*): Official language(s) used in the country.
 *        - area (double): The total area in kilometers of the country.
 *        - population (long int): The most recently estimated population.
 *        - description (string*): Short description of country.
 */
#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
using namespace std;

typedef long int l_int;

class Country {
public:
    Country();
    ~Country();
    // Getter / setters
    string& getName() const { return *name; }
    string& getCapital() const { return *capital; }
    string& getLanguage() const { return *language; }
    double getArea() const { return area; }
    l_int getPopulation() const { return population; }
    string& getDescription() const { return *description; }
    void setName(string& name);
    void setCapital(string& capital);
    void setLanguage(string& language);
    void setArea(double area) { this->area = area; }
    void setPopulation(l_int population) { this->population = population; }
    void setDescription(string& desc);
    // I/O Friend Functions
    friend ostream& operator <<(ostream& outs, const Country& country);
    friend istream& operator >>(istream& ins, Country& country);
private:
    string* name;
    string* capital;
    string* language;
    string* description;
    double area;
    l_int population;
    // Deletes heap allocated memory if it exists
    void deleteFields();
};
typedef Country* CountryPtr;
typedef Country& CountryRef;
#endif
