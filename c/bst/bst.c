#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "bst.h"

bst * create_bst_node(const int value) {
    bst *node = (bst*) malloc(sizeof(bst));
    if (!node) {
        printf("Node can't be created\n");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->lc = NULL;
    node->rc = NULL;

    return node;
}

void insert(bst **rootptr, const  int value) {
    if (!(*rootptr)) {
        bst *node = create_bst_node(value);
        *rootptr = node;
    } else if (value < (*rootptr)->data) {
        insert(&((*rootptr)->lc), value);
    } else if (value > (*rootptr)->data) {
        insert(&((*rootptr)->rc), value);
    } else {
        printf("value already exists in BST\n");
    }
}

bool search(bst *root, const int value) {
    if (!root)
        return false;

    if (value < root->data)
        return search(root->lc, value);
    else if (value > root->data)
        return search(root->rc, value);
    else
        return true;
}

int get_node_count(bst *root) {
    if (!root)
        return 0;

    int l_count = get_node_count(root->lc);
    int r_count = get_node_count(root->rc);

    return 1 + l_count + r_count;
}

void delete_tree(bst *root) {
    if (!root)
        return;

    delete_tree(root->lc);
    delete_tree(root->rc);
    free(root);
    root = NULL;
}

int get_height(bst *root) {
    if (!root)
        return 0;

    return 1 + fmax(get_height(root->lc), get_height(root->rc));
}

int get_min(bst *root) {
    if (!root) {
        printf("Empty tree\n");
        return 0;
    }

    if (!root->lc)
        return root->data;

    return get_min(root->lc);
}

int get_max(bst *root) {
    if (!root) {
        printf("Empty tree\n");
        return 0;
    }

    if (!root->rc)
        return root->data;

    return get_max(root->rc);
}

void remove(bst **rootptr, int key) {
    if (!*rootptr) {
        printf("Key not found\n");
        return;
    } else if (key < (*rootptr)->data) {
        remove(&((*rootptr)->lc), key);
    } else if (key > (*rootptr)->data) {
        remove(&((*rootptr)->rc), key);
    } else {
        if (!(*rootptr)->lc && !(*rootptr)->rc) {
            free(*rootptr);
            *rootptr = NULL;
        } else if (!(*rootptr)->lc) {
            bst *temp = *rootptr;
            *rootptr = (*rootptr)->rc;
            free(temp);
            temp = NULL;
        } else if (!(*rootptr)->rc) {
            bst *temp = *rootptr;
            *rootptr = (*rootptr)->lc;
            free(temp);
            temp = NULL;
        } else {
            int max_in_lst = get_max((*rootptr)->lc);
            (*rootptr)->data = max_in_lst;
            remove(&((*rootptr)->lc), max_in_lst);
        }
    }
}

bool is_bst(bst *root) {
    if (!root)
        return true;

    if (root->lc) {
        if (root->lc->data > root->data)
            return false;

        if (!is_bst(root->lc))
            return false;
    }

    if (root->rc) {
        if (root->rc->data < root->data)
            return false;

        if (!is_bst(root->rc))
            return false;
    }

    return true;
}
