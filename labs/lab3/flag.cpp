#include "flag.h"
#include <iostream>
using namespace std;

Flag::Flag(int width, int height, char symbol) {
    this->width = width;
    this->height = height;
    this->symbol = symbol;
}

Flag::Flag() {
    width = height = 1;
    symbol = '*';
}

Flag::~Flag() {}

int Flag::getWidth() {
    return width;
}

int Flag::getHeight() {
    return height;
}

char Flag::getSymbol() {
    return symbol;
}

void Flag::resize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
}

void Flag::changeSymbol(char newSymbol) {
    symbol = newSymbol;
}

int Flag::calculate() {
    return width * height;
}

void Flag::draw() {
    for (int i = 0; i < height; i++) {
	for (int j = 0; j < width; j++)
	    cout << symbol;
	cout << endl;
    }
}

bool Flag::bigFlag() {
    return ((width * height) > 25);
}
