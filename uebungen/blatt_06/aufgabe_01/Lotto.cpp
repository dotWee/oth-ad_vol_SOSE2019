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