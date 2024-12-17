#include "rotating_point.h"

COMPLEX PowerCOMPLEX(COMPLEX C, int p)
{
    if (p == 0)
    {
        COMPLEX result;
        CreateComplex(&result, 1, 0);
        return result;
    }
    if (p == 1)
    {
        return C;
    }
    return MultiplyCOMPLEX(C, PowerCOMPLEX(C, p - 1));
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n)
{
    if (n == 0)
    {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }

    int i;
    COMPLEX pC;
    float x, y;

    for (i = 1; i <= n; i++)
    {
        pC = PowerCOMPLEX(C, i);

        x = Absis(*P);
        y = Ordinat(*P);

        Absis(*P) = x * Real(pC) - y * Imag(pC);
        Ordinat(*P) = x * Imag(pC) + y * Real(pC);

        if (pow(Absis(*P), 2) + pow(Ordinat(*P), 2) > 1.0f)
        {
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            return;
        }
    }

    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}