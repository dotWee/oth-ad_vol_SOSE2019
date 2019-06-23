# Aufgabe 01: Skip-Listen

Siehe Quellcode zur Implementierung in C++. Dieser kann mit `$ make` kompiliert und ausgeführt werden. Beispielausführung:

```bash
$ make
clang++ -c Element.cpp
clang++ -c SkipList.cpp
SkipList.cpp:63:2: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
        auto random_integer = uni(rng);
        ^
1 warning generated.
clang++ Main.cpp Element.o SkipList.o -o Main.o
chmod +x Main.o
./Main.o
Skip-Liste
|(5) 0(1) 1(5) 2(0) 3(0) 4(0) 5(0) 6(2) 7(0) 8(2) 9(0) 10(1)

Will delete 0
Skip-Liste
|(5) 1(5) 2(0) 3(0) 4(0) 5(0) 6(2) 7(0) 8(2) 9(0) 10(1)

rm -f *.o
```
