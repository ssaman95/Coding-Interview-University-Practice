#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void check_address(void *ptr) {
    if (!ptr) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

queue * create_queue() {
    queue *q = (queue *)malloc(sizeof(queue));
    check_address(q);

    q->head = NULL;
    q->tail = NULL;

    return q;
}

bool empty(queue *q) {
    return q->head == NULL;
}

void print(queue *q) {
    if (empty(q)) {
        printf("Empty Queue\n");
        return;
    }

    node *current = q->head;

    while (current){
        printf(" %d ->", current->data);
        current = current->next;
    }

    printf("\n");
}


node * create_node(int value) {
    node *qnode = (node *)malloc(sizeof(node));
    check_address(qnode);

    qnode->data = value;
    qnode->next = NULL;

    return qnode;
}

void enqueue(queue *q, int value) {
    node *qnode = create_node(value);

    if (q->head == NULL) {
        q->head = qnode;
        q->tail = qnode;
    } else {
        q->tail->next = qnode;
        q->tail = qnode;
    }
}

int dequeue(queue *q) {
    if (q->head == NULL) {
        printf("Queue Empty\n");
        exit(EXIT_FAILURE);
    }

    node *temp = q->head;
    int value = temp->data;

    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
    }

    free(temp);
    temp = NULL;

    return value;
}
