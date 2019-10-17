#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int number_of_bits(int n) {
    return (int) log2(n) + 1;
}


int main() {

    FILE *file;


    int frame_sizes[] = {10, 50, 100};

    for (int j = 0; j < 3; ++j) {
        int frame_size = frame_sizes[j];


        unsigned int counters[2][frame_size];
        memset(counters, 0, sizeof(unsigned int) * 2 * frame_size);


        int hit = 0;
        int miss = 0;
        int new_page;
        file = fopen("input1.txt", "r");
        while (!feof(file)) {
            fscanf(file, "%d", &new_page);

            int temp = -1;
            int min_age = INT_MAX;
            int min_index = 0;

            for (int i = 0; i < frame_size; i++) {
                if (counters[0][i] == new_page) {
                    temp = i;
                }

                if (counters[1][i] <= min_age) {
                    min_age = counters[1][i];
                    min_index = i;
                }
                counters[1][i] >>= 1;
            }

            if (temp == -1) {
                miss++;
                counters[0][min_index] = new_page;
                counters[1][min_index] = INT_MAX;

            } else {
                hit++;
                counters[1][temp] = counters[1][temp] | (1 << number_of_bits(counters[1][temp]));
            }
        }
        printf("---^---\n");
        printf("frame size %d\n", frame_size);
        printf("hit rate: %d\n", hit);
        printf("miss rate: %d\n", miss);
        printf("hit/miss rate: %f\n", (double) hit / miss);
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
    hit/miss rate: 0.011111
    ---^---
    frame size 50
    hit rate: 36
    miss rate: 965
    hit/miss rate: 0.037306
    ---^---
    frame size 100
    hit rate: 36
    miss rate: 965
    hit/miss rate: 0.037306
    
*/
