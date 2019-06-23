all: main clean

main:
	clang++ -c Element.cpp
	clang++ -c SkipList.cpp
	clang++ Main.cpp Element.o SkipList.o -o Main.o
	chmod +x Main.o
	./Main.o

clean:
	$(RM) *.o