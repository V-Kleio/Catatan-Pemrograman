#include "list_circular.h"

#include <stdio.h>


boolean isEmpty(List l)
{
    return FIRST(l) == NULL;
}

void CreateList(List *l)
{
    FIRST(*l) = NULL;
}

Address allocate(ElType val)
{
    Address p = (Address)malloc(sizeof(ElmtList));
    if (p != NULL) 
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P)
{
    free(P);
}

Address search(List l, ElType val)
{
    if (isEmpty(l)) 
    {
        return NULL;
    }

    Address currentAddress = FIRST(l);
    boolean isFound = false;

    while (NEXT(currentAddress) != FIRST(l) && !isFound)
    {
        isFound = INFO(currentAddress) == val;
        if (!isFound) 
        {
            currentAddress = NEXT(currentAddress);
        }
    }

    if (INFO(currentAddress) == val) 
    {
        return currentAddress;
    }

    if (isFound) 
    {
        return currentAddress;
    }
    
    return NULL;
}


boolean addrSearch(List l, Address p)
{
    if (isEmpty(l)) 
    {
        return false;
    }

    Address currentAddress = FIRST(l);
    boolean isFound = false;

    while (NEXT(currentAddress) != FIRST(l) && !isFound)
    {
        isFound = currentAddress == p;
        if (!isFound) 
        {
            currentAddress = NEXT(currentAddress);
        }
    }
    if (currentAddress == p) 
    {
        return true;
    }
    return isFound;
}

void insertFirst(List *l, ElType val)
{
    Address newNodeAddress = allocate(val);
    Address firstNodeAddress = FIRST(*l);
    if (newNodeAddress != NULL)
    {
        if (isEmpty(*l))
        {
            FIRST(*l) = newNodeAddress;
            NEXT(newNodeAddress) = FIRST(*l);
        } 
        else 
        {
            NEXT(newNodeAddress) = firstNodeAddress;
            FIRST(*l) = newNodeAddress;
            newNodeAddress = NEXT(newNodeAddress);
            while (NEXT(newNodeAddress) != firstNodeAddress)
            {
                newNodeAddress = NEXT(newNodeAddress);
            }
            NEXT(newNodeAddress) = FIRST(*l);
        }
    }
}

void insertLast(List *l, ElType val)
{
    Address currentAddress = FIRST(*l);
    if (isEmpty(*l)) 
    {   
        insertFirst(l,val);
    } 
    else 
    {
        while (NEXT(currentAddress) != FIRST(*l))
        {
            currentAddress = NEXT(currentAddress);
        }
        NEXT(currentAddress) = allocate(val);
        if (NEXT(currentAddress) != NULL) 
        {
            NEXT(NEXT(currentAddress)) = FIRST(*l);
        } 
        else 
        {
            NEXT(currentAddress) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType * val)
{
    Address deletedAddress = FIRST(*l);
    *val = INFO(deletedAddress);
    if (NEXT(deletedAddress) == deletedAddress)
    {
        FIRST(*l) = NULL;
    } 
    else 
    {
        FIRST(*l) = NEXT(deletedAddress);
        Address currentAddress = FIRST(*l);
        while (NEXT(currentAddress) != deletedAddress){
            currentAddress = NEXT(currentAddress);
        }
        NEXT(currentAddress) = FIRST(*l);
    }
    deallocate(deletedAddress);
}

void deleteLast(List *l, ElType * val)
{
    Address deletedAddress = FIRST(*l);
    Address currentAddress = NULL;
    while (NEXT(deletedAddress) != FIRST(*l))
    {
        currentAddress = deletedAddress;
        deletedAddress = NEXT(deletedAddress);
    }
    *val = INFO(deletedAddress);
    if (currentAddress == NULL)
    {
        FIRST(*l) = NULL;
    } 
    else 
    {
        NEXT(currentAddress) = FIRST(*l);
    }
    deallocate(deletedAddress);
}

void displayList(List l)
{
    printf("[");
    Address currentAddress = FIRST(l);
    while (NEXT(currentAddress)!=FIRST(l))
    {
        printf("%d,", INFO(currentAddress));
        currentAddress = NEXT(currentAddress);
    }
    if (currentAddress != NULL)
    {
        printf("%d", INFO(currentAddress));
    }
    printf("]");
}