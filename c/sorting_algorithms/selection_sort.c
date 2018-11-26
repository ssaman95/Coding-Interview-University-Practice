#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int a[], int n) {
    for(int i = 0; i < n-1; ++i) {
        int min = i;

        for (int j = i+1; j < n; ++j) {
            if (a[j] < a[min])
                min = j;
        }

        if (i != min)
            swap(&a[min], &a[i]);
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

    selection_sort(a, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}
