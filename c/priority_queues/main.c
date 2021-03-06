#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main() {
    max_heap heap;
    heap.size = 0;
    heap.max_size = MAX_SIZE;

    insert(&heap, 42);
    printf("%d\n", pop_max(&heap));

    insert(&heap, 29);
    insert(&heap, 35);
    insert(&heap, 50);
    insert(&heap, 34);
    insert(&heap, 35);
    insert(&heap, 5);
    insert(&heap, 67);
    insert(&heap, 13);
    insert(&heap, 12);
    insert(&heap, 1995);

    print_heap(&heap);

    pop_max(&heap);
    print_heap(&heap);

    remove_node(&heap, 2);
    print_heap(&heap);

    return 0;
}
