/*
 * Write a complete program that asks the user for a seed and then outputs
 *  a list of ten random numbers based on that seed. The numbers should
 *  be floating-point numbers in the range 0.0 to 1.0 (inclusive)
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int seed;
    cout << "Enter seed: ";
    cin >> seed;
    srand(seed);
    for (int i = 0; i < 10; i++) {
	// Formula to get random number between 0 and 1
	double result = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
	cout << "Random number " << i << " = " << result << endl;
    }
    return 0;
}
