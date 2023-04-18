#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

/* 
Matala 2 in Operating systems
 by ilan Souffir and Nerya Rez
*/

int main(int argc, char* argv[]){
    bool verb = false;
    bool frc = false;

    if (argc < 3 || argc > 5) 
    {
        printf("Usage: copy <file1> <file2> [-v] [-f]\n");
        return 1;
    }

    for(int i=3; i<argc; i++)
    {
        if(strcmp(argv[i], "-v")==0)
            verb = true;

        else if (strcmp(argv[i], "-f")==0)
            frc = true;
    }

    if (access(argv[1], F_OK) == -1) {
        printf("The file %s doesn't exist\n", argv[1]);
        return 1;
    }

    if (access(argv[2], F_OK) != -1 && !(strcmp(argv[3], "-f") == 0 || strcmp(argv[4], "-f") == 0)) {
        printf("Target file exists. Use -f flag to force overwrite.\n");
        return 1;
    }
    
}
