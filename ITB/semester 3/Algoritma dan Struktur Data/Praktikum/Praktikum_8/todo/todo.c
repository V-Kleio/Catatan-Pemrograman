#include "listlinier.h"

#include <stdio.h>


int main()
{
    List list;
    CreateList(&list);

    char prompt;
    int task;

    scanf("%c", &prompt);

    while (prompt != 'X')
    {
        switch (prompt)
        {
        case 'P':
            scanf(" %d", &task);

            insertFirst(&list, task);
            scanf("%c", &prompt);
            break;
        case 'I':
            scanf(" %d", &task);

            insertLast(&list, task);
            scanf("%c", &prompt);
            break;
        case 'C':
            if (length(list) > 0)
            {
                int garbage;
                deleteFirst(&list, &garbage);
            }
            scanf("%c", &prompt);
            break;
        case 'D':
            scanf(" %d", &task);
            int idx = IDX_UNDEF;
            int garbage;
            idx = indexOf(list, task);

            // while (idx != IDX_UNDEF)
            // {
            if (idx != IDX_UNDEF)
            {
                deleteAt(&list, idx, &garbage);
            }
            // idx = indexOf(list, task);
            // }
            scanf("%c", &prompt);
            break;
        default:
            scanf("%c", &prompt);
            break;
        }
    }
    displayList(list);
}