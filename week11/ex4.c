#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main() {
    int file_1 = open("ex1.txt", O_RDONLY);
    int file_2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IWUSR);
    struct stat i_stat;
    fstat(file_1, &i_stat);

    ftruncate(file_2, i_stat.st_size);


    char *i_mapped = (char *) mmap(NULL, (size_t) i_stat.st_size, PROT_READ, MAP_PRIVATE, file_1, 0);
    char *o_mapped = (char *) mmap(NULL, (size_t) i_stat.st_size, PROT_WRITE, MAP_SHARED, file_2, 0);

    memcpy(o_mapped, i_mapped, i_stat.st_size);

    munmap(i_mapped, (size_t) i_stat.st_size);
    munmap(o_mapped, (size_t) i_stat.st_size);

    close(file_1);
    close(file_2);

    return 0;
}
