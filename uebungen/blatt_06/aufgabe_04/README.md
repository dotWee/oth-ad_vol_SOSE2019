# Aufgabe 04: Binäre, verkettete Bäume

Siehe Quellcode zur Implementierung in C++. Dieser kann mit `$ make` kompiliert und ausgeführt werden. Beispielausführung:

```bash
$ make
clang++ -c Knot.cpp
clang++ -c Tree.cpp
clang++ -c RebuildTree.cpp
clang++ Main.cpp Knot.o Tree.o RebuildTree.o -o Main.o
chmod +x Main.o
./Main.o
Restored Tree wit pre and in
(((n,1,n),2,((n,3,n),4,n)),5,((n,6,(n,7,n)),8,(n,9,n)))

Restored Tree wit pre and in
(((n,1,n),2,((n,3,n),4,n)),5,((n,6,(n,7,n)),8,(n,9,n)))

Restored Tree with only Pre
(((n,1,n),2,((n,3,n),4,n)),5,((n,6,(n,7,n)),8,(n,9,n)))
rm -f *.o
```