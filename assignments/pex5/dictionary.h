/*
 * File: dictionary.h
 * Author: Joshua Tate
 * Date: April 10, 2018
 * Updated: April 11, 2018
 *
 * Purpose:
 *    - This file contains the definition and implementation
 *      of a Dictionary.
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
using namespace std;

/* Dictionary Definition */
// Error Classes
class EmptyDictionary {};
class ExisitingKey {};
class ValueNotFound {};

template <typename Key, typename Value>
class Dictionary {
public:
    // Constructors/Destructors
    Dictionary();
    ~Dictionary();
    // Property accessors
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    // getKeys returns a pointer to a heap-allocated array of
    //  copies of all the keys in items. It is the responsibility
    //  of the user of getKeys to delete the array when they are
    //  done with the array.
    string* getKeys() const throw (EmptyDictionary);
    // Methods
    void insert(Key key, Value& value) throw (ExisitingKey);
    Value& remove(Key key) throw (ValueNotFound);
    Value& valueForKey(Key key) const throw (ValueNotFound);
    bool contains(Key key) const;
private:
    struct Item {
	Key key;
	Value* value;
    };
    int capacity, size;
    Item* items;
    void doubleCapacity();
    void deleteItems();
    // binarySearch performs a search for key in the items array
    // If the key is found, binarySearch returns true, and the
    //  index argument is set to its position in the items array.
    // If the key is not found, binarySearch returns false, and
    //  the index argument is set to the position which the key
    //  should go.
    bool binarySearch(Key key, int& index) const;
};

/* Dictionary Implementation */
// Constructor and Destructor
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
    if (isEmpty())
	throw EmptyDictionary();
    string* keys = new string[size];
    for (int i = 0; i < size; i++)
	keys[i] = items[i].key;
    return keys;
}
// Public Methods
template <typename Key, typename Value>
void Dictionary<Key,Value>::insert(Key key, Value& value) throw (ExisitingKey) {
    if (size >= capacity)
	doubleCapacity();
    int index;
    if (binarySearch(key, index))
	throw ExisitingKey();
    Item newItem;
    newItem.key = key;
    newItem.value = &value;
    for (int i = size; i > index; i--)
	items[i] = items[i-1];
    items[index] = newItem;
    size++;
}
template <typename Key, typename Value>
Value& Dictionary<Key,Value>::remove(Key key) throw (ValueNotFound) {
    int index;
    if (!binarySearch(key, index))
	throw ValueNotFound();
    Item item = items[index];
    Value& val = *(item.value);
    for (int i = index; i < size-1; i++)
	items[i] = items[i+1];
    size--;
    return val;
}
template <typename Key, typename Value>
Value& Dictionary<Key,Value>::valueForKey(Key key) const throw (ValueNotFound) {
    int index;
    if (!binarySearch(key, index))
	throw ValueNotFound();
    return *(items[index].value);
}
template <typename Key, typename Value>
bool Dictionary<Key, Value>::contains(Key key) const  {
    int index;
    return binarySearch(key, index);
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
template <typename Key, typename Value>
bool Dictionary<Key,Value>::binarySearch(Key key, int& index) const {
    int lower, mid, upper;
    lower = mid = 0;
    upper = size-1;
    while (lower <= upper) {
	mid = (upper + lower) / 2;
	if (items[mid].key == key) {
	    index = mid;
	    return true;
	} else if (items[mid].key.compare(key) < 0) {
	    lower = mid+1;
	} else {
	    upper = mid-1;
	}
    }
    index = lower;
    return false;
}
#endif
