#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a, b;
    printf("Enter two numbers:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    swap(&a, &b);

    printf("First number: %d\nSecond number: %d\n", a, b);
    return 0;
}

