#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
    int child_pid = fork();
    if (child_pid == 0) {
        //Child
        while (1) {
            printf("I am alive\n");
            sleep(1);
        }
    } else {
        //Parent
        sleep(10);
        kill(child_pid, SIGTERM);
        wait(NULL);
    }
    return 0;
}
