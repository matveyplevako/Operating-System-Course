#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    char buff[6];
    setvbuf(stdout, buff, _IOLBF, 6);

    printf("%c", 'H');
    sleep(1);

    printf("%c", 'e');
    sleep(1);


    printf("%c", 'l');
    sleep(1);


    printf("%c", 'l');
    sleep(1);


    printf("%c", 'o');

    return 0;
}
