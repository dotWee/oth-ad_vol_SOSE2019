all: matrix clean

matrix:
	clang++ -c Main.cpp 
	clang++ -c Matrix.cpp
	clang++ Main.o Matrix.o -o Cmain
	chmod +x Cmain
	./Cmain

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Cmain