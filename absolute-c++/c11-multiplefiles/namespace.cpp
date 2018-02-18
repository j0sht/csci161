#include <iostream>
using namespace std;

namespace Space1 {
    void greeting();
}

namespace Space2 {
    void greeting();
}

void bigGreeting();

int main() {
    {
	// Names in this block use definitions in namespaces
	//  Space2, std, and the global namespace
	using namespace Space2;
	greeting();
    }
    {
	// Names in this block use definitions in namespaces
	//  Space1, std, and the global namespace
	using namespace Space1;
	greeting();
    }
    // Names out here only use definitions in the namespace
    //  std and the global namespace
    bigGreeting();
    return 0;
}

namespace Space1 {
    void greeting() {
	cout << "Hello from namespace Space1.\n";
    }
}

namespace Space2 {
    void greeting() {
	cout << "Greetings from namespace Space2.\n";
    }
}

void bigGreeting() {
    cout << "A BIG GLOBAL HELLO!\n";
}
