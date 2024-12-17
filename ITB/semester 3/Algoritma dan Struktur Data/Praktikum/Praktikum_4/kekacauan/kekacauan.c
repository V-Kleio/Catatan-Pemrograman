#include "matrix.h"

#include <math.h>
#include <stdio.h>


int main() 
{
    Matrix board;
    int N;
    IdxType i, j, k;
    int mod = pow(10, 9) + 7;
    int kekacauan = 0;


    scanf("%d", &N);
    readMatrix(&board, N, N);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ELMT(board, i, j) != 0)
            {
                // Check for row
                for (k = 0; k < N; k++)
                {
                    if (k != i)
                    {
                        kekacauan = kekacauan + (ELMT(board, k, j) % mod);
                        kekacauan = kekacauan % mod;
                    }
                }


                //Check for column
                for (k = 0; k < N; k++)
                {
                    if (k != j)
                    {
                        kekacauan = kekacauan + (ELMT(board, i, k) % mod);
                        kekacauan = kekacauan % mod;
                    }
                }

            }
        }
    }


    kekacauan = kekacauan % mod;
    printf("%d\n", kekacauan);
}