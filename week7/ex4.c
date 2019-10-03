#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a)<(b))?(a):(b))

void *better_realloc(void *ptr, int prev_size, int size) {
    if (size > 0) {
        void *new_ptr = (void *) malloc(size);
        for (int i = 0; i < min(prev_size, size); i++) {
            *((char *) new_ptr + i) = *(i + (char *) ptr);
        }
        free(ptr);
        return new_ptr;
    }
    free(ptr);
    return NULL;
}

int main() {
    int N;

    scanf("%d", &N);

    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", *(a + i));
    }
    printf("%c", '\n');

    scanf("%d", &N);

    a = better_realloc(a, N * sizeof(int), N * sizeof(int));

    for (int i = 0; i < N; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    free(a);
}

