#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    DIR *tmp = opendir("tmp");
    struct dirent *dir = readdir(tmp);
    struct stat file;
    char cmd[256];
    system(cmd);

    while (dir != NULL) {
        if (dir->d_name[0] != '.') {
            char name[256];
            sprintf(name, "./tmp/%s", dir->d_name);
            stat(name, &file);
            if (file.st_nlink >= 2) {
                sprintf(cmd, "echo \"found %lc links in %s\" >> ex4.txt", name, file.st_nlink);
                system(cmd);
            }

        }
        dir = readdir(tmp);
    }
    return 0;
}
