#ifndef QUEUE_H
#define QUEUE_H
class FullQueue {};
class EmptyQueue {};

template <typename T>
class MyQueue {
public:
    MyQueue(int cap);
    ~MyQueue();
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
    int getSize() { return size; }
    int getCap() { return cap; }
    void enqueue(T& obj) throw (FullQueue);
    T& dequeue() throw (EmptyQueue);
    T& peek() throw (EmptyQueue);
    void display();
private:
    T** data;
    int cap, head, tail, size;
};

template <typename T>
MyQueue<T>::MyQueue(int cap) {
    this->cap = cap;
    head = tail = size = 0;
    data = new T*[cap];
}

template <typename T>
MyQueue<T>::~MyQueue() {
    while (!isEmpty()) {
	T& obj = dequeue();
	delete &obj;
    }
    delete [] data;
}

template <typename T>
void MyQueue<T>::enqueue(T& obj) throw (FullQueue) {
    if (isFull())
	throw FullQueue();
    data[tail] = &obj;
    tail = (tail+1)%cap;
    size++;
}

template <typename T>
T& MyQueue<T>::dequeue() throw (EmptyQueue) {
    if (isEmpty())
	throw EmptyQueue();
    T& ref = *(data[head]);
    head = (head+1)%cap;
    size--;
    return ref;
}

template <typename T>
T& MyQueue<T>::peek() throw (EmptyQueue) {
    if (isEmpty())
	throw EmptyQueue();
    return *(data[head]);
}

template <typename T>
void MyQueue<T>::display() {
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
#endif
