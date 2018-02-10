#include <iostream>
using namespace std;

typedef IntArrayPtr int*;

class Image {
public:
    static int getMaxRows();
    static int getMaxColumns();
    // Creates an image object, whose title is an empty string and
    //  whose size is 0 rows and 0 columns
    Image();
    Image(string title, int row, int columns, IntArrayPtr array);
    Image(const Image &i); // copy constructor
    ~Image(); // destructor

    Image& operator =(const Image &rightSide);
    const Image operator +(const Image &i2) throws (string) const;
    bool operator ==(const Image &i2) const;

    friend ostream& operator <<(ostream &outs, const Image &i);
    friend istream& operator >>(istream &ins, Image &i);

    void histogram(int n) const;
private:
    static int maxRows, maxColumns;
    // Member variables
    string title;
    int rows, columns;
};
