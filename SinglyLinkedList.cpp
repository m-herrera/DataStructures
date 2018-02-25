//
// Created by marco on 24/02/18.
//

#include <iostream>
#include "Node.cpp"

using namespace std;


template <typename T>
class SinglyLinkedList{

private:
    Node<T>* head = nullptr;
    //Node<T>* tail = nullptr;

public:
    SinglyLinkedList() = default;

    SinglyLinkedList(Node<T>* head){
        setHead(head);
    }

    SinglyLinkedList(T value){
        Node<T>* head = new Node<T>(value);
        setHead(head);
    }
    void setHead(Node<T>* head){
        this->head = head;
    }
    Node<T>* getHead(){
        return this->head;
    }


    void attachFirst(T value){

        if (getHead() == nullptr){
            setHead(new Node<T>(value));
            return;
        }
        Node<T>* newHead = new Node<T>(value,getHead());
        setHead(newHead);

    }

    void attach(T value, int position){

        int count = 0;
        Node<T>* current = getHead();
        while(count < position && current != nullptr){

        }
        if (count == 0){


        }
    }

    void deleteFirst(){}

    void deleteLast(){}

    void deletePosition(){}

    void edit(){}

    void get(){}


    void print(){
        Node<T>* temp = getHead();
        while (temp != nullptr){
            cout << temp->getValue()<<endl;
            cout << temp<< endl;
            cout << endl;

            temp = temp->getNext();
        }

    }


};