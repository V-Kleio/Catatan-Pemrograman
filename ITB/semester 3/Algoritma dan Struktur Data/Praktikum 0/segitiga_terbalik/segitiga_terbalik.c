#include <stdio.h>

int main()
{
    //============================================================
    // * Inisialisasi variable n, i, j dan meminta input untuk n
    int n, i, j;
    scanf("%i", &n);
    //============================================================

    //============================================================
    // * Looping untuk membuat segitiga terbalik

    // * Looping pertama untuk membuat baris pada segitiga
    for(i = n; i >= 1; i--)
    {
        // * Looping kedua untuk membuat spasi pada setiap baris
        // * jumlah spasi pada setiap baris sama dengan n - i
        for(j = n - i; j > 0; j--)
        {
            printf(" ");
        }

        // * Looping kedua untuk menggambar bintang pada setiap baris
        // * jumlah bintang pada setiap baris sama dengan 2 * i - 1
        for(j = 2 * i - 1; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
    //============================================================


    return 0;
}