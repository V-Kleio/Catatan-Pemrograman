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

List insertAt(List l, ElType e, int idx)
{
    Address node = newNode(e);

    if (node != NIL)
    {
        if (idx == 0)
        {
            List temp = l;
            l = node;
            NEXT(node) = temp;
        }
        else
        {
            Address currentAddress = l;
            int i;
            for (int i = 0; i < idx - 1; i++)
            {
                currentAddress = NEXT(currentAddress);
            }
            List temp = NEXT(currentAddress);
            NEXT(currentAddress) = node;
            NEXT(node) = temp;
        }
    }
    return l;
}

List deleteFirst(List l)
{
    return tail(l);
}

List deleteAt(List l, int idx)
{
    Address currentAddress = l;
    int i;
    if (idx == 0)
    {
        return deleteFirst(l);
    }

    for (int i = 0; i < idx - 1; i++)
    {
        currentAddress = NEXT(currentAddress);
    }
    NEXT(currentAddress) = NEXT(NEXT(currentAddress));
    
    return l;
}

List deleteLast(List l)
{
    Address currentAddress = l;
    while (!isOneElmt(tail(currentAddress)))
    {
        currentAddress = NEXT(currentAddress);
    }
    NEXT(currentAddress) = NIL;

    return l;
}

List reverseList (List l)
{
    if (isEmpty(l))
    {
        return NIL;
    }
    else
    {
        return konsb(reverseList(tail(l)), head(l));
    }
}

void splitOddEven (List l, List *l1, List *l2)
{
    Address currentAddress = l;
    *l1 = NIL;
    *l2 = NIL;

    while (currentAddress != NIL)
    {
        if (INFO(currentAddress) % 2 == 0)
        {
            if (isEmpty(*l1))
            {
                *l1 = newNode(INFO(currentAddress));
            }
            else
            {
                konsb(*l1, INFO(currentAddress));
            }
        }
        else
        {
            if (isEmpty(*l2))
            {
                *l2 = newNode(INFO(currentAddress));
            }
            else
            {
                konsb(*l2, INFO(currentAddress));
            }
        }
        currentAddress = NEXT(currentAddress);
    }
}

void splitOnX (List l, int x, List *l1, List *l2)
{
    Address currentAddress = l;
    *l1 = NIL;
    *l2 = NIL;

    int i;
    for (i = 0; i < x; i++)
    {
        if (isEmpty(*l1))
        {
            *l1 = newNode(INFO(currentAddress));
        }
        else
        {
            konsb(*l1, INFO(currentAddress));
        }

        currentAddress = NEXT(currentAddress);
    }

    while (currentAddress != NIL)
    {
        if (isEmpty(*l2))
        {
            *l2 = newNode(INFO(currentAddress));
        }
        else
        {
            konsb(*l2, INFO(currentAddress));
        }
        currentAddress = NEXT(currentAddress);
    }
}

ElType getMiddle(List l)
{
    Address currentAddress = l;

    int mid = length(l) / 2;
    int i;
    for (i = 0; i < mid; i++)
    {
        currentAddress = NEXT(currentAddress);
    }

    return INFO(currentAddress);
}