#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int a[], int n) {
    for (int i = n-1; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    bubble_sort(a, n);

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}
