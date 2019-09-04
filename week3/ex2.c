#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                sorted = 0;
                int c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
        }
    }
}

int main() {
    int n;
    printf("input an array size:\n");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("input %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    printf("sorted array:\n");
    for (int j = 0; j < n-1; ++j) {
        printf("%d, ", a[j]);
    }
    printf("%d\n", a[n-1]);
    free(a);
    return 0;
}
