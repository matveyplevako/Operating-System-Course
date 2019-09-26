#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LEN 100

int main() {
    int pipe_ds[2];
    char *string1 = "Message to be transferred";
    char *string2 = (char *)malloc(STR_MAX_LEN * sizeof(char));

    if (pipe(pipe_ds) == -1){
        perror("pipe failed");
        return -1;
    }

    printf("length of string 1: %ld\n", strlen(string1));
    printf("length of string 2: %ld\n", strlen(string2));

    printf("content of string 1: %s\n", string1);
    printf("content of string 2: %s\n\n", string2);

    int read_id = pipe_ds[0];
    int write_id = pipe_ds[1];

    write(write_id, string1, strlen(string1)+1);

    close(write_id);

    read(read_id, string2, STR_MAX_LEN);

    printf("length of string 1: %ld\n", strlen(string1));
    printf("length of string 2: %ld\n", strlen(string2));

    printf("content of string 1: %s\n", string1);
    printf("content of string 2: %s\n\n", string2);

    close(read_id);

    free(string2);
    return 0;
}
/*
length of string 1: 17
length of string 2: 0
Message from pipe
length of string 1: 17
length of string 2: 17
 */
