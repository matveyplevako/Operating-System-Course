#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tree(int n);
void stairs(int n);
void mount(int n);
void rectangle(int n, int k);

/*
 * 1 - tree
 * 2 - stairs
 * 3 - mount
 * 4 - rectangle
 */
int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        printf("Wrong number of arguments\n");
        return 0;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    if (n == 1) {
        tree(m);
    } else if (n == 2) {
        stairs(m);
    } else if (n == 3) {
        mount(m);
    } else if (n == 4 && argc == 4) {
        int k = atoi(argv[3]);
        rectangle(m, k);
    } else {
        printf("Select appropriate method");
    }

    return 0;
}

void tree(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j)
            printf("%c", ' ');

        for (int j = 0; j <= i * 2; ++j)
            printf("%c", '*');

        printf("%c", '\n');
    }
}

void stairs(int n) {
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j <= i; ++j)
            printf("%c", '*');

        printf("%c", '\n');
    }
}

void mount(int n) {
    for (int i = 0; i < n/2; ++i) {

        for (int j = 0; j <= i; ++j)
            printf("%c", '*');

        printf("%c", '\n');
    }
    for (int i = n/2 + (n % 2); i > 0; i--) {

        for (int j = 0; j < i; ++j)
            printf("%c", '*');

        printf("%c", '\n');
    }
}

void rectangle(int n, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; j++)
            printf("%c", '*');

        printf("%c", '\n');
    }
}

