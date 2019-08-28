#include <stdio.h>
#include <string.h>

int main() {
    char name[256];
    printf("Enter line:\n");
    fgets(name, sizeof(name), stdin);
    for (int i = (int) (strlen(name) - 2); i >= 0; i--) {
        printf("%c", name[i]);
    }
    printf("\n");

    return 0;
}

