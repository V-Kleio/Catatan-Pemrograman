#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix m1, m2;
    readMatrix(&m1, 3, 3);
    float det = determinant(m1);
    printf("%.2f\n", det);
    return 0;
}