//
// Created by marco on 26/02/18.
//

#ifndef DATASTRUCTURES_SINGLYLINKEDLIST_H
#define DATASTRUCTURES_SINGLYLINKEDLIST_H

#include "Node.h"


#include <iostream>


using namespace std;


template <typename T>
class SinglyLinkedList{

private:
    Node<T>* head = nullptr;
    long int size = 0;

public:
    SinglyLinkedList();

    SinglyLinkedList(Node<T>* head);

    SinglyLinkedList(T value);

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
SinglyLinkedList<T>::SinglyLinkedList() = default;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(Node<T>* head){
    setHead(head);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T value){
    attachFirst(value);
}

template <typename T>
void SinglyLinkedList<T>::setHead(Node<T>* head){
    this->head = head;
}

template <typename T>
Node<T>* SinglyLinkedList<T>::getHead(){
    return this->head;
}

template <typename T>
void SinglyLinkedList<T>::setSize(long int size){
    this->size = size;
}

template <typename T>
long int SinglyLinkedList<T>::getSize(){
    return this->size;
}

template <typename T>
void SinglyLinkedList<T>::attachFirst(T value){

    Node<T>* newHead = new Node<T>(value,getHead());
    setHead(newHead);
    this->size++;

}

template <typename T>
void SinglyLinkedList<T>::attach(T value, long int position){
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
void SinglyLinkedList<T>::attachLast(T value){
    attach(value,getSize());
}

template <typename T>
void SinglyLinkedList<T>::deleteFirst(){
    Node<T>* current = getHead();
    if (current == nullptr) {
        throw invalid_argument("Index Out Of Range");
    }
    setHead(current->getNext());
    delete(current);
    this->size--;

}

template <typename T>
void SinglyLinkedList<T>::deleteLast(){
    deletePosition(getSize()-1);
}

template <typename T>
void SinglyLinkedList<T>::deletePosition(long int position){
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
void SinglyLinkedList<T>::edit(T value, long int position){
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
Node<T>* SinglyLinkedList<T>::get(long int position){

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
void SinglyLinkedList<T>::print(){
    Node<T>* temp = getHead();
    while (temp != nullptr){
        cout << temp->getValue() << "\t";

        temp = temp->getNext();
    }
    cout <<endl;

}

#endif