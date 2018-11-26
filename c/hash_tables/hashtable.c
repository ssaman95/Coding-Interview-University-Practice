#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

const int kTableSize = 100;
const char* kDummy = "<dummy>";

hash_table *create_hash_table(int size) {
    hash_table *table = (hash_table *) malloc(sizeof(hash_table));
    check_address(table);

    table->size = size;
    table->data = (key_value **) malloc(sizeof(key_value *) * size);
    check_address(table->data);

    for (int i = 0; i < size; i++) {
        table->data[i] = NULL;
    }

    return table;
}

int hash(char *key, int m) {
    unsigned int hash = 0;

    for (int i = 0; key[i] != '\0'; ++i) {
        hash = hash * 31 + key[i];
    }

    return hash % m;
}

bool exists(hash_table *table, char *key) {
    int index = hash(key, table->size);
    int original_index = index;

    while (table->data[index] != NULL) {
        if (!strcmp(table->data[index]->key, key)) {
            return true;
        }

        index = (index + 1) % table->size;

        if (index == original_index) {
            return false;
        }
    }

    return false;
}

void add(hash_table *table, char *key, char *value) {
    if (!exists(table, key)) {
        int index = hash(key, table->size);
        int original_index = index;

        while (table->data[index] != NULL && strcmp(table->data[index]->key, kDummy)) {
            index = (index + 1) % table->size;

            if (index == original_index) {
                printf("Table is full\n");
                return;
            }
        }

        if (table->data[index] == NULL) {
            table->data[index] = malloc(sizeof(key_value));
        } else {
            free(table->data[index]->key);
            free(table->data[index]->value);
        }

        table->data[index]->key = strdup(key);
        table->data[index]->value = strdup(value);
    }
}

void check_address(void *addr) {
    if (!addr) {
        printf("Unable to assign memory\n");
        exit(EXIT_FAILURE);
    }
}

void print_table(hash_table *table) {
    int count = 0;

    for (int i = 0; i < table->size; ++i) {
        if (table->data[i] != NULL) {
            printf("%d : %d => %s : %s\n", ++count, i, table->data[i]->key, table->data[i]->value);
        }
    }
    printf("================\n");
}

char *get(hash_table *table, char *key) {
    int index = hash(key, table->size);
    int original_index = index;

    while (table->data[index] != NULL) {
        if (!strcmp(table->data[index]->key, key)) {
            return table->data[index]->value;
        }

        index = (index + 1) % table->size;
        if (index == original_index) {
            return NULL;
        }
    }

    return NULL;
}


void destroy_table(hash_table* table) {

    for(int i = 0; i < table->size; ++i) {
        if (table->data[i]) {
            free(table->data[i]->key);
            free(table->data[i]->value);
            free(table->data[i]);
        }
    }

    free(table->data);
    free(table);
}

void delete(hash_table *table, char *key) {
    int index = hash(key, table->size);
    int original_index = index;

    while (table->data[index]) {
        if (!strcmp(table->data[index]->key, key)) {
            free(table->data[index]->value);
            free(table->data[index]->key);

            table->data[index]->key = strdup(kDummy);
            table->data[index]->value = strdup("");

            return;
        }

        index = (index + 1) % table->size;
        if (index == original_index)
            return;
    }
}
