# Aufgabe 01 (Quicksort)

## a)

Der Quellcode zur Implementierung in C++ kann in [verketteteliste.cpp](verketteteliste.cpp) eingesehen werden und mit _make_ ausgeführt werden.

    Notiz: Eine Implementierung des Quicksort Algorithmus zum Sortieren der Liste ist (noch) nicht vorhanden.

```bash
$ make verketteteliste
clang++ verketteteliste.cpp -o Verketteteliste
chmod +x Verketteteliste
./Verketteteliste
Zahl eingeben (0 für Ende)
6
Zahl eingeben (0 für Ende)
2
Zahl eingeben (0 für Ende)
9
Zahl eingeben (0 für Ende)
5
Zahl eingeben (0 für Ende)
3
Zahl eingeben (0 für Ende)
0
3
5
9
2
6
```

## b)

Der Quellcode zur Implementierung in C++ kann in [Lotto.cpp](Lotto.cpp) sowie [Ringliste.h](Ringliste.h) und [Ringliste.cpp](Ringliste.cpp) eingesehen werden. _Make_ wird zur Ausführung genutzt:

```bash
$ make lotto
clang++ -c Lotto.cpp
clang++ -c Ringliste.cpp
clang++ Lotto.o Ringliste.o -o Lotto
chmod +x Lotto
./Lotto
Starte nach dem 31. Element
1. Zahl:  position=31 wert=31
2. Zahl:  position=37 wert=37
3. Zahl:  position=43 wert=43
4. Zahl:  position=49 wert=49
5. Zahl:  position=55 wert=5
6. Zahl:  position=61 wert=11
```

Datei `Lotto.cpp`:

```cpp
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <random>

#include "Ringliste.h"

using namespace std;

#define SCHRITTE 6 // Zahlen zu ziehen
#define SCHRITTWEITE 6
#define LAENGE 50 // Ringliste Länge

int getRandom(int range) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, range); // define range

    return distr(eng);
} 

int main (int argc, char *argv[]) {

    // Neue Ringliste generieren
    Ringliste* ringliste = new Ringliste();

    // Ringliste füllen
    for (int i = 1; i <= LAENGE; i++) {
        ringliste->Append(i);
    }
    
    // Starte bei einer zufällig generierten Position
    int position = getRandom(LAENGE);
    Element* gezogenesElement = ringliste->GetTail();
    for (int p = 0; p < position; p++) gezogenesElement = gezogenesElement->next;
    cout << "Starte nach dem " << position << ". Element" << endl;

    for (int zahl = 1; zahl <= SCHRITTE; zahl++) {

        cout << zahl << ". Zahl: ";

        if (zahl > 1) {
            for (int s = 0; s < SCHRITTWEITE; s++) {
                gezogenesElement = gezogenesElement->next;
                position++;
            }
        }
    
        cout << " position=" << position << " wert=" << gezogenesElement->value << endl;
    }

    return 0;
}
```

Datei `Ringliste.h`:

```cpp
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
```

Datei `Ringliste.cpp`:

```cpp
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
```
