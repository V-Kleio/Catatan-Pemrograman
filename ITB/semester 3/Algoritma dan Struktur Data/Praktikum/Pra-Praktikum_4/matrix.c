#include "matrix.h"
#include <stdio.h>

void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j)
{
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m)
{
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m)
{
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i)
{
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut)
{
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    for (int i = 0; i < ROW_EFF(mIn); i++)
    {
        for (int j = 0; j < COL_EFF(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol)
{
    createMatrix(nRow, nCol, m);
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m)
{
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            if (j != COL_EFF(m) - 1)
            {
                printf("%d ", ELMT(m, i, j));
            }
            else
            {
                if (i != ROW_EFF(m) - 1)
                {
                    printf("%d\n", ELMT(m, i, j));
                }
                else
                {
                    printf("%d", ELMT(m, i, j));
                }
            }
        }
    }
}

Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);
    for (int i = 0; i < ROW_EFF(m1); i++)
    {
        for (int j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m);
    for (int i = 0; i < ROW_EFF(m1); i++)
    {
        for (int j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for (int i = 0; i < ROW_EFF(m1); i++)
    {
        for (int j = 0; j < COL_EFF(m2); j++)
        {
            ELMT(m, i, j) = 0;
            for (int k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}

Matrix multiplyByConst(Matrix m, ElType x)
{
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            ELMT(mOut, i, j) = ELMT(m, i, j) * x;
        }
    }
    return mOut;
}

void pMultiplyByConst(Matrix *m, ElType k)
{
    for (int i = 0; i < ROW_EFF(*m); i++)
    {
        for (int j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2))
    {
        return false;
    }
    for (int i = 0; i < ROW_EFF(m1); i++)
    {
        for (int j = 0; j < COL_EFF(m1); j++)
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
}

int countElmt(Matrix m)
{
    return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m)
{
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m)
{
    if (!isSquare(m))
    {
        return false;
    }
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(Matrix m)
{
    if (!isSquare(m))
    {
        return false;
    }
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            if (i == j)
            {
                if (ELMT(m, i, j) != 1)
                {
                    return false;
                }
            }
            else
            {
                if (ELMT(m, i, j) != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

boolean isSparse(Matrix m)
{
    int count = 0;
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return count <= 0.05 * countElmt(m);
}

Matrix negation(Matrix m)
{
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m)
{
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m)
{
    if (!isSquare(m))
    {
        return 0;
    }
    if (ROW_EFF(m) == 1)
    {
        return ELMT(m, 0, 0);
    }
    if (ROW_EFF(m) == 2)
    {
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);
    }
    float det = 0;
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        Matrix subMatrix;
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &subMatrix);
        for (int j = 1; j < ROW_EFF(m); j++)
        {
            for (int k = 0; k < COL_EFF(m); k++)
            {
                if (k < i)
                {
                    ELMT(subMatrix, j - 1, k) = ELMT(m, j, k);
                }
                else if (k > i)
                {
                    ELMT(subMatrix, j - 1, k - 1) = ELMT(m, j, k);
                }
            }
        }
        det += ELMT(m, 0, i) * determinant(subMatrix) * (i % 2 == 0 ? 1 : -1);
    }
    return det;
}

Matrix transpose(Matrix m)
{
    Matrix mOut;
    createMatrix(COL_EFF(m), ROW_EFF(m), &mOut);
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            ELMT(mOut, j, i) = ELMT(m, i, j);
        }
    }
    return mOut;
}

void pTranspose(Matrix *m)
{
    Matrix mOut = transpose(*m);
    copyMatrix(mOut, m);
}