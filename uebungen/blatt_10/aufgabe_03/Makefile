all: main clean

main:
	clang++ -c NaiveSearch.cpp
	clang++ Main.cpp NaiveSearch.o -o Main.o
	chmod +x Main.o
	./Main.o

clean:
	$(RM) *.o