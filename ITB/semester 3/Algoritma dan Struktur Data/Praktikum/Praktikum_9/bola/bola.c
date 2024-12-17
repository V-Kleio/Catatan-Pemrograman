#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"

int main() {
    List l;
    CreateList(&l);
    int n, val, actval, i, j, length;
    scanf("%d", &n);
    for (i = n; i > 0; i--) {
        insertFirst(&l, i);
    }
    Address p;
    p = FIRST(l);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &actval);
        if (actval > 0) {
            length = n - i;
            val = (actval - 1) % length;
            for (j = 0; j < val; j++) {
                p = NEXT(p);
            }
            if (i == 0) {
                p = NEXT(p);
            }
            FIRST(l) = p;
            p = NEXT(p);
            deleteFirst(&l, &val);
        }
        else {
            length = n - i;
            val = -actval;
            val = val % length;
            val = -val;
            val = (length + val);
            for (j = 0; j < val; j++) {
                p = NEXT(p);
            }
            FIRST(l) = p;
            p = NEXT(p);
            deleteFirst(&l, &val);
        }
        // length = n - i;
        // val = (length + actval) % length;
        // for (j = 0; j < val - 1; j++) {
        //     p = NEXT(p);
        // }
        // if (i == 0)  {
        //     p = NEXT(p);
        // }
        // if (actval < 0 || actval > length) {
        //     p = NEXT(p);
        // }

        // FIRST(l) = p;
        // displayList(l);
        // printf("\n");
        // p = NEXT(p);
        // deleteFirst(&l, &val);
    }
    printf("%d\n", INFO(FIRST(l)));
    return 0;
}