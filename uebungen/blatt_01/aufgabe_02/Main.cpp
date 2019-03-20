
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Feld.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Lese Länge aus Programmparametern
    int length = atoi(argv[1]);

    cout << "Neues Feld mit der Länge " << length << " wird erzeugt" << endl;
    Feld feld;
    feld.Init(length);
    feld.FillRandom();
    feld.Print();

    cout << "Größte Zahl aus dem Feld: " << feld.Max() << endl;
    cout << "Kleinste Zahl aus dem Feld: " << feld.Min() << endl;
    cout << "Arithmetisches Mittel aller Werte: " << feld.Avg() << endl;

    return 0;
}