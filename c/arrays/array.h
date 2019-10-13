#ifndef ARRAY_H
#define ARRAY_H

/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
*/

#include <stdbool.h>

extern const int kMinCapacity;
extern const int kGrowthFactor;
extern const int kShrinkFactor;

typedef struct ASImplementationArray {
    int size;
    int capacity;
    int *data;
}SArray;

SArray* new_sarray(int capacity);
void destroy(SArray *arrptr);

void resize_for_size(SArray *arrptr, int candidate_size);
int determine_capacity(int capacity);
void upsize(SArray *arrptr);
void downsize(SArray *arrptr);

void push(SArray *arrptr, int item);
void print(SArray *arrptr);
int capacity(SArray *arrptr);
int size(SArray *arrptr);
bool is_empty(SArray *arrptr);
int at(SArray *arrptr, int index);
void insert(SArray *arrptr, int index, int value);
void prepend(SArray *arrptr, int value);
int pop(SArray *arrptr);
void delete_at(SArray *arrptr, int index);
void remove_value(SArray *arrptr, int value);
int find(SArray *arrptr, int value);
void check_address(void *p);

// tests

void run_all_tests();

void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
void test_resize();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_remove();
void test_find_exists();
void test_find_not_exists();

#endif
