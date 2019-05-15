all:
	clang++ -c AVLTree.cpp
	clang++ -c Knot.cpp
	clang++ Main.cpp AVLTree.o Knot.o -o Main.o
	chmod +x Main.o
	./Main.o
	$(RM) *.o