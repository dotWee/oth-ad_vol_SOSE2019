all: main clean

main:
	clang++ -c MaxSum1D.cpp
	clang++ -c MaxSum2D.cpp
	clang++ Main.cpp MaxSum1D.o MaxSum2D.o -o Main.o
	chmod +x Main.o
	./Main.o

clean:
	$(RM) *.o