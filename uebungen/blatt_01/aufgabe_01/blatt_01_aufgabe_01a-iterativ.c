#include <time.h>
#include <stdio.h>

int Ggt(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        while (b != 0)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
    }

    return a;
}

int main(void)
{
    clock_t start, end;
    start = clock();

    int a = 145;
    int b = 70;

    int ggt = Ggt(a, b);
    end = clock();

    printf("[ITERATIV] Der größte gemeinsame Teiler der Zahlen %d und %d ist %d. Dauer der Berechnung: %Lfms\n", a, b, ggt, (long double)(end - start));
    return 0;
}