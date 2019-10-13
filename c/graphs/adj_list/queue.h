#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

typedef struct Queue {
    node *head;
    node *tail;
} queue;

void check_address(void *ptr);
queue * create_queue(void);
bool empty(queue *q);
void print(queue *q);
node * create_queue_node(int value);
void enqueue(queue *q, int value);
int dequeue(queue *q);

#endif
