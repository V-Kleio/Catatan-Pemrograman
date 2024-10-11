#include "liststatik.h"

void increment(ListStatik *l, IdxType idx);

int main()
{
    ListStatik list;

    readList(&list);
    increment(&list, getLastIdx(list));
    printf("%d", ELMT(list, 0));
    for (int i = 1; i < listLength(list); i++)
    {
        printf(" %d", ELMT(list, i));
    }
    printf("\n");

}

void increment(ListStatik *l, IdxType idx)
{
    if (idx == IDX_MIN && ELMT(*l, idx) == 9)
    {
        ELMT(*l, idx) = 0;
        insertFirst(l, 1);
    }
    else if (ELMT(*l, idx) == 9)
    {
        ELMT(*l, idx) = 0;
        increment(l, idx - 1);
    }
    else
    {
        ELMT(*l, idx) += 1;
    }
}
