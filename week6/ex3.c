#include<stdio.h>
#include <unistd.h>
#include<signal.h>

void handle_sigint(int sig_no) {
    printf("caught %d\n", sig_no);
}

int main() {
    signal(SIGINT, handle_sigint);
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }
    return 0;
}
