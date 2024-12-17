#include "listlinier.h"

#include <stdio.h>


int main()
{
    List list;
    CreateList(&list);

    int input, i, insertIndex = -1;
    
    scanf("%d", &input);

    while (input != -9999)
    {
        for (i = 0; i < length(list); i++)
        {
            if (input <= getElmt(list, i))
            {
                insertIndex = i;
                break;
            }
        }

        if(insertIndex == -1)
        {
            insertLast(&list, input);
        }
        else
        {
            insertAt(&list, input, insertIndex);
        }

        insertIndex = -1;
        scanf("%d", &input);
    }

    displayList(list);
    
}