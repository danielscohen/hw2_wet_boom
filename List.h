//
// Created by dcohe on 11/06/2020.
//

#ifndef MUSIC_MANAGER_2_LIST_H
#define MUSIC_MANAGER_2_LIST_H

#include <memory>
#include "library2.h"


template <class T>
class List {


    struct Node{
        int key;
        T value;

        Node(int key, T value);
        Node();

        std::shared_ptr<Node> next;

    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> iterator;

public:

    StatusType add(int key, T value);
    StatusType remove(int key);
    T get(int key);
    T getItValue();
    int getItKey();
    bool itAtEnd();
    void itNext();
    void resetIterator();

    List();
};



template<class T>
StatusType List<T>::add(int key, T value) {
    std::shared_ptr<Node> temp;
    try {
        temp = std::make_shared<Node>(Node(key, value));
    }catch(...) {return ALLOCATION_ERROR;}

   temp->next = head->next;
   head->next = temp;
   return SUCCESS;
}

template<class T>
StatusType List<T>::remove(int key) {
    std::shared_ptr<Node> temp = head;
    while(temp->next != nullptr){
        if(temp->next->key == key){
            temp->next = temp->next->next;
            return SUCCESS;
        }
        temp = temp->next;
    }
    return FAILURE;
}

template<class T>
T List<T>::get(int key) {
    std::shared_ptr<Node> temp = head->next;
    while(temp != nullptr){
        if(temp->key == key) return temp->value;
        temp = temp->next;
    }
    return nullptr;
}

template<class T>
List<T>::Node::Node(int key, T value):key(key), value(value), next(nullptr) {}

template<class T>
List<T>::Node::Node():key(-1),value(nullptr), next(nullptr) {}

template<class T>
List<T>::List() {
    head = std::make_shared<Node>(Node());
}

template<class T>
T List<T>::getItValue() {
    return iterator->value;
}

template<class T>
int List<T>::getItKey() {
    return iterator->key;
}

template<class T>
void List<T>::resetIterator() {
    iterator = head->next;
}

template<class T>
bool List<T>::itAtEnd() {
    return iterator == nullptr;
}

template<class T>
void List<T>::itNext() {
    iterator = iterator->next;
}


#endif //MUSIC_MANAGER_2_LIST_H
