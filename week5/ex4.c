#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define STACK_SIZE 100000

long stack[STACK_SIZE] = {0};
int size = 0;

pthread_mutex_t mutex;


void *lcm(void *args) {

    while (1) {

        // all access to the shared variable must be inside the critical region
        pthread_mutex_lock(&mutex);
        // less than 2 numbers left
        // if another thread will put numbers after this check, it will process them by itself
        if (size < 2) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        long m = stack[--size];
        long n = stack[--size];
        pthread_mutex_unlock(&mutex);


        long result;
        if (n > m) {
            result = n;
        } else {
            result = m;
        }

        while (result <= n * m) {
            if (result % n == 0 && result % m == 0) {
                break;
            }
            result++;
        }

        pthread_mutex_lock(&mutex);
        stack[size++] = result;
        pthread_mutex_unlock(&mutex);
    }
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("The program must be given exactly 2 arguments.\n");
        return -1;
    }

    FILE *input = fopen(argv[1], "r");
    while (!feof(input)) {
        int number;
        fscanf(input, "%d", &number);
        if (number != 0) {
            stack[size++] = number;
        }
    }
    fclose(input);

    int thread_count = atoi(argv[2]);
    pthread_t threads[thread_count];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < thread_count; ++i) {
        pthread_create(&threads[i], NULL, lcm, NULL);
    }

    for (int i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("%ld\n", stack[0]);
}
