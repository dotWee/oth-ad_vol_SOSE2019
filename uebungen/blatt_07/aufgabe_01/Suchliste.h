#ifndef SUCHLISTE__H
#define SUCHLISTE__H

#include <cstdio>
#include <iostream>

using namespace std;
class Element
{
public:
    int value;
    Element *next;
};

class Suchliste
{
private:
    Element *first;
    Element *value;

public:
    Suchliste();
    ~Suchliste();

    Element* getFirstElement();
    Element* addElement(int value);

    void removeElementIterativ(int value) {
        Element* temp;
        Element* prev = NULL;
        Element* next;

        for (temp = first;  temp != NULL; temp = next) {
            next = temp->next;

            if (temp->value != value) {
                prev = temp;
                continue;
            }

            if (prev != NULL) {
                prev->next = next;
            }
            else {
                first = next;
            }

            delete temp;
        }
    }
};

#endif // SUCHLISTE__H