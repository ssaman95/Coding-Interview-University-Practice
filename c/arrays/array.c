// Contains the implementation of dynamic array functions
// and test functions for the implementation.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "array.h"

const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;


SArray* new_sarray(int capacity) {
    int true_capacity = determine_capacity(capacity);

    SArray *arr = (SArray *)malloc(sizeof(SArray));
    check_address(arr);

    arr->size = 0;
    arr->capacity = true_capacity;
    arr->data = (int *)malloc(sizeof(int) * true_capacity);
    check_address(arr->data);

    return arr;
}

void resize_for_size(SArray *arrptr, int candidate_size) {
    if (arrptr->size < candidate_size) {
        if (arrptr->size == arrptr->capacity) {
            upsize(arrptr);
        }
    } else if (arrptr->size > candidate_size) {
        if (arrptr->size < arrptr->capacity / kShrinkFactor) {
            downsize(arrptr);
        }
    }
}

void upsize(SArray *arrptr) {
    int old_capacity = arrptr->capacity;
    int new_capacity = determine_capacity(old_capacity);

    int *new_data = (int *)malloc(sizeof(int) * new_capacity);
    check_address(new_data);

    for (int i = 0; i < arrptr->size; ++i) {
        *(new_data + i) = *(arrptr->data + i);
    }

    free(arrptr->data);

    arrptr->data = new_data;
    arrptr->capacity = new_capacity;
}

void downsize(SArray *arrptr) {
    int old_capacity = arrptr->capacity;
    int new_capacity = old_capacity / 2;

    if (new_capacity < kMinCapacity) {
        new_capacity = kMinCapacity;
    }

    if (new_capacity != old_capacity) {
        int *new_data = (int *)malloc(sizeof(int) * new_capacity);
        check_address(new_data);

        for (int i = 0; i < arrptr->size; ++i) {
            *(new_data + i) = *(arrptr->data + i);
        }

        free(arrptr->data);

        arrptr->data = new_data;
        arrptr->capacity = new_capacity;
    }
}

int determine_capacity(int capacity) {
    const int kMinInitialCapacity = 1;
    
    if (capacity < kMinInitialCapacity) {
        exit(EXIT_FAILURE);
    }

    int true_capacity = kMinCapacity;

    while (capacity > true_capacity / kGrowthFactor) {
        true_capacity *= kGrowthFactor;
    }

    return true_capacity;
}

int size(SArray *arrptr) { return arrptr->size; }

void destroy(SArray *arrptr) {
    free(arrptr->data);
    free(arrptr);
}

void push(SArray* arrptr, int item) {
    resize_for_size(arrptr, arrptr->size + 1);

    *(arrptr->data + arrptr->size) = item;
    ++(arrptr->size);
}

void print(SArray* arrptr) {
    printf("size = %d\n", arrptr->size);
    printf("capacity = %d\n", arrptr->capacity);
    printf("items = \n");

    for (int i = 0; i < arrptr->size; ++i)
        printf("%d : %d\n", i, *(arrptr->data + i));

    printf("----------\n");
}

int capacity(SArray *arrptr) { return arrptr->capacity; }

bool is_empty(SArray *arrptr) { return arrptr->size == 0; }

int at(SArray *arrptr, int index) {
    if (index < 0 || index >= arrptr->size) {
        exit(EXIT_FAILURE);
    }

    return *(arrptr->data + index);
}

void insert(SArray *arrptr, int index, int value) {
    if (index < 0 || index >= arrptr->size)
        exit(EXIT_FAILURE);

    resize_for_size(arrptr, arrptr->size + 1);

    for (int i = arrptr->size; i > index; --i) {
        *(arrptr->data + i) = *(arrptr->data + i - 1);
    }

    *(arrptr->data + index) = value;
    (arrptr->size)++;
}

void prepend(SArray *arrptr, int value) {
    insert(arrptr, 0, value);
}

int pop(SArray *arrptr) {
    if (arrptr->size == 0) {
        exit(EXIT_FAILURE);
    }

    resize_for_size(arrptr, arrptr->size - 1);

    int popped_value = *(arrptr->data + arrptr->size - 1);
    --(arrptr->size);

    return popped_value;
}

void delete_at(SArray *arrptr, int index) {
    if (index < 0 || index >= arrptr->size) {
        exit(EXIT_FAILURE);
    }

    resize_for_size(arrptr, arrptr->size - 1);

    for (int i = index; i < arrptr->size - 1; ++i) {
        *(arrptr->data + i) = *(arrptr->data + i + 1);
    }

    --(arrptr->size);
}

void remove_value(SArray *arrptr, int value) {
    for (int i = 0; i < arrptr->size; ++i) {
        if (*(arrptr->data + i) == value) {
            delete_at(arrptr, i);
            --i;
        }
    }
}

int find(SArray *arrptr, int value) {
    int found_index = -1;

    for (int i = 0; i < arrptr->size; ++i) {
        if (*(arrptr->data + i) == value) {
            found_index = i;
            break;
        }
    }

    return found_index;
}

void check_address(void *p) {
    if(!p) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}


//==========================TESTS============================

void run_all_tests() {
    printf("Testing...\n");
  test_size_init();
  test_append();
  test_empty();
  test_resize();
  test_at();
  test_insert();
  test_prepend();
  test_pop();
  test_remove();
  test_find_exists();
  test_find_not_exists();
  printf("Done Testing\n");
}

void test_size_init() {
    SArray *aptr = new_sarray(2);
    int initial_size = size(aptr);
    assert(initial_size == 0);
    destroy(aptr);
}

void test_append() {
    SArray *aptr = new_sarray(2);
    push(aptr, 2);
    push(aptr, 12);
    assert(size(aptr) == 2);
    destroy(aptr);
}

void test_empty() {
    SArray *aptr = new_sarray(2);
    bool empty = is_empty(aptr);
    assert(empty);
    push(aptr, 2);
    empty = is_empty(aptr);
    assert(!empty);
    pop(aptr);
    empty = is_empty(aptr);
    assert(empty);
    destroy(aptr);
}

void test_resize() {
    SArray *aptr = new_sarray(2);
    
    int current_capacity = capacity(aptr);
    assert(current_capacity == 16);

    for (int i = 0; i < 17; i++) {
        push(aptr, i+1);
    }
    current_capacity = capacity(aptr);
    assert(current_capacity == 32);
    
    for (int i = 0; i < 15; i++) {
        pop(aptr);
    }
    current_capacity = capacity(aptr);
    assert(current_capacity == 16);

    destroy(aptr);
}

void test_at() {
  SArray *aptr = new_sarray(12);
  for (int i = 0; i < 12; ++i) {
    push(aptr, i + 3);
  }
  assert(at(aptr, 6) == 9);
  destroy(aptr);
}

void test_insert() {
    SArray *aptr = new_sarray(10);
    for (int i = 0; i < 10; ++i) {
        push(aptr, i+1);
    }
    insert(aptr, 2, 47);
    assert(at(aptr, 1) == 2);
    assert(at(aptr, 2) == 47);
    assert(at(aptr, 3) == 3);
    destroy(aptr);
}

void test_prepend() {
    SArray *aptr = new_sarray(10);
    for (int i = 0; i < 10; ++i) {
        push(aptr, i + 1);
    }
    prepend(aptr,47);
    assert(at(aptr, 0) == 47);
    assert(at(aptr, 1) == 1);
    destroy(aptr);
}

void test_pop() {
    SArray *aptr = new_sarray(5);
    for (int i = 0; i < 5; ++i) {
        push(aptr, i);
    }
    pop(aptr);
    assert(size(aptr) == 4);

    for (int i = 0; i < 4; ++i)
        pop(aptr);
    assert(size(aptr) == 0);

    destroy(aptr);
}

void test_remove() {
    SArray *aptr = new_sarray(5);
    push(aptr,2);
    push(aptr,1);
    push(aptr,1);
    push(aptr,2);
    push(aptr,2);
    remove_value(aptr, 2);
    assert(size(aptr) == 2);
    destroy(aptr);
}

void test_find_exists() {
    SArray *aptr = new_sarray(5);
    push(aptr,1);
    push(aptr,2);
    push(aptr,3);
    push(aptr,4);
    push(aptr,5);
    assert(find(aptr, 1) == 0);
    assert(find(aptr, 3) == 2);
    assert(find(aptr, 5) == 4);
    destroy(aptr);
}

void test_find_not_exists() {
    SArray *aptr = new_sarray(5);
    push(aptr,2);
    push(aptr,1);
    push(aptr,1);
    push(aptr,2);
    push(aptr,2);
    assert(find(aptr, 7) == -1);
    destroy(aptr);
}
