#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    if (*p == NULL)
    {
        return;
    }

    BinTree temp = LEFT(*p);
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = temp;

    invertTree(&LEFT(*p));
    invertTree(&RIGHT(*p));
}