#include "family.h"

int main(int argc, char *argv[])
{
    string filename;
    if (argc != 2) {
        filename = "MyFamily.txt";
    } else {
        filename = argv[1];
    }
    try {
        FamilyTree myFamily(filename);

        cout << "\npre order traverse:\n";
        myFamily.preOrder();

        cout << "\npost order traverse:\n";
        myFamily.postOrder();
    } catch (string e) {
        cout << e << endl;
    }

    return 0;
}

