//
// Created by marco on 24/02/18.
//
#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H

#include <iostream>


using namespace std;


template <typename T >
class Node {

private:
    T value;
    Node<T>* next = nullptr;

public:
    Node();
    Node(T);
    Node(T, Node<T>*);

    void setValue(T);

    T getValue();

    void setNext(Node<T>*);
    Node<T>* getNext();

};

template <typename T>
Node<T>::Node() = default;

template <typename T>
Node<T>::Node(T value){
    setValue(value);
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this -> next = next;
}

template <typename T>
Node<T>::Node(T value, Node<T>* next){
    setValue(value);
    setNext(next);
}

template <typename T>
void Node<T>::setValue(T value) {
    this -> value = value;
}

template <typename T>
T Node<T>::getValue() {
    return this ->value;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return this ->next;
}

#endif