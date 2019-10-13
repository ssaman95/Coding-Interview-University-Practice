#ifndef BST_H
#define BST_H

typedef struct bst_nodes {
    int data;
    struct bst_nodes *lc;
    struct bst_nodes *rc;
} bst;

bst * create_bst_node(const int value);

void insert(bst** rootptr, const int value);

bool search(bst* root, const int key);

int get_node_count(bst *root);

void delete_tree(bst *root);

int get_height(bst *root);

int get_min(bst *root);

int get_max(bst *root);

bool is_bst(bst *root);

void remove(bst **rootptr, int key);


#endif
