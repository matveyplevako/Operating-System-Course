#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        return 0;
    }

    int n = atoi(argv[1]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j)
            printf("%c", ' ');

        for (int j = 0; j <= i * 2; ++j)
            printf("%c", '*');

        printf("%c", '\n');
    }

    return 0;
}

