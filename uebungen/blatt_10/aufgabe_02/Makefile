all: main clean

main:
	clang++ -c BoyerMooreSearch.cpp
	clang++ -c NaiveSearch.cpp
	clang++ Main.cpp BoyerMooreSearch.o NaiveSearch.o -o Main.o
	chmod +x Main.o
	./Main.o

clean:
	$(RM) *.o