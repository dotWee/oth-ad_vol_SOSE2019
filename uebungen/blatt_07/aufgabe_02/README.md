# Aufgabe 02 (AVLBäume)

Der Quellcode zur Implementierung in C++ kann in [AVLTree.cpp](AVLTree.cpp) sowie [Knot.cpp](Knot.cpp) und [Main.cpp](Main.cpp) eingesehen werden. _Make_ wird zur Ausführung genutzt:

```bash
$ make
clang++ -c AVLTree.cpp
clang++ -c Knot.cpp
clang++ Main.cpp AVLTree.o Knot.o -o Main.o
chmod +x Main.o
./Main.o
Es gibt 4096 viele Bäume der Höhe 5
Tree 0
((((((n,0,n),1,n),2,(n,0,n)),3,((n,0,n),1,n)),4,(((n,0,n),1,n),2,(n,0,n))),5,((((n,0,n),1,n),2,(n,0,n)),3,((n,0,n),1,n)))
Tree 1
((((((n,0,n),1,n),2,(n,0,n)),3,((n,0,n),1,n)),4,(((n,0,n),1,n),2,(n,0,n))),5,((((n,0,n),1,n),2,(n,0,n)),3,(n,1,(n,0,n))))
Tree 2
((((((n,0,n),1,n),2,(n,0,n)),3,((n,0,n),1,n)),4,(((n,0,n),1,n),2,(n,0,n))),5,(((n,1,(n,0,n)),2,(n,0,n)),3,((n,0,n),1,n)))
Tree 3
((((((n,0,n),1,n),2,(n,0,n)),3,((n,0,n),1,n)),4,(((n,0,n),1,n),2,(n,0,n))),5,(((n,1,(n,0,n)),2,(n,0,n)),3,(n,1,(n,0,n))))

...

Tree 4094
((((n,0,n),1,n),3,((n,0,n),2,(n,1,(n,0,n)))),5,(((n,0,n),2,(n,1,(n,0,n))),4,((n,1,(n,0,n)),3,((n,0,n),2,(n,1,(n,0,n))))))
Tree 4095
(((n,1,(n,0,n)),3,((n,0,n),2,(n,1,(n,0,n)))),5,(((n,0,n),2,(n,1,(n,0,n))),4,((n,1,(n,0,n)),3,((n,0,n),2,(n,1,(n,0,n))))))
rm -f *.o
```
