#include <stdio.h>
#include <zconf.h>

int main() {

        int c = fork();
        int k = getpid();
        if (c == 0) {
                printf(Hello from child [PID - %d]n,  k);
        } else {
                printf(Hello from parent [PID - %d]n, k);
        }
        return 0;
}

/*

 parent process continues execution immediately and child starts shortly after


 1 execution
Hello from parent [PID - 13201]
2 execution
Hello from child [PID - 13202]
Hello from parent [PID - 13203]
Hello from child [PID - 13204]
3 execution
Hello from parent [PID - 13205]
Hello from child [PID - 13206]
4 execution
Hello from parent [PID - 13207]
Hello from child [PID - 13208]
5 execution
Hello from parent [PID - 13209]
Hello from child [PID - 13210]
6 execution
Hello from parent [PID - 13211]
7 execution
Hello from child [PID - 13212]
Hello from parent [PID - 13213]
8 execution
Hello from child [PID - 13214]
Hello from parent [PID - 13215]
9 execution
Hello from child [PID - 13216]
Hello from parent [PID - 13217]
10 execution
Hello from child [PID - 13218]
Hello from parent [PID - 13219]
Hello from child [PID - 13220]
 */

