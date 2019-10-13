#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

/*
void check_address(void *ptr) {
    if (!ptr) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}
*/

stack * create_stack() {
    stack *s = (stack *)malloc(sizeof(stack));
    check_address(s);

    s->head = NULL;
    return s;
}

bool stack_empty(stack *s) {
    return s->head == NULL;
}

void print_stack(stack *s) {
    if (stack_empty(s)) {
        printf("empty stack\n");
        return;
    }

    s_node *current = s->head;

    while (current){
        printf(" %d ->", current->data);
        current = current->next;
    }

    printf("\n");
}


s_node * create_stack_node(int value) {
    s_node *snode = (s_node *)malloc(sizeof(s_node));
    check_address(snode);

    snode->data = value;
    snode->next = NULL;

    return snode;
}

void push(stack *s, int value) {
    s_node *snode = create_stack_node(value);
    snode->next = s->head;

    s->head = snode;
}

int pop(stack *s) {
    if (s->head == NULL) {
        printf("Stack empty\n");
        exit(EXIT_FAILURE);
    }

    s_node *temp = s->head;
    int value = temp->data;
    s->head = s->head->next;

    free(temp);
    temp = NULL;

    return value;
}

int top(stack *s) {
    if (s->head)
        return s->head->data;
    else
        return INT_MIN;
}
