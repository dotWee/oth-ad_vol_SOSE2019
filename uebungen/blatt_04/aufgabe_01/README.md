# Aufgabe 01 (Implementierung von Sortieralgorithmen)

## a) und b)

Eine Implementierung in C++ der Sortieralgorithmen Insertionsort, Bubblesort und Selectionsort kann in der Quelldatei [sortieralgorithmen.cpp](sortieralgorithmen.cpp) betrachtet werden.

Eine Ausführung kann mithilfe des Makefiles durchgeführt werden:
```bash
$ make
clang++ sortieralgorithmen.cpp -o Sortieralgorithmen
chmod +x Sortieralgorithmen
./Sortieralgorithmen
Insertionsort: Starte Sortierung.
Insertionsort: Array={-35, -32, -5, -3, 7, 12, 13, 17, 19, 23, }
Insertionsort: Sortierung dauerte 0ms.
Bubblesort: Starte Sortierung.
Bubblesort: Array={-35, -32, -5, -3, 7, 12, 13, 17, 19, 23, }
Bubblesort: Sortierung dauerte 0ms.
Selectionsort: Starte Sortierung.
Selectionsort: Array={-35, -32, -5, -3, 7, 12, 13, 17, 19, 23, }
Selectionsort: Sortierung dauerte 0ms.
rm -f *.o
rm -f *.out
rm -f Sortieralgorithmen
```