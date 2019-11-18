#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int number_of_bits(int n) {
    return (int) log2(n) + 1;
}

void bin(unsigned n) {
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}


void print_page_table(unsigned int *table, int size) {
    printf("---\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", i);
        bin(table[i]);
    }
    printf("---\n");
}


int main() {

    FILE *file;


    int frame_sizes[] = {10, 50, 100};
//    int frame_sizes[] = {10};
    int page_table_ages = 31;
    if (page_table_ages > 31) {
        page_table_ages = 31;
    }

    for (int j = 0; j < 3; ++j) {
        int frame_size = frame_sizes[j];


        unsigned int counters[2][frame_size];
        memset(counters, 0, sizeof(unsigned int) * 2 * frame_size);


        int hit = 0;
        int miss = 0;
        int new_page;
        file = fopen("input.txt", "r");
        while (!feof(file)) {
            fscanf(file, "%d", &new_page);

            int temp = -1;
            int min_index = 0;

            for (int i = 0; i < frame_size; i++) {
                if (counters[0][i] == new_page) {
                    temp = i;
                    break;
                }

                if (counters[0][i] == 0) {
                    min_index = i;
                } else if (counters[1][i] < counters[1][min_index]) {
                    min_index = i;
                }
            }

            for (int i = 0; i < frame_size; ++i) {
                counters[1][i] >>= 1;
            }


            if (temp == -1) {
                miss++;
                counters[0][min_index] = new_page;
                counters[1][min_index] = 1 << page_table_ages;
            } else {
                hit++;
                counters[1][temp] += (1 << page_table_ages);
            }
        }
        printf("---^---\n");
        printf("frame size %d\n", frame_size);
        printf("hit rate: %d\n", hit);
        printf("miss rate: %d\n", miss);
        printf("hit/miss rate: %f\n", (double) hit / (miss + hit));
        fclose(file);


    }
    return 0;
}

/*
 *
    ---^---
    frame size 10
    hit rate: 11
    miss rate: 990
    hit/miss rate: 0.010989
    ---^---
    frame size 50
    hit rate: 54
    miss rate: 947
    hit/miss rate: 0.053946
    ---^---
    frame size 100
    hit rate: 98
    miss rate: 903
    hit/miss rate: 0.097902
*/


