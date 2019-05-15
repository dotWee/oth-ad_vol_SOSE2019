# Aufgabe 1 (Hashing)

Der Quellcode zur Aufgabe in C++ kann in [Main.cpp](Main.cpp) eingesehen und mit `make` ausgeführt werden.

## Beispielausgabe

```bash

clang++ Main.cpp -o Main.o
chmod +x Main.o
./Main.o

Geben sie Zahlen ein, für das der Wert der Hashfunktion h(s) berechnet werden soll (Negative Zahlen benden die Eingabeschleife)

s = 5
h(5) = 5
s = 28
h(28) = 1
s = 19
h(19) = 1
s = 15
h(15) = 6
s = 20
h(20) = 2
s = 33
h(33) = 6
s = 12
h(12) = 3
s = 17
h(17) = 8
s = 10
h(10) = 1
s = -1
h(-1) = -1

rm -f *.o
```