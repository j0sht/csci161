#include "person.h"
#include "student.h"
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    const int size = 3;
    MyQueue<Student> queue(size);
    try {
	queue.peek();
    } catch (EmptyQueue& e) {
	cout << "Queue is empty.\n";
    }
    for (int i = 0; i < size; i++) {
	Student& s = *(new Student);
	cin >> s;
	queue.enqueue(s);
    }
    Student& s = queue.dequeue();
    cout << "Released from queue: " << s << endl;
    delete &s;
    cout << "Next up in queue: " << queue.peek() << endl;
    Student& s2 = *(new Student("Josh", 120, 4.0));
    queue.enqueue(s2);
    Student& s3 = *(new Student("Jane", 120, 4.3));
    try {
	queue.enqueue(s3);
    } catch (FullQueue &e) {
	cout << "Queue is full.\n";
	delete &s3;
    }
    while (!queue.isEmpty()) {
	Student& student = queue.dequeue();
	cout << "Dequeued: " << student << endl;
    }
    return 0;
}
