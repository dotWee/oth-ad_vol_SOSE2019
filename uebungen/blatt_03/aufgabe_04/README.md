# Aufgabe 4: Algorithmenimplementierung

Siehe Quellcode zur Implementierung in C++. Dieser kann mit `$ make` kompiliert und ausgeführt werden. Beispielausführung:

```bash
$ make
clang++ -c MaxSum1D.cpp
MaxSum1D.cpp:48:14: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (int &a : line)
                    ^
1 warning generated.
clang++ -c MaxSum2D.cpp
6clang++ Main.cpp MaxSum1D.o MaxSum2D.o -o Main.o

Main.cpp:20:28: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
    for (vector<int> &line : field)
                           ^
Main.cpp:22:25: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (int &entry : line)
                        ^
2 warnings generated.
chmod +x Main.o
./Main.o
Enter values
4
2
8
5
2
Max Sum is 27
rm -f *.o
```