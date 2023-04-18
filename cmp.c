#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* 
Matala 2 in Operating systems
 by ilan Souffir and Nerya Rez
*/
int main(int argc, char *argv[]) 
{

    bool verb = false;
    bool ign = false;

    if (argc < 3 || argc > 5) 
    {
        printf("Usage: cmp <file1> <file2> [-v] [-i]\n");
        exit(1);
    }

    for(int i=3; i<argc; i++)
    {
        if(strcmp(argv[i], "-v")==0)
            verb = true;

        else if (strcmp(argv[i], "-i")==0)
            ign = true;
    }

    FILE *f1 = fopen(argv[1], "r");
    
    if (f1 == NULL)
    {
        printf("File1 error");
        exit(1);
    }

    FILE *f2 = fopen(argv[2], "r");

    if (f2 == NULL)
    {
        printf("File2 error");
        exit(1);
    }

    fseek(f1, 0, SEEK_END);
    fseek(f2, 0, SEEK_END);

    long f1_len = ftell(f1);
    long f2_len = ftell(f2);

    rewind(f1);
    rewind(f2);

    if(f1_len != f2_len)
    {
        if(verb) printf("distinct\n");
        return 1;
    }

    char c1, c2;
    while ((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF)
    {
        if(ign)
        {
           c1 = tolower(c1);
           c2 = tolower(c2);
        }

        if (c1 != c2))
        {
            if(verb) printf("distinct\n"); 
            return 1; 
        }
    }
    if(verb) printf ("equal\n");
    
    fclose(p1);
    fclose(p2);
 
    return 0;
}
