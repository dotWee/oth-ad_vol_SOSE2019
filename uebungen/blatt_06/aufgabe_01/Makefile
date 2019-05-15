all: verketteteliste clean

verketteteliste:
	clang++ verketteteliste.cpp -o Verketteteliste
	chmod +x Verketteteliste
	./Verketteteliste

lotto:
	clang++ -c Lotto.cpp
	clang++ -c Ringliste.cpp
	clang++ Lotto.o Ringliste.o -o Lotto
	chmod +x Lotto
	./Lotto

clean:
	$(RM) *.o
	$(RM) *.out
	$(RM) Verketteteliste
	$(RM) Lotto