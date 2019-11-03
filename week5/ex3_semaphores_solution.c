#include <stdio.h>
#include <pthread.h>
#include <zconf.h>

#define N 100
#define MESSAGES 10000
#define PRODUCERS 5
#define CONSUMERS 30
#define TIMEOUT 1000000000

int size = 0;
int buf[N] = {0};
int result[MESSAGES] = {0};

int t = 0;

int messages_left = MESSAGES;
int received_messages = 0;

pthread_mutex_t mutex, produce_mutex, consume_mutex;
pthread_cond_t P;
pthread_cond_t C;

int produce_item() {
    pthread_mutex_lock(&produce_mutex);
    int result = messages_left--;
    pthread_mutex_unlock(&produce_mutex);
    return result;
}


void *producer(void *args) {
    while (1) {

        int item = produce_item();
        if (item <= 0) {
            return NULL;
        }

        pthread_mutex_lock(&mutex);
        while (size == N) {
            pthread_cond_wait(&P, &mutex);
        }
        buf[size] = item;
        size++;
        if (size == 1) {
            pthread_cond_broadcast(&C);
        }
        pthread_mutex_unlock(&mutex);

        if (t > TIMEOUT) {
            return NULL;
        }
    }
}

void consume(int item) {
    for (int i = 1; i < MESSAGES; ++i) {
        // heavy computing simulation
        for (int j = 0; j < 5; ++j) {
            item = item * item / item;
        }
    }
    pthread_mutex_lock(&consume_mutex);
    result[received_messages++] = item;
    pthread_mutex_unlock(&consume_mutex);
}

void *consumer(void *args) {
    while (1) {

        pthread_mutex_lock(&mutex);

        while (size == 0) {
            pthread_cond_wait(&C, &mutex);
        }

        int item = buf[--size];
        buf[size] = 0;

        if (size == N - 1) {
            pthread_cond_broadcast(&P);
        }

        pthread_mutex_unlock(&mutex);
        consume(item);

        if (t > TIMEOUT) {
            return NULL;
        }
    }
}

int main(int argc, char *argv[]) {


    pthread_t producer_t[PRODUCERS], consumer_t[CONSUMERS];

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&produce_mutex, NULL);
    pthread_mutex_init(&consume_mutex, NULL);
    pthread_cond_init(&C, NULL);
    pthread_cond_init(&P, NULL);

    for (int i = 0; i < PRODUCERS; ++i) {
        pthread_create(&producer_t[i], NULL, producer, NULL);
    }

    for (int i = 0; i < CONSUMERS; ++i) {
        pthread_create(&consumer_t[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < PRODUCERS; ++i) {
        pthread_join(producer_t[i], NULL);
    }


    while (received_messages != MESSAGES);
    printf("len: %d\n", received_messages);
//    for (int j = 0; j < received_messages; ++j) {
//        printf("%d ", result[j]);
//    }
    printf("\n");


    return 0;
}
