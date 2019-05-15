all: main cleanup

main:
	clang++ -c Matrix.cpp Stoppwatch.cpp Main.cpp
	clang++ Matrix.o Stoppwatch.o Main.o -o Main
	chmod +x Main
	./Main

cleanup:
	$(RM) *.o
	$(RM) Main
