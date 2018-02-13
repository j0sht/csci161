#include <iostream>
#include "image.h"
using namespace std;

int main() {
    // Test the empty constructor
    Image img1;
    bool condition = ((img1.getRows()) == 0 && (img1.getColumns() == 0) &&
		      (img1.getTitle() == ""));
    if (condition) // Should be true
	cout << "'Image 1' initialized to 0 rows, 0 columns, "
	     << "and an empty title\n";
    else
	cout << "img1 was not initialized to to expected values\n";

    // Test the four parameter constructor
    IntArrayPtr a = new int[3 * 3];
    for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	    a[i*3+j] = i+1;
    Image img2("Image 2", 3, 3, a);
    delete [] a;

    IntArrayPtr b = new int[3 * 3];
    for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	    b[i*3+j] = 3 - i;
    Image img3("Image 3", 3, 3, b);
    delete [] b;

    // Test the copy constructor
    Image *img4 = new Image(img3);
    img4->setTitle("Image 4");

    // Test the output operator
    cout << img2 << endl << endl << img3 << endl << endl << *img4 << endl
	 << endl;

    delete img4;
    cout << "Image 3 after deleting Image 4:\n";
    cout << img3 << endl << endl;

    try {
	// Test the addition and assignment operator
	img1 = img2 + img3;
	cout << img1 << endl << endl;
	IntArrayPtr c = new int[3 * 3];
	for (int i = 0; i < 3; i++)
	    for (int j = 0; j < 3; j++)
		c[i*3+j] = 2;
	Image img5("Image 5", 3, 3, c);
	delete [] c;
	cout << img5 << endl << endl;

	// Test equivalence
	if (img1 == img5) // Should be true
	    cout << '\"' << img1.getTitle() << "\" and \"" << img5.getTitle()
		 << "\" have the same content\n";
	else
	    cout << img1.getTitle() << " and " << img5.getTitle()
		 << " do not have the same content\n";
    } catch (string &s) {
	cout << img1.getTitle() << " + " << img2.getTitle()
	     << ": " << s << endl;
    }

    // Test input operator
    Image userImage;
    cin >> userImage;
    cout << "You entered:\n" << userImage << endl << endl;

    // Test histogram
    for (int i = 2; i <= 16; i++) {
	cout << "=======================\n"
	     << "Histogram Value: " << i << endl
	     << "=======================\n";
	userImage.histogram(i);
    }

    return 0;
}
