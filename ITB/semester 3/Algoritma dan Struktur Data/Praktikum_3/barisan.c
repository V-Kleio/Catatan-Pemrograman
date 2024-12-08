#include "listdin.h"
#include <stdio.h>

int main()
{
    ListDin l;
    IdxType i, j;
    ElType temp;
    int counter = 0;

    CreateListDin(&l, 1000);
    readList(&l);

    for (i = getFirstIdx(l); i < NEFF(l); i++)
    {
        for (j = NEFF(l) - 1; j > i; j--)
        {
            if (ELMT(l, j) < ELMT(l, j - 1))
            {
                temp = ELMT(l, j);
                ELMT(l, j) = ELMT(l, j - 1);
                ELMT(l, j - 1) = temp;
                counter++;
            }
        }
    }

    printf("%d\n", counter);
}