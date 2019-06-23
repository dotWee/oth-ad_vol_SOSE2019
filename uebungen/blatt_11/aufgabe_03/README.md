# Aufgabe 03: Maximale Cliquen

Siehe Quellcode zur Implementierung in C++. Dieser kann mit `$ make` kompiliert und ausgeführt werden. Beispielausführung:

```bash
$ make
clang++ -c Graph.cpp
Graph.cpp:55:15: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
        for (Knot* a : knots)
                     ^
Graph.cpp:102:14: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
        for(Knot* k : *knotList)
                    ^
Graph.cpp:104:15: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
                for(Knot* m : *knotList)
                            ^
3 warnings generated.
clang++ -c Knot.cpp
clang++ -c Matrix.cpp
Matrix.cpp:28:22: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
        for (vector<int> &a : internMatrix)
                            ^
Matrix.cpp:29:15: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
                for (int &b : a)
                            ^
Matrix.cpp:46:21: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
        for (vector<int> a : internMatrix)
                           ^
Matrix.cpp:48:14: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
                for (int b : a)
                           ^
Matrix.cpp:58:22: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
        for (vector<int> &a : internMatrix)
                            ^
Matrix.cpp:59:15: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
                for (int &b : a)
                            ^
6 warnings generated.
clang++ Main.cpp Graph.o Knot.o Matrix.o -o Main.o
chmod +x Main.o
./Main.o
Knot amount in max Clique 5
rm -f *.o
```
