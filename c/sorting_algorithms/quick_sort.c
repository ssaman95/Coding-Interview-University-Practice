#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int partition(int a[], int lo, int hi) {
    int pivot = a[hi];
    int p = 0;

    for (int i = 0; i < hi; ++i) {
        if (a[i] <= pivot) {
            swap(a, i, p);
            ++p;
        }
    }

    swap(a, p, hi);

    return p;
}

void quicksort(int a[], int lo, int hi) {
    if (hi > lo) {
        int p = partition(a, lo, hi);
        quicksort(a, lo, p-1);
        quicksort(a, p+1, hi);
    }
}


int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(sizeof(int) * n);
    if (!a)
        EXIT_FAILURE;

    printf("Enter elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    quicksort(a, 0, n-1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}
