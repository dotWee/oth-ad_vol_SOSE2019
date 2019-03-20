#include <stdlib.h>
#include <stdio.h>

int GetGgt(int a, int b);
int GetGgtRec(int a, int b);

int main(int argc, char **argv)
{
    // Lese Variablen a und b aus Programm-Argumenten
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // Berechne größten gemeinsamen Teiler mit iterativer Methode
    int ggt = GetGgt(a, b);

    // Alternative rekursive Implementierung
    //int ggt = GetGgtRec(a, b); 

    // Ausgabe
    printf("Der größte gemeinsame Teiler der Zahlen %d und %d ist %d.\n", a, b, ggt);
    return 0;
}

int GetGgt(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        while (b != 0)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
    }

    return a;
}

int GetGgtRec(int a, int b)
{

    if (b == 0)
    {
        return a;
    }

    else if (a == 0)
    {
        return b;
    }
    else if (a > b)
    {
        return GetGgtRec(a - b, b);
    }
    else
    {
        return GetGgtRec(a, b - a);
    }
}