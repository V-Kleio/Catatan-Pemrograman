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
    boolean nq = false;
    int temp, temp2;
    if (isEmpty(*pq)) 
    {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
        return;
    } 
    int old = IDX_TAIL(*pq);
    IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % (CAPACITY);
    int i = IDX_HEAD(*pq);
    int ctr = 0;
    while(ctr != length(*pq))
    {
        if (pq->buffer[i] < val || nq)
        {
            if(!nq)
            {
                temp = pq->buffer[i];
                pq->buffer[i] = val;
                nq = true;
            }
            else
            {
                // printf("%d", temp);
                temp2 = pq->buffer[i];
                pq->buffer[i] = temp;
                temp = temp2;
                // printf("%d", temp);
            }
        }

        if (i == old && !nq)
        {
            TAIL(*pq) = val;
        }
        i = (i + 1) % CAPACITY;
        ctr++;
    }
    return;
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