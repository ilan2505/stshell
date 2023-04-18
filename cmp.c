#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

/* 
Matala 2 in Operating systems
 by ilan Souffir and Nerya Rez
*/

int main(int argc, char* argv[]) {
    int fd1, fd2, n;
    char buffer[1024];

    if (argc < 3) {
        printf("Usage: copy <file1> <file2> [-v] [-f]\n");
        return 1;
    }

    if (access(argv[1], F_OK) == -1) {
        printf("File %s does not exist\n", argv[1]);
        return 1;
    }

    if (access(argv[2], F_OK) != -1 && !strcmp(argv[3], "-f") == 0) {
        printf("Target file exists. Use -f flag to force overwrite.\n");
        return 1;
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0666);

    if (fd1 == -1 || fd2 == -1) {
        printf("General failure\n");
        return 1;
    }

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    if (strcmp(argv[3], "-v") == 0) {
        printf("Success\n");
    }

    return 0;
}

