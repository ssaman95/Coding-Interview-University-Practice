#include "bst.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    bst *root = NULL;
    
    assert(is_bst(root));

    insert(&root, 20);
    assert(is_bst(root));
    insert(&root, 10);
    assert(is_bst(root));
    insert(&root, 40);
    insert(&root, 30);
    insert(&root, 60);
    insert(&root, 70);
    assert(is_bst(root));
    insert(&root, 50);
    insert(&root, 5);
    assert(is_bst(root));

    assert(get_min(root) == 5);
    assert(get_max(root) == 70);

    assert(root->data == 20);
    assert(get_node_count(root) == 8);
    assert(get_height(root) == 4);
    
    assert(root->rc->data == 40);
    remove(&root, 40);
    assert(root->rc->data == 30);

    // Dummy fake bst to check is_bst
    bst *dummy = create_bst_node(50);
    insert(&dummy, 40);
    insert(&dummy, 60);
    insert(&dummy, 45);
    dummy->lc->rc->data = 20;


    assert(!is_bst(dummy));

    return 0;
}

