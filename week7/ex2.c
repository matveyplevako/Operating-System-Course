#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *a = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", a[i]);
    }

    free(a);
}

