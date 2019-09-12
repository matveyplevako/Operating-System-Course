#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
        char cmd[1024];

        while(1) {
                scanf("%s", cmd);
                if (strncmp(cmd, "exit", 5) == 0) break;
                system(cmd);
        }

        return 0;
}
