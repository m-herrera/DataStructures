//
// Created by marco on 26/02/18.
//

#ifndef DATASTRUCTURES_DOUBLYLINKEDLIST_H
#define DATASTRUCTURES_DOUBLYLINKEDLIST_H


#include <iostream>
#include "DoubleNode.h"

using namespace std;


template <typename T>
class DoublyLinkedList {

private:
    DoubleNode<T>* head = nullptr;
    long int size = 0;

public:
    DoublyLinkedList();

    DoublyLinkedList(DoubleNode<T>* head);

    DoublyLinkedList(T value);

    void setHead(DoubleNode<T>* head);

    DoubleNode<T>* getHead();

    void setSize(long int size);

    long int getSize();

    void attachFirst(T value);

    void attach(T value, long int position);

    void attachLast(T value);

    void deleteFirst();

    void deleteLast();

    void deletePosition(long int position);

    void edit(T value, long int position);

    DoubleNode<T>* get(long int position);


    void print();


};

template <typename T>
DoublyLinkedList::DoublyLinkedList() = default;

template <typename T>
DoublyLinkedList::DoublyLinkedList(DoubleNode<T>* head){
    setHead(head);
}

template <typename T>
DoublyLinkedList::DoublyLinkedList(T value){
    attachFirst(value);
}

template <typename T>
void DoublyLinkedList::setHead(DoubleNode<T>* head){
    this->head = head;
}

template <typename T>
DoubleNode<T>* DoublyLinkedList::getHead(){
    return this->head;
}

template <typename T>
void DoublyLinkedList::setSize(long int size){
    this->size = size;
}

template <typename T>
long int DoublyLinkedList::getSize(){
    return this->size;
}

template <typename T>
void DoublyLinkedList::attachFirst(T value){

    DoubleNode<T>* oldHead = getHead();
    DoubleNode<T>* newHead = new DoubleNode<T>(value,oldHead);

    if (oldHead != nullptr){
        oldHead->setPrevious(newHead);
    }


    setHead(newHead);
    this->size++;

}

template <typename T>
void DoublyLinkedList::attach(T value, long int position){
    if (position == 0){
        attachFirst(value);
        return;
    }
    else if (position > getSize() || position < 0){
        throw invalid_argument("Index Out Of Range");
    }
    else{
        int count = 0;
        DoubleNode<T>* current = getHead();

        while(count < position-1){
            current = current->getNext();
            count++;
        }

        DoubleNode<T>* newNode = new DoubleNode<T>(value,current->getNext(),current);

        if (current->getNext() != nullptr) {
            (current->getNext())->setPrevious(newNode);
        }
        current->setNext(newNode);

        this->size++;
    }

}

template <typename T>
void DoublyLinkedList::attachLast(T value){
    attach(value,getSize());
}

template <typename T>
void DoublyLinkedList::deleteFirst(){
    DoubleNode<T>* current = getHead();
    if (current == nullptr) {
        throw invalid_argument("Index Out Of Range");
    }
    setHead(current->getNext());
    if (current->getNext() != nullptr){
        (current->getNext())->setPrevious(nullptr);
    }
    delete(current);
    this->size--;

}

template <typename T>
void DoublyLinkedList::deleteLast(){
    deletePosition(getSize()-1);
}

template <typename T>
void DoublyLinkedList::deletePosition(long int position){
    DoubleNode<T>* current = getHead();

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
            current = current->getNext();
            count++;
        }
        (current->getPrevious())->setNext(current->getNext());
        if (current->getNext() != nullptr){
            (current->getNext())->setPrevious(current->getPrevious());
        }
        delete (current);
        this->size--;
    }
}

template <typename T>
void DoublyLinkedList::edit(T value, long int position){
    if (position < 0 || position >= getSize()){
        throw invalid_argument("Index Out Of Range");
    }
    else{
        DoubleNode<T>* current = getHead();
        int count = 0;
        while (count < position) {
            current = current->getNext();
            count++;
        }
        current->setValue(value);
    }

}

template <typename T>
DoubleNode<T>* DoublyLinkedList::get(long int position){

    if (position < 0 || position >= getSize()){
        throw invalid_argument("Index Out Of Range");
    }
    else{
        DoubleNode<T>* current = getHead();
        int count = 0;
        while (count < position) {
            current = current->getNext();
            count++;
        }
        return current;
    }
}

template <typename T>
void DoublyLinkedList::print(){
    DoubleNode<T>* temp = getHead();
    while (temp != nullptr){
        cout << temp->getValue() << "\t";

        temp = temp->getNext();
    }
    cout <<endl;

}


#endif //DATASTRUCTURES_DOUBLYLINKEDLIST_H
