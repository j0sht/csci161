/*
 * File: dictionary.h
 * Author: Joshua Tate
 * Date: April 10, 2018
 * Updated: April 10, 2018
 *
 * Purpose:
 *    - This file contains the definition and implementation
 *      of a Dictionary.
 */
#include <iostream>
using namespace std;

/* Dictionary Definition */
// Error Classes
class EmptyDictionary {};

template <typename Key, typename Value>
class Dictionary {
public:
    // Constructors/Destructors
    Dictionary();
    ~Dictionary();
    // Getters
    int getSize() const { return size; }
    string* getKeys() const throw (EmptyDictionary);
    // Methods
    void insert(Key key, Value& value);
private:
    struct Item {
	Key key;
	Value* value;
    };
    int capacity, size;
    Item* items;
    void doubleCapacity();
    void deleteItems();
};

/* Dictionary Implementation */
template <typename Key, typename Value>
Dictionary<Key,Value>::Dictionary() {
    capacity = 2;
    size = 0;
    items = new Item[capacity];
}
template <typename Key, typename Value>
Dictionary<Key,Value>::~Dictionary() {
    deleteItems();
}
// Getters
template <typename Key, typename Value>
string* Dictionary<Key,Value>::getKeys() const throw (EmptyDictionary) {
    string* keys = new string[size];
    for (int i = 0; i < size; i++)
	keys[i] = items[i].key;
    return keys;
}
// Public Methods
template <typename Key, typename Value>
void Dictionary<Key,Value>::insert(Key key, Value& value) {
    Item newItem;
    newItem.key = key;
    newItem.value = &value;
    if (size == capacity)
	doubleCapacity();
    items[size] = newItem;
    size++;
}
// Private Methods
template <typename Key, typename Value>
void Dictionary<Key,Value>::doubleCapacity() {
    capacity *= 2;
    Item* tmpItems = new Item[capacity];
    for (int i = 0; i < size; i++)
	tmpItems[i] = items[i];
    delete [] items;
    items = tmpItems;
}
template <typename Key, typename Value>
void Dictionary<Key,Value>::deleteItems() {
    for (int i = 0; i < size; i++)
	delete items[i].value;
    delete [] items;
}
