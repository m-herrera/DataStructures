#include <iostream>
#include "SinglyLinkedList.cpp"

using namespace std;


int main() {


    SinglyLinkedList<int>* list = new SinglyLinkedList<int>();

    list->attachFirst(4);

    list->attachFirst(3);

    list->print();
    return 0;
}