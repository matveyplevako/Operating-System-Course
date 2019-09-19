#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define FULL 8

int buffer = 0;
int cons_sleep = 0;
int prod_sleep = 0;


void *consumer() {
    while (1) {
        if (cons_sleep) {
            continue;
        }
        while (buffer > 0) {
            buffer--;
        }
        cons_sleep = 1;
        prod_sleep = 0;
    }
}

void *producer() {
    while (1) {
        if (prod_sleep) {
            continue;
        }
        while (buffer < FULL) {
            buffer++;
        }

        prod_sleep = 1;
        cons_sleep = 0;
    }

}

int main(int argc, char *argv[]) {
    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, producer, NULL);
    sleep(5);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    int time = 0;
    while (1) {
        time++;
        if (time % 100000000 == 0) {
            printf("%d\n", buffer);
        }
    }

    return 0;
}
