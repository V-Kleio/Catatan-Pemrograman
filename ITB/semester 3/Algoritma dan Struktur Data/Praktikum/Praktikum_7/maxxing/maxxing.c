#include <stdio.h>
#include "prioqueue.h"

int main() {
    int n; scanf("%d", &n);
    PrioQueue character, weapon;
    CreatePrioQueue(&character);
    CreatePrioQueue(&weapon);
    
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        enqueue(&character, a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        enqueue(&weapon, b);
    }

    long long ans = 0;
    long long str = 0;
    ElType charTemp, weapTemp;
    for (int i = 0; i < n; i++)
    {
        dequeue(&character, &charTemp);
        dequeue(&weapon, &weapTemp);
        str = charTemp;
        str = str * weapTemp;
        ans = ans + str;
    }
    

    printf("%lld\n", ans);
}