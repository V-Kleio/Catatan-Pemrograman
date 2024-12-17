#include "bintree.h"

#include <stdio.h>

void count(BinTree T, int *include, int *exclude)
{
    if (T == NULL)
    {
        *include = 0;
        *exclude = 0;
        return;
    }

    int includeLeft, excludeLeft, includeRight, excludeRight;

    count(LEFT(T), &includeLeft, &excludeLeft);
    count(RIGHT(T), &includeRight, &excludeRight);

    *include = ROOT(T) + excludeLeft + excludeRight;
    *exclude = 0;

    if (includeLeft > excludeLeft)
    {
        *exclude += includeLeft;
    }
    else
    {
        *exclude += excludeLeft;
    }

    if (includeRight > excludeRight)
    {
        *exclude += includeRight;
    }
    else
    {
        *exclude += excludeRight;
    }
}

int mencurry(BinTree T)
{
    int include, exclude;
    count(T, &include, &exclude);
    if (include > exclude)
    {
        return include;
    }
    else
    {
        return exclude;
    }
}