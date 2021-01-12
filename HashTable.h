//
// Created by dcohe on 11/06/2020.
//

#ifndef MUSIC_MANAGER_2_HASHTABLE_H
#define MUSIC_MANAGER_2_HASHTABLE_H

#include <iostream>
#include "List.h"



template <class T>
class HashTable {
    List<T> *array;
    int arraySize;
    int numEntries;
    int iterator;

    int hash(int key);
    void adjustArrSize(int size);

public:
    virtual ~HashTable();

    StatusType insert(int key, T value);
    StatusType remove(int key);
    T get(int key);
    void printAll(){
        std::cout << std::endl;
        for(int i = 0; i < arraySize; i++){
            std::cout << i << ":" << " " ;
            for (array[i].resetIterator(); !array[i].itAtEnd(); array[i].itNext()) {
                std::cout << array[i].getItKey() << " ";
            }
            std::cout << std::endl;
        }
    }

    HashTable();
    T itGet();
    void itFirst();
    void itNext();
    bool itAtEnd();
    int getNumEntries();
};

template<class T>
int HashTable<T>::hash(int key) {
    return key % arraySize;
}

template<class T>
void HashTable<T>::adjustArrSize(int size) {
    List<T> *newArr = new List<T>[size];
    int oldSize = arraySize;
    arraySize = size;

    for(int i = 0; i < oldSize; i++){
        for (array[i].resetIterator(); !array[i].itAtEnd(); array[i].itNext()) {
            newArr[hash(array[i].getItKey())].add(array[i].getItKey(), array[i].getItValue());
        }
    }
    delete[] array;
    array = newArr;

}

template<class T>
StatusType HashTable<T>::insert(int key, T value) {
    try {
        array[hash(key)].add(key, value);
        numEntries++;
        if(arraySize == numEntries) adjustArrSize(arraySize * 2);
    }catch (...){return ALLOCATION_ERROR;}
    return SUCCESS;
}

template<class T>
StatusType HashTable<T>::remove(int key) {
    if(array[hash(key)].remove(key) == FAILURE) return FAILURE;
    numEntries--;
    try {
        if(numEntries <= arraySize / 4 && numEntries > 3) adjustArrSize(arraySize / 2);
    } catch (...){ return ALLOCATION_ERROR;}
    return SUCCESS;
}

template<class T>
T HashTable<T>::get(int key) {
    return array[hash(key)].get(key);
}

template<class T>
HashTable<T>::HashTable():array(new List<T>[10]), arraySize(10), numEntries(0) {}

template<class T>
HashTable<T>::~HashTable() {
    delete[] array;
}

template<class T>
T HashTable<T>::itGet() {
    return array[iterator].getItValue();
}

template<class T>
void HashTable<T>::itFirst() {
    iterator = 0;
    array[iterator].resetIterator();
    itNext();
}

template<class T>
void HashTable<T>::itNext() {
    if(array[iterator].itAtEnd() && iterator == arraySize - 1){
        iterator = -1;
        return;
    }
    if(array[iterator].itAtEnd()){
        iterator++;
        array[iterator].resetIterator();
        while(array[iterator].itAtEnd()){
            iterator++;
            if(iterator == arraySize){
                iterator = -1;
                return;
            }
            array[iterator].resetIterator();
        }
        return;
    }
    array[iterator].itNext();
}

template<class T>
bool HashTable<T>::itAtEnd() {
    return iterator == -1;
}

template<class T>
int HashTable<T>::getNumEntries() {
    return numEntries;
}


#endif //MUSIC_MANAGER_2_HASHTABLE_H
