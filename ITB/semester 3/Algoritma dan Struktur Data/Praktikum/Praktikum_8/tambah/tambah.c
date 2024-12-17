#include "listlinier.h"

#include <stdio.h>


int main()
{
    List firstList, secondList, resultList;
    CreateList(&firstList);
    CreateList(&secondList);
    CreateList(&resultList);

    int input = 0;

    while (input != -1)
    {
        scanf("%d", &input);
        if (input != -1)
        {
            insertLast(&firstList, input);
        }
    }

    input = 0;

    while (input != -1)
    {
        scanf("%d", &input);
        if (input != -1)
        {
            insertLast(&secondList, input);
        }
    }

    int i, firstListDigit, secondListDigit, maxLength, carry = 0, sumDigit;

    if (length(firstList) >= length(secondList))
    {
        maxLength = length(firstList);
        while (length(secondList) < length(firstList))
        {
            insertFirst(&secondList, 0);
        }
    }
    else
    {
        maxLength = length(secondList);
        while (length(secondList) > length(firstList))
        {
            insertFirst(&firstList, 0);
        }
    }

    for (i = maxLength - 1; i >= 0; i--)
    {
        firstListDigit = getElmt(firstList, i);
        secondListDigit = getElmt(secondList, i);
        if (carry)
        {
            sumDigit = firstListDigit + secondListDigit + carry;
        }
        else
        {
            sumDigit = firstListDigit + secondListDigit;
        }
        if (sumDigit > 9)
        {
            sumDigit -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        insertFirst(&resultList, sumDigit);
    }

    if (carry)
    {
        insertFirst(&resultList, 1);
    }


    for (i = 0; i < length(resultList) - 1; i++)
    {
        printf("%d ", getElmt(resultList, i));
    }

    printf("%d\n", getElmt(resultList, length(resultList) - 1));
}