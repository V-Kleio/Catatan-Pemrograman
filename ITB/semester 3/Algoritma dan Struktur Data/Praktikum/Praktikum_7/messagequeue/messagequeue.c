#include <stdio.h>
#include "queue.h"

int main() {
    int n;
    scanf("%d", &n);

    // Lakukan inisialisasi Queue disini
    Queue q;
    CreateQueue(&q);

    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        // Kerjakan keempat tipe query disini
        if (op == 1) {
            if (isFull(q))
            {
                int val;
                scanf(" %d", &val);
                
                printf("Queue Penuh\n");
            }
            else
            {
                int val;
                scanf(" %d", &val);

                enqueue(&q, val);
                printf("Enqueue %d Berhasil\n", val);
            }
        } else if (op == 2) {
            if (isEmpty(q))
            {
                printf("Queue Kosong\n");
            }
            else
            {
                ElType temp;
                dequeue(&q, &temp);

                printf("Dequeue %d Berhasil\n", temp);
            }
        } else if (op == 3) {
            if (isEmpty(q))
            {
                printf("Queue Kosong\n");
            }
            else
            {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
        } else if (op == 4) {
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
    }

    // Display Queue disini
    displayQueue(q);
}