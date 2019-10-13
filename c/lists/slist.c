#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slist.h"

snode *create_node(int value) {
    snode *node = (snode *)malloc(sizeof(snode));
    check_address(node);

    node->data = value;
    node->next = NULL;

    return node;
}

void check_address(void *ptr) {
    if(!ptr) {
        printf("Memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
}

void print_list(snode *head) {
    snode *current = head;

    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("\n");
}

int size(snode *head) {
    snode *current = head;
    int size = 0;

    while (current) {
        ++size;
        current = current->next;
    }

    return size;
}

void push_front(snode **headptr, int value) {
    snode *new_node = create_node(value);
    new_node->next = *headptr;

    *headptr = new_node;
}

void destroy_list(snode **headptr) {
    snode *current = *headptr;

    while (current) {
        snode *next = current->next;
        free (current);
        current = next;
    }

    *headptr = NULL;
}

bool empty(snode *head) { return head == NULL; }

int value_at(snode *head, int index) {
    int i = 0;
    snode *current = head;

    for (; i < index && current; ++i) {
        current = current->next;
    }

    if (i != index || !current) {
        printf("Invalid index\n");
        exit(EXIT_SUCCESS);
    } else {
        return current->data;
    }
}

int pop_front(snode **headptr) {
    if (*headptr == NULL) {
        printf("Empty List\n");
        exit(EXIT_FAILURE);
    }

    int value = (*headptr)->data;

    snode *temp = *headptr;
    *headptr = (*headptr)->next;

    free(temp);

    return value;
}

void push_back(snode **headptr, int value) {
    snode *new_node = create_node(value);

    if ((*headptr) == NULL) {
        *headptr = new_node;
        return;
    }

    snode *current = *headptr;

    while(current->next) {
        current = current->next;
    }

    current->next = new_node;
}

int pop_back(snode **headptr) {
    if (*headptr == NULL) {
        printf("Empty list\n");
        exit(EXIT_FAILURE);
    }

    snode *current = *headptr;
    snode *prev = NULL;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    int value = current->data;

    if (!prev) {
        *headptr = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);

    return value;
}

int front(snode *head) {
    if (!head) {
        printf("Empty List\n");
        exit(EXIT_FAILURE);
    }

    return head->data;
}

int back(snode *head) {
    if (!head) {
        printf("Empty List\n");
        exit(EXIT_FAILURE);
    }

    snode *current = head;
    while(current->next) {
        current = current->next;
    }

    return current->data;
}

void insert(snode **headptr, int index, int value) {
    snode *current = *headptr;
    snode *prev = NULL;
    int i = 0;

    for (; i < index && current; ++i) {
        prev = current;
        current = current->next;
    }

    if (i != index) {
        printf("%d\n", i);
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    snode *new_node = create_node(value);

    if (prev) {
        new_node->next = current;
        prev->next = new_node;
    } else {
        new_node->next = *headptr;
        *headptr = new_node;
    }
}

void erase(snode **headptr, int index) {
    if (*headptr == NULL) {
        printf("Empty List");
        exit(EXIT_FAILURE);
    }

    snode *current = *headptr;
    snode *prev = NULL;
    int i = 0;

    for (; i < index && current; ++i) {
        prev = current;
        current = current->next;
    }

    if (i != index) {
        printf("Inde out ofbounds\n");
        exit(EXIT_SUCCESS);
    }

    if (prev) {
        prev->next = current->next;
    } else {
        *headptr = current->next;
    }

    free(current);
}

int value_n_from_end(snode *head, int n) {
    if (n < 1 || head == NULL) {
        printf("Can not get nth value from end\n");
        exit(EXIT_FAILURE);
    }

    snode *current = head;
    snode *match = head;

    int i = 0;
    for (; i < n && current; ++i) {
        current = current->next;
    }

    if (i != n) {
        printf("List is too short\n");
        exit(EXIT_FAILURE);
    }

    while (current) {
        current = current->next;
        match = match->next;
    }

    return match->data;
}

void reverse(snode **headptr) {
    snode *prev = NULL;
    snode *current = *headptr;
    snode *next = *headptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headptr = prev;
}

void remove_value(snode **headptr, int value) {
    snode *current = *headptr;
    snode *prev = NULL;

    while (current) {
        if (current->data == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                *headptr = current->next;
            }

            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
}
