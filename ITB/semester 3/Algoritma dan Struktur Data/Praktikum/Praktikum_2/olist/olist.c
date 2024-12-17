#include "liststatik.h"


int main()
{
    ListStatik list, counter, uniqueList;

    readList(&list);
    CreateListStatik(&counter);
    CreateListStatik(&uniqueList);
    
    for (int i = 0; i < listLength(list); i++) 
    {
        ELMT(counter, i) = 0;
    }

    for (int i = 0; i < listLength(list); i++) 
    {
        if (indexOf(uniqueList, ELMT(list, i)) == IDX_UNDEF) 
        {
            insertLast(&uniqueList, ELMT(list, i));
        }

        ELMT(counter, indexOf(uniqueList, ELMT(list, i)))++;
    }

    printList(uniqueList);
    printf("\n");
    for (int i = 0; i < listLength(uniqueList); i++) 
    {
        printf("%d %d\n", ELMT(uniqueList, i), ELMT(counter, i));
    }

}



