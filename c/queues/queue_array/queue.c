#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
extern const int kQueueCapacity;
extern const int kQueuePositions;
*/

void check_address(void *ptr) {
    if (!ptr) {
        printf("Queue can not be created\n");
        exit(EXIT_FAILURE);
    }
}

queue * create_queue() {
    queue *q = (queue *)malloc(sizeof(queue));
    check_address(q);

    q->front = 0;
    q->rear = 0;
    q->data = (int *)malloc(sizeof(int) * kQueuePositions);
    check_address(q->data);

    return q;
}

bool empty(queue *q) {
    return q->front == q->rear;
}

bool full(queue *q) {
    return q->front == (q->rear + 1) % kQueuePositions;
}

void enqueue(queue *q, int value) {
    if (full(q)) {
        printf("Queue is full\n");
        return;
    }

    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % kQueuePositions;
}

int dequeue(queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % kQueuePositions;

    return value;
}

void print_queue(queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i != q->rear; i = (i + 1) % kQueuePositions) {
        printf(" %d <-", q->data[i]);
    }

    printf("\n");
}
