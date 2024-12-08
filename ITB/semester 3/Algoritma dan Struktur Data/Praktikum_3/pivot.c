#include "listdin.h"
#include <stdio.h>

int main()
{
    ListDin l;
    IdxType i;
    int counter = 0;

    CreateListDin(&l, 1000000);
    readList(&l);

    int n = NEFF(l);
    int maxLeft[n], minRight[n];

    maxLeft[0] = ELMT(l, 0);
    for (i = 1; i < n; i++)
    {
        maxLeft[i] = (ELMT(l, i) > maxLeft[i - 1]) ? ELMT(l, i) : maxLeft[i - 1];
    }

    minRight[n - 1] = ELMT(l, n - 1);
    for (i = n - 2; i >= 0; i--)
    {
        minRight[i] = (ELMT(l, i) < minRight[i + 1]) ? ELMT(l, i) : minRight[i + 1];
    }

    for (i = 0; i < n; i++)
    {
        if ((i == 0 || maxLeft[i - 1] <= ELMT(l, i)) && (i == n - 1 || minRight[i + 1] >= ELMT(l, i)))
        {
            counter++;
        }
    }

    printf("%d\n", counter);

}
