#ifndef QUEUE_H
#define QUEUE_H
class FullQueue {};
class EmptyQueue {};

template <typename T>
class MyQueue {
public:
    MyQueue(int cap) {
	this->cap = cap;
	head = tail = size = 0;
	data = new T*[cap];
    }
    ~MyQueue() {
	while (!isEmpty()) {
	    T& obj = dequeue();
	    delete &obj;
	}
	delete [] data;
    }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
    int getSize() { return size; }
    int getCap() { return cap; }
    void enqueue(T& obj) throw (FullQueue) {
	if (size == cap)
	    throw FullQueue();
	data[tail] = &obj;
	tail = (tail+1)%cap;
	size++;
    }
    T& dequeue() throw (EmptyQueue) {
	if (isEmpty())
	    throw EmptyQueue();
	T& ref = *(data[head]);
	head = (head+1)%cap;
	size--;
	return ref;
    }
    T& peek() throw (EmptyQueue) {
	if (isEmpty())
	    throw EmptyQueue();
	return *(data[head]);
    }
    void display() {
	int i = 0;
	int sizeCopy = size;
	while (i < sizeCopy) {
	    T& obj = dequeue();
	    cout << "----------------------------------------------------\n"
		 << i+1 << ") " << obj << endl
		 << "----------------------------------------------------\n";
	    enqueue(obj);
	    i++;
	}
    }
private:
    T** data;
    int cap, head, tail, size;
};

// template <typename T>
// ostream& operator <<(ostream& outs, const MyQueue<T> q) {

// }
#endif
