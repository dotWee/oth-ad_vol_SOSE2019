all: main clean

main:
	clang++ -c Knot.cpp
	clang++ -c Tree.cpp
	clang++ -c RebuildTree.cpp
	clang++ Main.cpp Knot.o Tree.o RebuildTree.o -o Main.o
	chmod +x Main.o
	./Main.o

clean:
	$(RM) *.o