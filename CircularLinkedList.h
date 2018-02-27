//
// Created by marco on 26/02/18.
//
#ifndef DATASTRUCTURES_CIRCULARLINKEDLIST_H
#define DATASTRUCTURES_CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;


template <typename T>
class CircularLinkedList{

private:
    Node<T>* head = nullptr;
    long int size = 0;

public:
    CircularLinkedList();

    CircularLinkedList(Node<T>* head);

    CircularLinkedList(T value);

    void setHead(Node<T>* head);

    Node<T>* getHead();

    void setSize(long int size);

    long int getSize();

    void attachFirst(T value);

    void attach(T value, long int position);

    void attachLast(T value);

    void deleteFirst();

    void deleteLast();

    void deletePosition(long int position);

    void edit(T value, long int position);

    Node<T>* get(long int position);


    void print();

};
template <typename T>
CircularLinkedList<T>::CircularLinkedList() = default;

template <typename T>
CircularLinkedList<T>::CircularLinkedList(Node<T>* head){
    setHead(head);
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList(T value){
    attachFirst(value);
}
template <typename T>
void CircularLinkedList<T>::setHead(Node<T>* head){
    this->head = head;
}

template <typename T>
Node<T>* CircularLinkedList<T>::getHead(){
    return this->head;
}

template <typename T>
void CircularLinkedList<T>::setSize(long int size){
    this->size = size;
}

template <typename T>
long int CircularLinkedList<T>::getSize(){
    return this->size;
}

template <typename T>
void CircularLinkedList<T>::attachFirst(T value){
    Node<T>* newHead = nullptr;
    Node<T>* head = getHead();

    if (getSize() == 0){
        newHead = new Node<T>(value,newHead);

    }
    else{
        newHead = new Node<T>(value,head);

        Node<T>* current = head;

        do{
            current = current->getNext();
        }while(current->getNext() != head);

        current->setNext(newHead);
    }
    setHead(newHead);
    this->size++;

}
template <typename T>
void CircularLinkedList<T>::attach(T value, long int position){
    if (position == 0){
        attachFirst(value);
        return;
    }
    else if (position > getSize() || position < 0){
        throw invalid_argument("Index Out Of Range");
    }
    else{
        int count = 0;
        Node<T>* current = getHead();
        while(count < position-1){
            current = current->getNext();
            count++;
        }
        Node<T>* newNode = new Node<T>(value,current->getNext());
        current->setNext(newNode);
        this->size++;
    }

}
template <typename T>
void CircularLinkedList<T>::attachLast(T value){
    attach(value,getSize());
}

template <typename T>
void CircularLinkedList<T>::deleteFirst(){
    Node<T>* current = getHead();
    if (current == nullptr) {
        throw invalid_argument("Index Out Of Range");
    }
    setHead(current->getNext());
    delete(current);
    this->size--;

}

template <typename T>
void CircularLinkedList<T>::deleteLast(){
    deletePosition(getSize()-1);
}

template <typename T>
void CircularLinkedList<T>::deletePosition(long int position){
    Node<T>* current = getHead();
    Node<T>* previous = nullptr;

    if (position == 0){
        deleteFirst();
        return;
    }
    else if (current == nullptr || position >= getSize() || position < 0) {
        throw invalid_argument("Index Out Of Range");
    }
    else {
        int count = 0;
        while (count < position) {
            previous = current;
            current = current->getNext();
            count++;
        }

        previous->setNext(current->getNext());
        delete (current);
        this->size--;
    }
}

template <typename T>
void CircularLinkedList<T>::edit(T value, long int position){
    if (position < 0 || position >= getSize()){
        throw invalid_argument("Index Out Of Range");
    }
    else{
        Node<T>* current = getHead();
        int count = 0;
        while (count < position) {
            current = current->getNext();
            count++;
        }
        current->setValue(value);
    }

}

template <typename T>
Node<T>* CircularLinkedList<T>::get(long int position){

    if (position < 0 || position >= getSize()){
        throw invalid_argument("Index Out Of Range");
    }
    else{
        Node<T>* current = getHead();
        int count = 0;
        while (count < position) {
            current = current->getNext();
            count++;
        }
        return current;
    }
}

template <typename T>
void CircularLinkedList<T>::print(){
    Node<T>* head = getHead();
    Node<T>* current = head;

    do{
        cout << current->getValue() << "\t";
        current = current->getNext();

    }while(current->getNext() != head);

    cout <<endl;

}

#endif