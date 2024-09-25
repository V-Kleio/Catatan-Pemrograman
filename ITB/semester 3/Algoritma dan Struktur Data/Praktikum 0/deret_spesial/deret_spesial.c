#include <stdio.h>

int main()
{
    //=============================================================================
    // * Inisialisasi variable n, a, b dan meminta input untuk n, a, b
    int i, a, b;
    scanf("%i %i", &a, &b);
    //=============================================================================

    //=============================================================================
    // * Kode ini dibutuhkan agar sesuai dengan output yang diminta soal
    printf("%i", a);
    //=============================================================================

    //=============================================================================
    /*
    * Looping sebanyak selama a <= b
    * Jika a genap, kali a dengan 2
    * Jika a ganjil, tambah dengan 1
    * penjelasan ekspresi dalam condition while loop
    * syntax:
    * (condition) ? ekspresi jika condition benar : ekspresi jika condition salah
    * hal ini digunakan untuk mengatur ekspresi conditional pada while loop 
    * agar sesuai dengan genap atau ganjilnya a
    */
    while ((a % 2 == 0) ? a * 2 <= b : a + 1 <= b)
    {
        if (a % 2 == 0)
        {
            a *= 2;
        }
        else
        {
            a += 1;
        }
        // * print whitespace sebelum angka agar sesuai dengan output yang diminta
        printf(" %i", a);
    }
   //=============================================================================

    printf("\n");
    return 0;
}