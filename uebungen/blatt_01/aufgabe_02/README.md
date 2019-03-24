# Aufgabe 2 (Abstrakter Datentyp)

Datei `Feld.h`:

```cpp
#ifndef AD_VOL_SOSE2019_FELD_H
#define AD_VOL_SOSE2019_FELD_H

class Feld {
public:
    void Init(int length);
    
    void FillRandom();
    
    int Min();

    int Max();

    int Avg();
    
    void Print();

private:
    int length;
    int* array;
};


#endif //AD_VOL_SOSE2019_FELD_H
```

Datei `Feld.cpp`:

```cpp
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <random>
#include <limits>
#include "Feld.h"

void Feld::Init(int length)
{
    this->length = length;

    array = (int *)malloc(sizeof(int) * length);

    // Fülle Array mit 0
    memset(array, 0, sizeof(int) * length);
};

void Feld::FillRandom()
{
    std::random_device rd;                          // obtain a random number from hardware
    std::mt19937 eng(rd());                         // seed the generator
    std::uniform_int_distribution<> distr(0, 1000); // define the range

    for (int n = 0; n < length; ++n)
    {
        array[n] = distr(eng);
    }
}

int Feld::Min()
{
    int lowest = INT_MAX;

    for (int position = 0; position < length; ++position)
    {
        if (array[position] < lowest)
        {
            lowest = array[position];
        }
    }

    return lowest;
}

int Feld::Max()
{
    int largest = INT_MIN;

    for (int position = 0; position < length; ++position)
    {
        if (array[position] > largest)
        {
            largest = array[position];
        }
    }

    return largest;
}

int Feld::Avg()
{
    int average = 0;

    for (int position = 0; position < length; ++position)
    {
        average += array[position];
    }

    average = average / length;

    return average;
}

void Feld::Print()
{
    for (int position = 0; position < length; ++position)
    {
        std::cout << "Position=" << position << " Value=" << array[position] << "\n";
    }
}
```

Datei `Main.cpp`:

```cpp
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
```

Datei `Makefile`:

```makefile
LENGTH = 10

all: feld clean

feld:
	g++ -c Main.cpp
	g++ -c Feld.cpp
	g++ Main.o Feld.o -o Cmain
	chmod +x Cmain
	./Cmain $(LENGTH)

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Cmain
```

Ausgabe:

```bash
$ make
g++ -c Main.cpp
g++ -c Feld.cpp
g++ Main.o Feld.o -o Cmain
chmod +x Cmain
./Cmain 10
Neues Feld mit der Länge 10 wird erzeugt
Position=0 Value=956
Position=1 Value=979
Position=2 Value=662
Position=3 Value=479
Position=4 Value=547
Position=5 Value=662
Position=6 Value=746
Position=7 Value=727
Position=8 Value=86
Position=9 Value=194
Größte Zahl aus dem Feld: 979
Kleinste Zahl aus dem Feld: 86
Arithmetisches Mittel aller Werte: 603
```