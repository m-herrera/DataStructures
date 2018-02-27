//
// Created by marco on 26/02/18.
//

#ifndef DATASTRUCTURES_DOUBLENODE_H
#define DATASTRUCTURES_DOUBLENODE_H

#include <iostream>

using namespace std;

template <class T>
class DoubleNode {

private:
    T value;
    DoubleNode<T>* next = nullptr;
    DoubleNode<T>* previous = nullptr;
public:
    DoubleNode();

    DoubleNode(T value);

    DoubleNode(T value,DoubleNode<T>* next);

    DoubleNode(T value,DoubleNode<T>* next, DoubleNode<T>* previous);

    void setValue(T value);

    T getValue();

    void setNext(DoubleNode<T>* next);

    DoubleNode<T>* getNext();

    void setPrevious(DoubleNode<T>* previous);

    DoubleNode<T>* getPrevious();

};
template <class T>
DoubleNode<T>::DoubleNode() = default;


template <class T>
DoubleNode<T>::DoubleNode(T value){
setValue(value);}

template <class T>
DoubleNode<T>::DoubleNode(T value,DoubleNode<T>* next){
setValue(value);
setNext(next);
}

template <class T>
DoubleNode<T>::DoubleNode(T value,DoubleNode<T>* next, DoubleNode<T>* previous){
setValue(value);
setNext(next);
setPrevious(previous);
}

template <class T>
void DoubleNode<T>::setValue(T value) {
this -> value = value;
}

template <class T>
T DoubleNode<T>::getValue() {
    return this ->value;
}

template <class T>
void DoubleNode<T>::setNext(DoubleNode<T>* next){
    this->next = next;
}

template <class T>
DoubleNode<T>* DoubleNode<T>::getNext(){
    return this->next;
}

template <class T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* previous){
    this->previous = previous;
}

template <class T>
DoubleNode<T>* DoubleNode<T>::getPrevious(){
    return this->previous;
}


#endif //DATASTRUCTURES_DOUBLENODE_H
