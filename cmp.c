#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* 
Matala 2 in Operating systems
 by ilan Souffir and Nerya Rez
*/
int main(int argc, char *argv[]) {
    bool verb = false;
    bool ign = false;

    if (argc < 3 || argc > 5) {
        printf("Usage: cmp <file1> <file2> [-v] [-i]\n");
        exit(1);
    }

    for(int i=3; i<argc; i++){
        if(strcmp(argv[i], "-v")==0)
            verb = true;
        else if (strcmp(argv[i], "-i")==0)
            ign = true;
    }
    printf("argv[3]== %s\n", argv[3]);
    printf("argv[4]== %s\n", argv[4]);

    FILE *f1 = fopen(argv[1], "r");
    if (f1 == NULL) {
        printf("File1 error");
        exit(1);
    }

    FILE *f2 = fopen(argv[2], "r");
    if (f2 == NULL) {
        printf("File2 error");
        exit(1);
    }
}