#include<stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>

void handle_sigkill(int sig_no) {
    printf("caught SIGKILL %d\n", sig_no);
    exit(0);
}

void handle_sigstop(int sig_no) {
    printf("caught SIGSTOP %d\n", sig_no);
    exit(0);
}

void handle_sigurs1(int sig_no) {
    printf("caught SIGUSR1 %d\n", sig_no);
    exit(0);
}

int main() {
    signal(SIGKILL, handle_sigkill);
    signal(SIGSTOP, handle_sigstop);
    signal(SIGUSR1, handle_sigurs1);


    while (1)
    {
//        printf("hello world\n");
        sleep(1);
    }
    return 0;
}

/*
 matvey$ ./ex4&
[1] 24394
matvey$ kill -SIGUSR1 %1
caught SIGUSR1 30
[1]+  Done                    ./ex4
matvey$


 OUTPUT:
 caught SIGUSR1 30
[1]+  Done                    ./ex4
 
 the first line shows that custom handler caught SIGUSR1 signal and printed message
 the second line shows what process was finished and what command started it

 */
