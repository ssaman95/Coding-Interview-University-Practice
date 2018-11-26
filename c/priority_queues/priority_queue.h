#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define MAX_SIZE 15

typedef struct MaxHeap {
    int size;
    int max_size;
    int data[MAX_SIZE];
} max_heap;


void shift_up(max_heap *heap, int i) {
    int temp;
    int par = (i - 1) / 2;

    while (i > 0 && heap->data[i] > heap->data[par]) {
        temp = heap->data[i];
        heap->data[i] = heap->data[par];
        heap->data[par] = temp;

        i = par;
        par = (i - 1) / 2;
    }
}

void shift_down(max_heap *heap, int i) {
    int max = i;
    int left = 2*i + 1;

    if (left < heap->size && heap->data[i] < heap->data[left])
        max = left;

    int right = 2*i + 2;
    if (right < heap->size && heap->data[max] < heap->data[right])
        max = right;

    if (max != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[max];
        heap->data[max] = temp;

        shift_down(heap, max);
    }
}

void insert(max_heap *heap, int p) {
    if (heap->size == heap->max_size) {
        printf("Heap is full\n");
        return;
    }

    heap->data[heap->size] = p;
    shift_up(heap, heap->size);
    ++heap->size;
}

void print_heap(max_heap *heap) {
    for (int i = 0; i < heap->size; ++i) {
        printf("%d ", heap->data[i]);
    }

    printf("\n");
}

int pop_max(max_heap *heap) {
    if (heap->size > 0) {
        int max_value = heap->data[0];
        --heap->size;

        if (heap->size != 0) {
            heap->data[0] = heap->data[heap->size];
            shift_down(heap, 0);
        }

        return max_value;
    } else {
        printf("Empty Heap\n");
        exit(EXIT_FAILURE);
    }
}

int get_max(max_heap *heap) {
    if (heap->size > 0) {
        return heap->data[0];
    }

    printf("Heap is Empty\n");
    exit(EXIT_FAILURE);
}

void remove_node(max_heap *heap, int i) {
    if (i == 0)
        pop_max(heap);

    if (i < heap->size) {
        --heap->size;
        heap->data[i] = heap->data[heap->size];
        shift_down(heap, i);
    }
}

void change_priority(max_heap *heap, int i, int p) {
    int old_p = heap->data[i];

    heap->data[i] = p;

    if (p > old_p)
        shift_up(heap, i);
    else
        shift_down(heap, i);
}


#endif
