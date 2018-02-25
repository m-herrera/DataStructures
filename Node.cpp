//
// Created by marco on 24/02/18.
//

#include <iostream>

using namespace std;


template <typename T >
struct Node {

private:
    T value;
    Node<T>* next = nullptr;

public:
    Node() = default;
    Node(T value){
        setValue(value);
    }
    Node(T value, Node<T>* next){
        setValue(value);
        setNext(next);
    }

    void setValue(T value) {
        this -> value = value;
    }

    T getValue() {
        return this ->value;
    }
    void setNext(Node<T>* next) {
        this -> next = next;
    }
    Node<T>* getNext() {
        return this ->next;
    }

};