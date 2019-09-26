#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void handle_sigstop(int sig_no) {
    exit(0);
}


int main(void) {
    int pipe_ds[2];
    if (pipe(pipe_ds) == -1) {
        printf("pipe failed\n");
        return -1;
    }

    int read_id = pipe_ds[0];
    int write_id = pipe_ds[1];

    printf("the first fork was done\n");
    int child1_pid = fork();

    if (child1_pid == 0) {
        // child1
        int received_pid;
        close(write_id);
        read(read_id, &received_pid, sizeof(int));
        printf("child1: received pid: %d\n", received_pid);
        close(read_id);

        sleep(2);
        puts("child1: sent SIGSTOP to child2");
        kill(received_pid, SIGSTOP);

        puts("child1: sent SIGTERM to child2");

        kill(received_pid, SIGTERM);
    } else {
        printf("the second fork was done\n");
        int child2_pid = fork();
        if (child2_pid == 0) {
            // child2
            while (1){
                printf("child 2 is alive\n");
                sleep(1);
            }
        } else {
            //parent
            printf("parent: childs are %d %d\n", child1_pid, child2_pid);
            printf("parent: sent pid: %d\n", child2_pid);
            write(write_id, &child2_pid, sizeof(int));
            close(write_id);

            int child2_status;
            printf("parent is waiting for child2 state to change\n");
            waitpid(child2_pid, &child2_status, 0);
            printf("parent: child2 changed state\n");
        }
    }
    return 0;
}
