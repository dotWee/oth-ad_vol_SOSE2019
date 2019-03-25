all: main clean

main:
	clang++ -c Reader.cpp Compiler.cpp RegisterMachine.cpp Main.cpp
	clang++ Reader.o Compiler.o RegisterMachine.o Main.o -o Cmain
	chmod +x Cmain
	./Cmain

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Cmain