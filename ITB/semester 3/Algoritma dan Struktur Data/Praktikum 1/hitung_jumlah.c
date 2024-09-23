#include <stdio.h>

int main()
{
    //=============================================================================
    // * Inisialisasi variable n, k, a_i, sum
    int i, n, k, a_i, sum;
    scanf("%i %i", &n, &k);
    sum = 0;
    //=============================================================================
    
    //=============================================================================
    /*
    * Looping sebanyak n kali
    * Meminta input a_i pada setiap loop
    * Jika a_i tidak habis dibagi k, tambahkan a_i ke sum
    */
    for (i = 0; i < n; i++)
    {
        scanf("%i", &a_i);
        if (a_i % k != 0)
        {
            sum += a_i;
        }
    }
    //=============================================================================

    printf("%i\n", sum);
    return 0;
}