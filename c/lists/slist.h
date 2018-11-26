#ifndef SLIST_H
#define SLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
}snode;

snode * create_node(int value);
void print_list(snode *head);
int size(snode *head);
void push_front(snode **headptr, int value);
void destroy_list(snode **headptr);
bool empty(snode *head);
int value_at(snode *head, int index);
int pop_front(snode **headptr);
void push_back(snode **headptr, int value);
int pop_back(snode **headptr);
int front(snode *head);
int back(snode *head);
void insert(snode **headptr, int index, int value);
void erase(snode **headptr, int index);
int value_n_from_end(snode *head, int n);
void reverse(snode **headptr);
void remove_value(snode **headptr, int value);
void check_address(void *ptr);


#endif
