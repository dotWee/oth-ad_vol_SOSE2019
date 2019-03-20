#include <time.h>
#include <stdio.h>

int Ggt(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    else if (a == 0)
    {
        return b;
    }
    else if (a > b)
    {
        return Ggt(a - b, b);
    }
    else
    {
        return Ggt(a, b - a);
    }
}

int main(void)
{
    clock_t start, end;
    start = clock();

    int a = 145;
    int b = 70;

    int ggt = Ggt(a, b);
    end = clock();

    printf("[REKURSIV] Der größte gemeinsame Teiler der Zahlen %d und %d ist %d. Dauer der Berechnung: %Lfms\n", a, b, ggt, (long double)(end - start));
    return 0;
}