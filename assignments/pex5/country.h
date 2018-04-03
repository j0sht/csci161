/*
 * File: country.h
 * Author: Joshua Tate
 * Date: April 2, 2018
 * Updated: April 2, 2018
 *
 * Purpose:
 *    - This file contains the definition of a Country, which consists of:
 *        - name (string*): The country's name.
 *           * MUST BE UNIQUE.
 *           * CANNOT BE EMPTY.
 *           * May contain whitespaces.
 *
 *        - capital (string*): Name of the capital of the country.
 *           * May contain whitespaces.
 *
 *        - language (string*): Official language(s) used in the country.
 *
 *        - area (double): The total area in kilometers of the country.
 *
 *        - population (long int): The most recently estimated population.
 *
 *        - description (string*): Short description of country.
 *           * MAX 255 characters.
 *           * MUST NOT CONTAIN NEW LINE CHARACTERS.
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
    void setName(string& name) { this->name = &name; }
    void setCapital(string& capital) { this->capital = &capital; }
    void setLanguage(string& language) { this->language = &language; }
    void setArea(double area) { this->area = area; }
    void setPopulation(l_int population) { this->population = population; }
    void setDescription(string& desc) { description = &desc; }
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
};
#endif
