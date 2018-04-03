/*
 * File: country.cpp
 * Author: Joshua Tate
 * Date: April 2, 2018
 * Updated: April 2, 2018
 *
 * Purpose:
 *    - This file contains the implementation of the Country class.
 */
#include "country.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Contructor / Destructor
Country::Country() {
    name = NULL;
    capital = NULL;
    language = NULL;
    area = 0.0;
    population = 0;
    description = NULL;
}
Country::~Country() {
    delete name;
    delete capital;
    delete language;
    delete description;
}
// I/O Friend Functions
ostream& operator <<(ostream& outs, const Country& country) {
    outs << "--------------------"
	 << "       Name: " << *(country.name) << endl
	 << "    capital: " << *(country.capital) << endl
	 << "   language: " << *(country.language) << endl
	 << "       area: " << country.area << endl
	 << " population: " << country.population << endl
	 << "description: " << *(country.description) << endl;
    return outs;
}
istream& operator >>(istream& ins, Country& country) {
    getline(ins, *(country.name));
    getline(ins, *(country.capital));
    getline(ins, *(country.language));
    string garbage;
    ins >> country.area;
    ins >> country.population;
    getline(ins, garbage);
    getline(ins, *(country.description));
    return ins;
}
