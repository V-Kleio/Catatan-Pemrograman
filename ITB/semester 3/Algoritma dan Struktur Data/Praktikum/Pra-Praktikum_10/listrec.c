#include "listrec.h"

#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x)
{
    Address address = (Address) malloc(sizeof(Node));

    if (address != NIL)
    {
        INFO(address) = x;
        NEXT(address) = NIL;
    }

    return address;
}

boolean isEmpty(List l)
{
    return l == NIL;
}

boolean isOneElmt(List l)
{
    if (isEmpty(l))
    {
        return false;
    }

    return NEXT(l) == NIL;
}

ElType head(List l)
{
    return INFO(l);
}

List tail(List l)
{
    return NEXT(l);
}

List konso(List l, ElType e)
{
    Address node = newNode(e);

    if (node != NIL)
    {
        NEXT(node) = l;
        l = node;
    }

    return l;
}

List konsb(List l, ElType e)
{
    Address node = newNode(e);

    if (node != NIL)
    {
        if (isEmpty(l))
        {
            l = node;
        }
        else
        {
            Address currentAddress = l;
            while (NEXT(currentAddress) != NIL)
            {
                currentAddress = NEXT(currentAddress);
            }
            NEXT(currentAddress) = node;
        }
    }

    return l;
}

List copy(List l)
{
    if (isEmpty(l))
    {
        return NIL;
    }
    else
    {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2)
{
    if (isEmpty(l1))
    {
        return(copy(l2));
    }
    else
    {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x)
{
    if (isEmpty(l))
    {
        return false;
    }
    else
    {
        if (head(l) == x)
        {
            return true;
        }
        else
        {
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l)
{
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}