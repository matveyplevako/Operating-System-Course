#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int random_stream = open("/dev/random", O_RDONLY);

    char string[20];
    printf("read %ld bytes\n", read(random_stream, string, 20));
    close(random_stream);

    int output;

    if ((output = open("ex1.txt", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE)) == -1) {
        printf("Cannot open file.\n");
        exit(1);
    }

    printf("write %ld bytes\n", write(output, string, 20));


    return 0;
}

/*
 read 20 bytes
 write 20 bytes
*/

