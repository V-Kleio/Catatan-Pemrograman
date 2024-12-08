#include "prioqueue.h"
#include <stdio.h>

void CreatePrioQueue(PrioQueue *pq)
{
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq)
{
    return IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF;
}

boolean isFull(PrioQueue pq)
{
    return (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY - 1) || (IDX_TAIL(pq) + 1 == IDX_HEAD(pq));
}

int length(PrioQueue pq)
{
    if (isEmpty(pq)) {
        return 0;
    } else if (IDX_HEAD(pq) <= IDX_TAIL(pq)) {
        return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    } else {
        return (CAPACITY - IDX_HEAD(pq)) + (IDX_TAIL(pq) + 1);
    }
}

void enqueue(PrioQueue *pq, ElType val)
{
    boolean inserted = false;
    int temp, temp2;

    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
        return;
    }

    int oldTail = IDX_TAIL(*pq);
    IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
    int currentIndex = IDX_HEAD(*pq);
    int counter = 0;

    while (counter != length(*pq)) {
        if (pq->buffer[currentIndex] < val || inserted) {
            if (!inserted) {
                temp = pq->buffer[currentIndex];
                pq->buffer[currentIndex] = val;
                inserted = true;
            } else {
                temp2 = pq->buffer[currentIndex];
                pq->buffer[currentIndex] = temp;
                temp = temp2;
            }
        }

        if (currentIndex == oldTail && !inserted) {
            TAIL(*pq) = val;
        }

        currentIndex = (currentIndex + 1) % CAPACITY;
        counter++;
    }
}

void dequeue(PrioQueue *pq, ElType *val)
{
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % CAPACITY;
    }
}

void displayPrioQueue(PrioQueue pq)
{
    if (isEmpty(pq)) 
    {
        printf("[]\n");
    } 
    else 
    {
        printf("[");
        for (int i = IDX_HEAD(pq); i != IDX_TAIL(pq); i = (i + 1) % CAPACITY) 
        {
            printf("%d,", pq.buffer[i]);
        }
        printf("%d]\n", pq.buffer[IDX_TAIL(pq)]);
    }
}