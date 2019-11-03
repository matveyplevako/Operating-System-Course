#include <stdio.h>
#include <pthread.h>
#include <zconf.h>

#define N 3
#define INTERVAL 1000000

int size = 0;
int buf[N] = {0};

int p_sleep = 0;
int c_sleep = 0;
int t = 0;

void *p(void *args) {
    while (1) {
        while (p_sleep) {
            // DEADLOCK OCCURRED
            if (c_sleep == 1 && p_sleep == 1) {
                return NULL;
            }
        };

        if (size == N) {
            // we can receive signal to wake up after size has been checked 
            // so race condition is met
            p_sleep = 1;
        } else {
            buf[size] = size;
            size++;
            if (size == 1) {
                // waking up consumer just before it goes to sleep causes race condition
                c_sleep = 0;
            }
        }

        if (t % INTERVAL == 0) {
            printf("still running producer\n");
        }
    }

    pthread_exit(0);
}

void *c(void *args) {
    while (1) {
        while (c_sleep) {
            // DEADLOCK OCCURRED
            if (c_sleep == 1 && p_sleep == 1) {
                return NULL;
            }
        };

        if (size == 0) {
            // we can receive signal to wake up after size has been checked 
            // so race condition is met
            c_sleep = 1;
        } else {
            buf[size - 1] = 0;
            size--;
            if (size == N - 1) {
                // waking up producer before it goes to sleep causes race condition
                p_sleep = 0;
            }
        }

        if (t % INTERVAL == 0) {
            printf("still running consumer\n");
        }
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {

    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, p, NULL);
    pthread_create(&consumer_t, NULL, c, NULL);
    while (!(c_sleep == 1 && p_sleep == 1)) {
        t++;
    }
    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    return 0;
}
