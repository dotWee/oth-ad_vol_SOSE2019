LENGTH = 10

all: feld clean

feld:
	g++ -c Main.cpp
	g++ -c Feld.cpp
	g++ Main.o Feld.o -o Cmain
	chmod +x Cmain
	./Cmain $(LENGTH)

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Cmain