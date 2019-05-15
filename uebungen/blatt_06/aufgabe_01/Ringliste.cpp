#include <iostream>
#include "Ringliste.h"

using namespace std;

Ringliste::Ringliste() {
    head = NULL;
    tail = NULL;
}

Ringliste::~Ringliste() {}

Element* Ringliste::GetHead() {
    return this->head;
}

Element* Ringliste::GetTail() {
    return this->tail;
}

void Ringliste::Append(int value) {
    Element *element = new Element();

    //cout << "elem addr" << &element << " val" << value << endl;

    element->value = value;
    element->next = head;

    if (tail == NULL) {
        head = element;
        tail = element;
    }

    else {
        tail->next = element;
        tail = element;
    }

    //cout << "tail addr" << &tail << " val" << tail->value << endl;    
    //cout << "head addr" << &head << " val" << head->value << endl;    
}