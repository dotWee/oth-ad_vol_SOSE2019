all: main clean

main:
	clang++ -c Graph.cpp
	clang++ -c Knot.cpp
	clang++ -c Matrix.cpp
	clang++ Main.cpp Graph.o Knot.o Matrix.o -o Main.o
	chmod +x Main.o
	./Main.o

clean:
	$(RM) *.o