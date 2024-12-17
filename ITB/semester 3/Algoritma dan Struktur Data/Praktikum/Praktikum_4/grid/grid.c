#include "matrix.h"

#include <stdio.h>
#include <math.h>


int main()
{
    Matrix board;
    int N, banyakJalan;
    int mod = pow(10, 9) + 7;
    IdxType i, j;

    scanf("%d", &N);
    readMatrix(&board, N, N);


    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ELMT(board, i, j) == 1)
            {
                ELMT(board, i, j) = -1;
            }
        }
    }

    ELMT(board, 0, 0) = 1;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i < N - 1 && ELMT(board, i, j) > 0)
            {
                if (ELMT(board, i + 1, j) > -1)
                {
                    ELMT(board, i + 1, j) += ELMT(board, i, j);
                    ELMT(board, i + 1, j) = ELMT(board, i + 1, j) % mod;
                }
            }

            if (j < N - 1 && ELMT(board, i, j) > 0)
            {
                if (ELMT(board, i, j + 1) > -1)
                {
                    ELMT(board, i, j + 1) += ELMT(board, i, j);
                    ELMT(board, i, j + 1) = ELMT(board, i, j + 1) % mod;
                }
            }
        }
    }

    banyakJalan = ELMT(board, N - 1, N - 1);
    banyakJalan = banyakJalan % mod;
    printf("%d\n", banyakJalan);

}