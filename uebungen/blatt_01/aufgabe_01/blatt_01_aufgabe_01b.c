#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // Für a,b ∈ {30,...,40}
    for (int a = atoi(argv[1]); a <= atoi(argv[2]); a++)
    {
        for (int b = atoi(argv[1]); b <= atoi(argv[2]); b++)
        {

            // Berechne Ggt
            int ggt, kgv, tempA = a, tempB = b, ab;
            if (tempA == 0)
            {
                ggt = tempB;
            }
            else
            {
                while (tempB != 0)
                {
                    if (tempA > tempB)
                    {
                        tempA = tempA - tempB;
                    }
                    else
                    {
                        tempB = tempB - tempA;
                    }
                }
            }
            ggt = tempA;

            // Berechne a*b
            ab = a * b;

            // Berechne Kgv
            kgv = ab / ggt;

            // Ausgabe
            printf("a=%d b=%d ggt=%d a*b=%d kgv=%d\n", a, b, ggt, ab, kgv);
        }
    }
    return 0;
}