#include "flag.h"
#include <iostream>
using namespace std;


int main() {
    Flag starFlag(5, 3, '*');
    Flag *flagPtr = new Flag();

    cout << "info of star flag:\n"
         << "width: " << starFlag.getWidth() << " "
         << "hight: " << starFlag.getHeight() << endl;

    starFlag.draw();

    if (starFlag.bigFlag()) {
        cout << "star flag is a big flag.\n";
    } else {
        cout << "star flag is a small flag.\n";
    }

    cout << "info of a dynamically created flag:\n"
         << "width: " << flagPtr->getWidth() << " "
         << "hight: " << flagPtr->getHeight() << endl;

    flagPtr->draw();

    flagPtr->resize(7, 5);
    flagPtr->draw();

    if (flagPtr->bigFlag()) {
        cout << "the dynamically created flag is a big flag.\n";
    } else {
        cout << "the dynamically created flag is a small flag.\n";
    }

    delete flagPtr;

    return 0;
}
