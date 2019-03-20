a = 150
b = 40

ARRAY = 30 31 32 33 34 35 36 37 38 39 40

all: blatt_01_aufgabe_01a blatt_01_aufgabe_01a-speedtest blatt_01_aufgabe_01b clean

blatt_01_aufgabe_01a-speedtest: blatt_01_aufgabe_01a-iterativ blatt_01_aufgabe_01a-rekursiv

blatt_01_aufgabe_01a:
	@echo "Bestimmung des groeßten gemeinsamen Teilers in C"
	clang blatt_01_aufgabe_01a.c -o blatt_01_aufgabe_01a.o 
	chmod +x blatt_01_aufgabe_01a.o
	./blatt_01_aufgabe_01a.o $(a) $(b)

blatt_01_aufgabe_01a-iterativ:
	clang blatt_01_aufgabe_01a-iterativ.c -o blatt_01_aufgabe_01a-iterativ.o 
	chmod +x blatt_01_aufgabe_01a-iterativ.o
	./blatt_01_aufgabe_01a-iterativ.o

blatt_01_aufgabe_01a-rekursiv:
	clang blatt_01_aufgabe_01a-rekursiv.c -o blatt_01_aufgabe_01a-rekursiv.o 
	chmod +x blatt_01_aufgabe_01a-rekursiv.o
	./blatt_01_aufgabe_01a-rekursiv.o

blatt_01_aufgabe_01b:
	@echo "Bestimmung des groeßten gemeinsamen Teilers und kleinsten gemeinsamen Vielfachem in C"
	clang blatt_01_aufgabe_01b.c -o blatt_01_aufgabe_01b.o 
	chmod +x blatt_01_aufgabe_01b.o
	./blatt_01_aufgabe_01b.o 30 40

clean:
	$(RM) *.o