# Aufgabe 1 (Euklidischer Algorithmus)

## Aufgabe 1a)

> Implementieren Sie den in der Vorlesung vorgestellten euklidischen Algorithmus zur Bestimmung des größten gemeinsamen Teilers (ggT) zweier natürlicher Zahlen in einer Programmiersprache Ihrer Wahl (C, C++, Java oder C#). Ergänzen Sie eine rekursive Implementierung des Algorithmus. Welchen Algorithmus halten Sie wann für sinnvoller?

Datei `blatt_01_aufgabe_01a.c`:

```c
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
```

```bash
$ make
Bestimmung des groeßten gemeinsamen Teilers in C
clang blatt_01_aufgabe_01a.c -o blatt_01_aufgabe_01a.o
chmod +x blatt_01_aufgabe_01a.o
./blatt_01_aufgabe_01a.o 150 40
Der größte gemeinsame Teiler der Zahlen 150 und 40 ist 10.
rm -f *.o
```

### _Welchen Algorithmus halten Sie wann für sinnvoller?_

Der schnellere Algorithmus benötigt weniger Zeit bei der Berechnung. Mit dem Make-Target `blatt_01_aufgabe_01a-speedtest` kann die Geschwindigkeit der Berechnung direkt abgelesen werden.

```bash
$ make blatt_01_aufgabe_01a-speedtest

clang blatt_01_aufgabe_01a-iterativ.c -o blatt_01_aufgabe_01a-iterativ.o
chmod +x blatt_01_aufgabe_01a-iterativ.o
./blatt_01_aufgabe_01a-iterativ.o
[ITERATIV] Der größte gemeinsame Teiler der Zahlen 145 und 70 ist 5. Dauer der Berechnung: 1.000000ms

clang blatt_01_aufgabe_01a-rekursiv.c -o blatt_01_aufgabe_01a-rekursiv.o
chmod +x blatt_01_aufgabe_01a-rekursiv.o
./blatt_01_aufgabe_01a-rekursiv.o
[REKURSIV] Der größte gemeinsame Teiler der Zahlen 145 und 70 ist 5. Dauer der Berechnung: 4.000000ms
rm -f *.o
```

In diesem Fall ist die rekursive Berechnung schneller und kann (sofern Geschwindigkeit relevant ist) bevorzugt werden.

## Aufgabe 1b)

> Implementieren Sie einen Algorithmus zur Bestimmung des kleinsten gemeinsamen Vielfachen (kgV) zweier natürlicher Zahlen ohne Funktionen zu nutzen, die bereits in der Vorlesung oder Übung implementiert wurden. Geben Sie für a,b ∈ {30,...,40} die Werte kgV(a,b), ggT(a,b) und a·b aus. Was fällt Ihnen auf?

Datei `blatt_01_aufgabe_01b.c`:

```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // Für a,b ∈ {30,...,40}
    for (int a = atoi(argv[1]); a <= atoi(argv[2]); a++)
    {
        for (int b = atoi(argv[1]); b <= atoi(argv[2]); b++)
        {

            // Berechne Ggt
            int ggt, kgv, tempA = a, tempB = b, ab;
            if (tempA == 0)
            {
                ggt = tempB;
            }
            else
            {
                while (tempB != 0)
                {
                    if (tempA > tempB)
                    {
                        tempA = tempA - tempB;
                    }
                    else
                    {
                        tempB = tempB - tempA;
                    }
                }
            }
            ggt = tempA;

            // Berechne a*b
            ab = a * b;

            // Berechne Kgv
            kgv = ab / ggt;

            // Ausgabe
            printf("a=%d b=%d ggt=%d a*b=%d kgv=%d\n", a, b, ggt, ab, kgv);
        }
    }
    return 0;
}
```

Ausgabe:

```bash
$ make blatt_01_aufgabe_01b
Bestimmung des groeßten gemeinsamen Teilers und kleinsten gemeinsamen Vielfachem in C
clang blatt_01_aufgabe_01b.c -o blatt_01_aufgabe_01b.o
chmod +x blatt_01_aufgabe_01b.o
./blatt_01_aufgabe_01b.o 30 40

a=30 b=30 ggt=30 a*b=900 kgv=30
a=30 b=31 ggt=1 a*b=930 kgv=930
a=30 b=32 ggt=2 a*b=960 kgv=480
a=30 b=33 ggt=3 a*b=990 kgv=330
a=30 b=34 ggt=2 a*b=1020 kgv=510
a=30 b=35 ggt=5 a*b=1050 kgv=210
a=30 b=36 ggt=6 a*b=1080 kgv=180
a=30 b=37 ggt=1 a*b=1110 kgv=1110
a=30 b=38 ggt=2 a*b=1140 kgv=570
a=30 b=39 ggt=3 a*b=1170 kgv=390
a=30 b=40 ggt=10 a*b=1200 kgv=120
a=31 b=30 ggt=1 a*b=930 kgv=930
a=31 b=31 ggt=31 a*b=961 kgv=31
a=31 b=32 ggt=1 a*b=992 kgv=992
a=31 b=33 ggt=1 a*b=1023 kgv=1023
a=31 b=34 ggt=1 a*b=1054 kgv=1054
a=31 b=35 ggt=1 a*b=1085 kgv=1085
a=31 b=36 ggt=1 a*b=1116 kgv=1116
a=31 b=37 ggt=1 a*b=1147 kgv=1147
a=31 b=38 ggt=1 a*b=1178 kgv=1178
a=31 b=39 ggt=1 a*b=1209 kgv=1209
a=31 b=40 ggt=1 a*b=1240 kgv=1240
a=32 b=30 ggt=2 a*b=960 kgv=480
a=32 b=31 ggt=1 a*b=992 kgv=992
a=32 b=32 ggt=32 a*b=1024 kgv=32
a=32 b=33 ggt=1 a*b=1056 kgv=1056
a=32 b=34 ggt=2 a*b=1088 kgv=544
a=32 b=35 ggt=1 a*b=1120 kgv=1120
a=32 b=36 ggt=4 a*b=1152 kgv=288
a=32 b=37 ggt=1 a*b=1184 kgv=1184
a=32 b=38 ggt=2 a*b=1216 kgv=608
a=32 b=39 ggt=1 a*b=1248 kgv=1248
a=32 b=40 ggt=8 a*b=1280 kgv=160
a=33 b=30 ggt=3 a*b=990 kgv=330
a=33 b=31 ggt=1 a*b=1023 kgv=1023
a=33 b=32 ggt=1 a*b=1056 kgv=1056
a=33 b=33 ggt=33 a*b=1089 kgv=33
a=33 b=34 ggt=1 a*b=1122 kgv=1122
a=33 b=35 ggt=1 a*b=1155 kgv=1155
a=33 b=36 ggt=3 a*b=1188 kgv=396
a=33 b=37 ggt=1 a*b=1221 kgv=1221
a=33 b=38 ggt=1 a*b=1254 kgv=1254
a=33 b=39 ggt=3 a*b=1287 kgv=429
a=33 b=40 ggt=1 a*b=1320 kgv=1320
a=34 b=30 ggt=2 a*b=1020 kgv=510
a=34 b=31 ggt=1 a*b=1054 kgv=1054
a=34 b=32 ggt=2 a*b=1088 kgv=544
a=34 b=33 ggt=1 a*b=1122 kgv=1122
a=34 b=34 ggt=34 a*b=1156 kgv=34
a=34 b=35 ggt=1 a*b=1190 kgv=1190
a=34 b=36 ggt=2 a*b=1224 kgv=612
a=34 b=37 ggt=1 a*b=1258 kgv=1258
a=34 b=38 ggt=2 a*b=1292 kgv=646
a=34 b=39 ggt=1 a*b=1326 kgv=1326
a=34 b=40 ggt=2 a*b=1360 kgv=680
a=35 b=30 ggt=5 a*b=1050 kgv=210
a=35 b=31 ggt=1 a*b=1085 kgv=1085
a=35 b=32 ggt=1 a*b=1120 kgv=1120
a=35 b=33 ggt=1 a*b=1155 kgv=1155
a=35 b=34 ggt=1 a*b=1190 kgv=1190
a=35 b=35 ggt=35 a*b=1225 kgv=35
a=35 b=36 ggt=1 a*b=1260 kgv=1260
a=35 b=37 ggt=1 a*b=1295 kgv=1295
a=35 b=38 ggt=1 a*b=1330 kgv=1330
a=35 b=39 ggt=1 a*b=1365 kgv=1365
a=35 b=40 ggt=5 a*b=1400 kgv=280
a=36 b=30 ggt=6 a*b=1080 kgv=180
a=36 b=31 ggt=1 a*b=1116 kgv=1116
a=36 b=32 ggt=4 a*b=1152 kgv=288
a=36 b=33 ggt=3 a*b=1188 kgv=396
a=36 b=34 ggt=2 a*b=1224 kgv=612
a=36 b=35 ggt=1 a*b=1260 kgv=1260
a=36 b=36 ggt=36 a*b=1296 kgv=36
a=36 b=37 ggt=1 a*b=1332 kgv=1332
a=36 b=38 ggt=2 a*b=1368 kgv=684
a=36 b=39 ggt=3 a*b=1404 kgv=468
a=36 b=40 ggt=4 a*b=1440 kgv=360
a=37 b=30 ggt=1 a*b=1110 kgv=1110
a=37 b=31 ggt=1 a*b=1147 kgv=1147
a=37 b=32 ggt=1 a*b=1184 kgv=1184
a=37 b=33 ggt=1 a*b=1221 kgv=1221
a=37 b=34 ggt=1 a*b=1258 kgv=1258
a=37 b=35 ggt=1 a*b=1295 kgv=1295
a=37 b=36 ggt=1 a*b=1332 kgv=1332
a=37 b=37 ggt=37 a*b=1369 kgv=37
a=37 b=38 ggt=1 a*b=1406 kgv=1406
a=37 b=39 ggt=1 a*b=1443 kgv=1443
a=37 b=40 ggt=1 a*b=1480 kgv=1480
a=38 b=30 ggt=2 a*b=1140 kgv=570
a=38 b=31 ggt=1 a*b=1178 kgv=1178
a=38 b=32 ggt=2 a*b=1216 kgv=608
a=38 b=33 ggt=1 a*b=1254 kgv=1254
a=38 b=34 ggt=2 a*b=1292 kgv=646
a=38 b=35 ggt=1 a*b=1330 kgv=1330
a=38 b=36 ggt=2 a*b=1368 kgv=684
a=38 b=37 ggt=1 a*b=1406 kgv=1406
a=38 b=38 ggt=38 a*b=1444 kgv=38
a=38 b=39 ggt=1 a*b=1482 kgv=1482
a=38 b=40 ggt=2 a*b=1520 kgv=760
a=39 b=30 ggt=3 a*b=1170 kgv=390
a=39 b=31 ggt=1 a*b=1209 kgv=1209
a=39 b=32 ggt=1 a*b=1248 kgv=1248
a=39 b=33 ggt=3 a*b=1287 kgv=429
a=39 b=34 ggt=1 a*b=1326 kgv=1326
a=39 b=35 ggt=1 a*b=1365 kgv=1365
a=39 b=36 ggt=3 a*b=1404 kgv=468
a=39 b=37 ggt=1 a*b=1443 kgv=1443
a=39 b=38 ggt=1 a*b=1482 kgv=1482
a=39 b=39 ggt=39 a*b=1521 kgv=39
a=39 b=40 ggt=1 a*b=1560 kgv=1560
a=40 b=30 ggt=10 a*b=1200 kgv=120
a=40 b=31 ggt=1 a*b=1240 kgv=1240
a=40 b=32 ggt=8 a*b=1280 kgv=160
a=40 b=33 ggt=1 a*b=1320 kgv=1320
a=40 b=34 ggt=2 a*b=1360 kgv=680
a=40 b=35 ggt=5 a*b=1400 kgv=280
a=40 b=36 ggt=4 a*b=1440 kgv=360
a=40 b=37 ggt=1 a*b=1480 kgv=1480
a=40 b=38 ggt=2 a*b=1520 kgv=760
a=40 b=39 ggt=1 a*b=1560 kgv=1560
a=40 b=40 ggt=40 a*b=1600 kgv=40
```