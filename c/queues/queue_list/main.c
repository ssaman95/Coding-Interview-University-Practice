#include <stdio.h>
#include "queue.h"

int main() {
    queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    print(q);

    dequeue(q);

    print(q);

    printf("DONE\n");

    return 0;
}
