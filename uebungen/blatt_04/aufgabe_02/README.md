# Aufgabe 02 (Anpassung von Sortieralgorithmen)

## a)

Um mit dem Minimum statt mit dem Maximum zu arbeiten, muss das bool-Statement der While-Schleife von `y <= 0 && array[y] < key` in `y >= 0 && array[y] < key` abegändert werden.

```bash
$ make 2a
clang++ a_insertionsort.cpp -o Aufgabe2a
chmod +x Aufgabe2a
./Aufgabe2a
Insertionsort: Starte Sortierung.
Insertionsort: Array={23, 19, 17, 13, 12, 7, -3, -5, -32, -35, }
Insertionsort: Sortierung dauerte 0ms.
```

## b)

Um eine Absteigende Reihenfolge zu erzeugen, muss das bool-Statement der if-Abfrage von `array[y] > array[y + 1]` in `array[y] <= array[y + 1]` abegändert werden.

```bash
$ make 2b
clang++ b_bubblesort.cpp -o Aufgabe2b
chmod +x Aufgabe2b
./Aufgabe2b
Bubblesort: Starte Sortierung.
Bubblesort: Array={23, 19, 17, 13, 12, 7, -3, -5, -32, -35, }
Bubblesort: Sortierung dauerte 0ms.
```

## c)

Um anstelle des Minimums jeweils das Maximum an die richtige Stelle zu setzen, wird in der if-Abfrage der Inhalt mit ```>=``` und nicht mit ```<``` verglichen.

```bash
$ make 2c
clang++ c_selectionsort.cpp -o Aufgabe2c
chmod +x Aufgabe2c
./Aufgabe2c
Selectionsort: Starte Sortierung.
Selectionsort: Array={23, 19, 17, 13, 12, 7, -3, -5, -32, -35, }
Selectionsort: Sortierung dauerte 0ms.
```

## d)

Um ein zufälliges Element als Pivot-Element zu nutzen muss legdiglich irgendein Element aus dem Array als Start übergeben werden. Dies kann mit `&array[rand() % (length - 1)]` ausgwählt werden.

```bash
$ make 2d
clang++ d_quicksort.cpp -o Aufgabe2d
chmod +x Aufgabe2d
./Aufgabe2d
Quicksort: Starte Sortierung.
Quicksort: Zufälliges Pivot-Element - position=4 value=-3
Quicksort: Array={-32, -5, -3, 7, 13, 17, 23, 12, -35, 19, }
Quicksort: Sortierung dauerte 0ms.
```