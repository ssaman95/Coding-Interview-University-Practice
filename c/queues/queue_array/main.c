#include <stdio.h>
#include "queue.h"

int main() {
    queue *q = create_queue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);
    printf("...\n");
    enqueue(q, 4);
    enqueue(q, 5);
    print_queue(q);
    enqueue(q, 6);
    dequeue(q);
    print_queue(q);
    dequeue(q);
    enqueue(q, 9);
    enqueue(q, 8);
    print_queue(q);



    return 0;
}
