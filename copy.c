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

    FILE* f1 = fopen(argv[1], "rb");

    if(!f1)
    {
        if(verb)
        {
            printf ("general failure\n");
        }
        return 1;
    }

    if (access(argv[2], F_OK) != -1 && ! frc)
    {
        if(verb)
        {
            printf("Target file exists. Use -f flag to force overwrite.\n");
        }
        fclose(f1);
        return 1;
    }

    else{
        
        FILE* f2 = fopen(argv[2], "wb");
        
        if(!f2)
        {
            if(verb) printf ("general failure\n");
            return 1;
        }

        char buffer[1024];
        size_t bytes_read;

        while ((bytes_read = fread(buffer, 1, sizeof(buffer), f1)) > 0)
        {

        fwrite(buffer, 1, bytes_read, f2);

        } 

       fclose(f2); 
       if(verb) printf("sucess\n");
    }
   
   fclose(f1);
   return 0;
} 

