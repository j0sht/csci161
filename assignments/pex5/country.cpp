/*
 * File: country.cpp
 * Author: Joshua Tate
 * Date: April 2, 2018
 * Updated: April 11, 2018
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
    deleteFields();
}
// Setters
void Country::setName(string& name) {
    string* curr = this->name;
    this->name = &name;
    delete curr;
}
void Country::setCapital(string& capital) {
    string* curr = this->capital;
    this->capital = &capital;
    delete curr;
}
void Country::setLanguage(string& language) {
    string* curr = this->language;
    this->language = &language;
    delete curr;
}
void Country::setDescription(string& description) {
    string* curr = this->description;
    this->description = &description;
    delete curr;
}
// I/O Friend Functions
ostream& operator <<(ostream& outs, const Country& country) {
    outs << "--------------------\n"
	 << "       Name: " << *(country.name) << endl
	 << "    capital: " << *(country.capital) << endl
	 << "   language: " << *(country.language) << endl
	 << "       area: " << fixed << setprecision(1) << country.area << endl
	 << " population: " << country.population << endl
	 << "description: " << *(country.description);
    return outs;
}
istream& operator >>(istream& ins, Country& country) {
    country.deleteFields();
    country.name = new string;
    getline(ins, *(country.name));
    country.capital = new string;
    getline(ins, *(country.capital));
    country.language = new string;
    getline(ins, *(country.language));
    string garbage;
    ins >> country.area;
    ins >> country.population;
    getline(ins, garbage);
    country.description = new string;
    getline(ins, *(country.description));
    return ins;
}
// Country methods
void Country::deleteFields() {
    string* properties[4] = { name, capital, language, description };
    for (int i = 0; i < 4; i++)
	if (properties[i])
	    delete properties[i];
}
