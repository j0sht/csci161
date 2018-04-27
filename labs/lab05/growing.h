#ifndef GROWING
#define GROWING
class Growing {
public:
    // Constructors
    Growing();
    Growing(int size);
    ~Growing();
    // Methods
    void insert(double n);
    void show();
    int getSize();
    // Operators
    bool operator ==(const Growing &other);
private:
    int size;
    int capacity;
    double *array;
};
#endif
