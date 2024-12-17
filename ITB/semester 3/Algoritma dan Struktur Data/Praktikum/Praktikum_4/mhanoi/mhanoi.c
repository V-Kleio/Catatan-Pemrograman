#include "matrix.h"

#include <stdio.h>

void rotateMatrix(Matrix *m);

int main()
{
    Matrix board, piringan;
    int N;
    IdxType i, j, k;
    int counter = 0;

    scanf("%d", &N);
    readMatrix(&board, N, N);
    readMatrix(&piringan, 2, 2);

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            for (k = 0; k < 4; k++)
            {
                if (ELMT(piringan, 0, 0) < ELMT(board, i, j) && ELMT(piringan, 0, 1) < ELMT(board, i, j + 1) && ELMT(piringan, 1, 0) < ELMT(board, i + 1, j) && ELMT(piringan, 1, 1) < ELMT(board, i + 1, j + 1))
                {
                    counter++;
                    break;
                }
                rotateMatrix(&piringan);
            }
        }
    }
    printf("%d\n", counter);
}

void rotateMatrix(Matrix *m)
{
    int temp = ELMT(*m, 0, 0);
    ELMT(*m, 0, 0) = ELMT(*m, 1, 0);
    ELMT(*m, 1, 0) = ELMT(*m, 1, 1);
    ELMT(*m, 1, 1) = ELMT(*m, 0, 1);
    ELMT(*m, 0, 1) = temp;
}