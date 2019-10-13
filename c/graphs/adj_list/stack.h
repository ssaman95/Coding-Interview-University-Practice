#ifndef stack_H
#define stack_H

#include <stdbool.h>

typedef struct SNode {
    int data;
    struct SNode *next;
} s_node;

typedef struct stack {
    s_node *head;
} stack;

//void check_address(void *ptr);
stack * create_stack(void);
bool stack_empty(stack *s);
void print_stack(stack *s);
s_node * create_stack_node(int value);
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);

#endif
