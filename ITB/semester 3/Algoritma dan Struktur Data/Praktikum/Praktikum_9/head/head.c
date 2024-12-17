#include "list_circular.h"

#include <stdio.h>

int main()
{
    List l;
    CreateList(&l);

    int n, i;

    scanf("%d", &n);

    int val, max;
    scanf("%d", &val);
    insertLast(&l, val);
    max = val;
    
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &val);
        insertLast(&l, val);
        if (val >= max)
        {
            max = val;
        }
    }

    FIRST(l) = search(l, max);

    displayList(l);
}