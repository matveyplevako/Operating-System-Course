
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define size 10 * 1024 * 1024

int main() {
    for (int i = 0; i < 10; i++) {
        char *a = malloc(size);
        memset(a, 0, size);
        struct rusage *usage = (struct rusage*) malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        printf("ru_ixrss: %ld, ru_idrss: %ld, ru_isrss: %ld, ru_minflt: %ld, ru_majflt: %ld\n", usage->ru_ixrss,
               usage->ru_idrss, usage->ru_isrss, usage->ru_minflt, usage->ru_majflt);
        sleep(1);
    }

    return 0;
}

/*
 ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 2873, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 5436, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 7997, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 10557, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 13120, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 15681, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 18241, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 20801, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 23363, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 25924, ru_majflt: 0

 */

