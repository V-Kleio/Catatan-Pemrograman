#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    Address p1 = l1;
    Address p2 = l2;
    List result = NIL;

    while (p1 != NIL && p2 != NIL)
    {
        if (INFO(p1) < INFO(p2))
        {
            result = konsb(result, INFO(p1));
            p1 = NEXT(p1);
        }
        else if (INFO(p1) > INFO(p2))
        {
            result = konsb(result, INFO(p2));
            p2 = NEXT(p2);
        }
        else
        {
            result = konsb(result, INFO(p1));
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }
    }

    while (p1 != NIL)
    {
        result = konsb(result, INFO(p1));
        p1 = NEXT(p1);
    }

    while (p2 != NIL)
    {
        result = konsb(result, INFO(p2));
        p2 = NEXT(p2);
    }
    
    *res = result;
}
