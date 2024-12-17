#include "listrec.h"
#include <stdio.h>

ElType getLastValue(List l) {
    if (isEmpty(l)) {
        return 0;
    }
    Address p = l;
    while (NEXT(p) != NIL) {
        p = NEXT(p);
    }
    return INFO(p);
}

List reorderList(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return copy(l);
    } else {
        ElType first = head(l);
        ElType last = getLastValue(l);

        List newList = NIL;
        newList = konso(newList, first);
        newList = konsb(newList, last);

        List copyL = copy(l);

        copyL = deleteLast(copyL);

        copyL = tail(copyL);

        List reordered = reorderList(copyL);

        List result = concat(newList, reordered);

        return result;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    List original = NIL;
    for(int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        original = konsb(original, value);
    }

    List reordered = reorderList(original);

    displayList(reordered);
    return 0;
}