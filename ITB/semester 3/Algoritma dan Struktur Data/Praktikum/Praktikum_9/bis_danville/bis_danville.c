#include "list_circular.h"

#include <stdio.h>

boolean checkClockwise(List l);
boolean checkCounterClockwise(List l);

int main()
{
    List l;
    CreateList(&l);

    int n, i, val;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertLast(&l, val);
    }

    if (checkClockwise(l))
    {
        printf("YES\n");
    }
    else if (checkCounterClockwise(l))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

boolean checkClockwise(List l)
{
    Address initialAddress = search(l, 1);
    FIRST(l) = initialAddress;
    Address currentAddress = FIRST(l);

    boolean isValid = true;
    while(NEXT(currentAddress) != FIRST(l))
    {
        if (INFO(currentAddress) > INFO(NEXT(currentAddress)))
        {
            isValid = false;
        }
        currentAddress = NEXT(currentAddress);
    }

    return isValid;
}

boolean checkCounterClockwise(List l)
{
    Address initialAddress = search(l, 1);
    FIRST(l) = initialAddress;
    Address currentAddress = NEXT(FIRST(l));

    boolean isValid = true;
    while(currentAddress != FIRST(l))
    {
        if (INFO(currentAddress) < INFO(NEXT(currentAddress)))
        {
            isValid = false;
        }
        currentAddress = NEXT(currentAddress);
    }

    return isValid;
}