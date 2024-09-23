#include <stdio.h>

int main() 
{
    //=================================================================
    // * Inisialisasi variable n, a, b dan meminta input untuk n, a, b
    int n, a, b;
    scanf("%i %i %i", &n, &a, &b);
    //=================================================================

    //=================================================================
    // * Print hasil dari fibonacci(n, a, b)
    printf("%i\n", fibonacci(n, a, b));
    //=================================================================

    return 0;
}

int fibonacci(int n, int a, int b) 
{
    //==========================================================================
    // * Jika n == 1 maka return a
    if (n == 1) 
    {
        return a;
    }
    //==========================================================================

    //==========================================================================
    // * Jika n == 2 maka return b
    if (n == 2) 
    {
        return b;
    }
    //==========================================================================

    //==========================================================================
    // * Jika n > 2 maka return fibonacci(n - 1, a, b) + fibonacci(n - 2, a, b)
    return fibonacci(n - 1, a, b) + fibonacci(n - 2, a, b);
    //==========================================================================
}