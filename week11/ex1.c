#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define st "This is a nice day"

int main() {

    int file = open("ex1.txt", O_RDWR | O_CREAT, S_IWRITE);

    ftruncate(file, (off_t) strlen(st));

    char *address = (char *) mmap(NULL, strlen(st), PROT_WRITE, MAP_SHARED, file, 0);

    strcpy(address, st);
    sprintf(address, "%s", st);

    munmap(address, strlen(st));
    close(file);
    return 0;
}
