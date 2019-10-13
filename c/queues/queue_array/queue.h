#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

const int kQueueCapacity = 5;
const int kQueuePositions = 6;

typedef struct Queue {
    int *data;
    int front;
    int rear;
}queue;

void check_address(void *ptr);
queue *create_queue(void);
bool empty(queue *q);
bool full(queue*q);
void enqueue(queue *q, int value);
int dequeue(queue *q);
void print_queue(queue *q);

#endif
