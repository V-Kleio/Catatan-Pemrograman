#include <stdio.h>
#include "boolean.h"
#include "stack.h"

const int MXN = 1e4 + 7;

int main()
{
    int N;
    scanf("%d", &N);
    int heights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    int maxStrength[N + 1];
    for (int i = 0; i <= N; i++) {
        maxStrength[i] = 0;
    }

    Stack S;
    CreateEmpty(&S);

    int left[N], right[N];
    for (int i = 0; i < N; i++) {
        while (!IsEmpty(S) && heights[InfoTop(S)] >= heights[i]) {
            int temp;
            Pop(&S, &temp);
        }
        left[i] = IsEmpty(S) ? 0 : InfoTop(S) + 1;
        Push(&S, i);
    }

    CreateEmpty(&S);

    for (int i = N - 1; i >= 0; i--) {
        while (!IsEmpty(S) && heights[InfoTop(S)] >= heights[i]) {
            int temp;
            Pop(&S, &temp);
        }
        right[i] = IsEmpty(S) ? N - 1 : InfoTop(S) - 1;
        Push(&S, i);
    }

    for (int i = 0; i < N; i++) {
        int width = right[i] - left[i] + 1;
        maxStrength[width] = heights[i] > maxStrength[width] ? heights[i] : maxStrength[width];
    }

    for (int i = N - 1; i > 0; i--) {
        maxStrength[i] = maxStrength[i] > maxStrength[i + 1] ? maxStrength[i] : maxStrength[i + 1];
    }

    for (int i = 1; i < N; i++) {
        printf("%d ", maxStrength[i]);
    }
    printf("%d", maxStrength[N]);
    printf("\n");

    return 0;
} 