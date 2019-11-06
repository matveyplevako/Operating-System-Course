#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <stdlib.h>
#include <memory.h>

#define max_length 10000

int main(int argc, char *argv[]) {

    int mode = O_CREAT | O_WRONLY;

    int i = 1;

    char content[max_length];

    if (read(STDIN_FILENO, content, max_length) == max_length) {
        printf("content exceeded max length");
        exit(-1);
    };

    write(STDOUT_FILENO, content, strlen(content));


    if (getopt(argc, argv, "a") != -1) {
        mode |= O_APPEND;
        i++;
    }

    int size = 0;

    for (; i < argc; i++) {
        int fd;
        if ((fd = open(argv[i], mode, S_IWRITE | S_IREAD)) == -1) {
            printf("Cannot open file.\n");
            exit(1);
        }
        write(fd, content, strlen(content));
        close(fd);
    }

    return 0;
}

