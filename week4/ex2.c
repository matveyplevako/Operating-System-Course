#include <stdio.h>
#include <zconf.h>

int main() {

        printf("%d\n", getpid());

        for (int i = 0; i < 5; ++i) {
                sleep(5);
        	printf("%d\n", getpid());
                fork();
        }
        return 0;
}


/*

 Each process creates 2 more


 -+= 22077 matvey ./ex2
 |-+- 22078 matvey ./ex2
 | |-+- 22087 matvey ./ex2
 | | |-+- 22110 matvey ./ex2
 | | | \--- 22131 matvey ./ex2
 | | \--- 22132 matvey ./ex2
 | |-+- 22109 matvey ./ex2
 | | \--- 22130 matvey ./ex2
 | \--- 22129 matvey ./ex2
 |-+- 22088 matvey ./ex2
 | |-+- 22111 matvey ./ex2
 | | \--- 22133 matvey ./ex2
 | \--- 22134 matvey ./ex2
 |-+- 22112 matvey ./ex2
 | \--- 22135 matvey ./ex2
 \--- 22136 matvey ./ex2

*/
