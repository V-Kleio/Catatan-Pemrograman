#include "listdin.h"
#include <stdio.h>

int main() {
    ListDin intervalay, newInterval;
    int newStart, newStop;
    IdxType i = 0;

    CreateListDin(&intervalay, 1000);
    CreateListDin(&newInterval, 1000);

    readList(&intervalay);

    scanf("%d", &newStart);
    scanf("%d", &newStop);


    while (i < listLength(intervalay) && ELMT(intervalay, i+1) < newStart) 
    {
        insertLast(&newInterval, ELMT(intervalay, i));
        insertLast(&newInterval, ELMT(intervalay, i + 1));
        i += 2;
    }

    while (i < listLength(intervalay) && ELMT(intervalay, i) <= newStop) 
    {
        if (ELMT(intervalay, i) < newStart) 
        {
            newStart = ELMT(intervalay, i);
        }
        if (ELMT(intervalay, i + 1) > newStop) 
        {
            newStop = ELMT(intervalay, i + 1);
        }
        i += 2;
    }

    insertLast(&newInterval, newStart);
    insertLast(&newInterval, newStop);

    while (i < listLength(intervalay)) 
    {
        insertLast(&newInterval, ELMT(intervalay, i));
        insertLast(&newInterval, ELMT(intervalay, i + 1));
        i += 2;
    }

    printf("%d", ELMT(newInterval, 0));
    for (i = 1; i < listLength(newInterval); i++) 
    {
        printf(" %d", ELMT(newInterval, i));
    }
    printf("\n");

    dealocateList(&intervalay);
    dealocateList(&newInterval);

    return 0;
}
