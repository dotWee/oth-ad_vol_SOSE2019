#ifndef RINGLIST__H
#define RINGLIST__H

class Element
{
public:
    int value;
    Element *next;
};

class Ringliste
{
private:
    Element *head;
    Element *tail;

public:
    Ringliste();
    ~Ringliste();

    Element* GetHead();
    Element* GetTail();

    void Append(int value);
};

#endif