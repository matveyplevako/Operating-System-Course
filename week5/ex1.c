#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *myThreadFun(void *tid) {
    printf("Thread %d printed message\n", (int)tid);
    return NULL;
}

int main() {
    int number_of_threads = 5;
    pthread_t thread_id[number_of_threads];
    for (int i = 1; i < number_of_threads+1; ++i) {
        printf("Thread %d created\n", i);
        pthread_create(&thread_id[i], NULL, myThreadFun, (void *)i);
        pthread_join(thread_id[i], NULL);
        printf("Thread %d exited\n", i);
    }

    return 0;
}
