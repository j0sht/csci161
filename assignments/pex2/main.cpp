#include <iostream>
#include "image.h"

using namespace std;

int main()
{
    Image I1;
    Image I2;
    int *A = new int[3*3];
    for(int i = 0; i < 9; i++)
        A[i] = 255/(i+1);

    cin >> I1 >> I2;

    Image *pimage = new Image("random image", 3, 3, A);
    delete [] A;

       Image I3  = (*pimage);

    cout << "The image I1: \n" << I1
         << endl;

    try {
        cout << "I1  +  I2  = \n"
             << I1 + I2 << endl;
    } catch (string & e) {
        cout << "I1 and I2: " << e << endl;
    }

    cout << I3 << endl;

    pimage->histogram(4);
    
    delete pimage;

    return 0;
}
