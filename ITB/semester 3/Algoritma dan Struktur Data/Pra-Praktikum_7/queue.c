#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1) || (IDX_TAIL(q) + 1 == IDX_HEAD(q));
}

int length(Queue q)
{
    if (isEmpty(q)) {
        return 0;
    } else if (IDX_HEAD(q) <= IDX_TAIL(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    } else {
        return (CAPACITY - IDX_HEAD(q)) + (IDX_TAIL(q) + 1);
    }
}

void enqueue(Queue *q, ElType val)
{
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val)
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

void displayQueue(Queue q)
{
    if (isEmpty(q)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY) {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", q.buffer[IDX_TAIL(q)]);
    }
}