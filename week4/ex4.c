#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

#define BUFFER_SIZE 1024

int pids[BUFFER_SIZE];
int pid_size = 0;

int main(int argc, char *argv[]) {
    char buf[BUFFER_SIZE];
    printf("started, type exit to finish terminal\n");
    while (1) {
        fgets(buf, BUFFER_SIZE - 1, stdin);
        if (strncmp(buf, "exit\n", 5) == 0) {
            for (int i = 0; i < pid_size; ++i) {
                wait(&pids[i]);
            }
            break;
        } else {
            int pid = fork();
            if (pid == 0) {
                system(buf);
                break;
            } else {
                pids[pid_size++] = pid;
            }
        }
    }


    return 0;
}
