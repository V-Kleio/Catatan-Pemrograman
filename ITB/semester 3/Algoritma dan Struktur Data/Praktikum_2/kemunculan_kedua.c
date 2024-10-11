#include "liststatik.h"

int main() 
{
    ListStatik list, counter, uniqueList;

    readList(&list);
    sortList(&list, true);
    CreateListStatik(&counter);
    CreateListStatik(&uniqueList);

    for (int i = 0; i < listLength(list); i++) 
    {
        if (indexOf(uniqueList, ELMT(list, i)) == IDX_UNDEF) 
        {
            insertLast(&uniqueList, ELMT(list, i));
        }
    }

    for (int i = 0; i < listLength(uniqueList); i++) 
    {
        ELMT(counter, i) = 0;
    }

    for (int i = 0; i < listLength(list); i++) 
    {
        ELMT(counter, indexOf(uniqueList, ELMT(list, i)))++;
    }

    int max1 = -1;
    int max2 = -1;
    int freq1 = -1;
    int freq2 = -1;

    for (int i = 0; i < listLength(counter); i++) 
    {
        if (ELMT(counter, i) > freq1) 
        {
            freq2 = freq1;
            max2 = max1;
            freq1 = ELMT(counter, i);
            max1 = ELMT(uniqueList, i);
        } 
        else if (ELMT(counter, i) > freq2 && ELMT(counter, i) != freq1) 
        {
            freq2 = ELMT(counter, i);
            max2 = ELMT(uniqueList, i);
        }
    }

    if (max2 != -1 && freq2 != freq1) 
    {
        printf("%d\n", max2);
    } 
    else 
    {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
}