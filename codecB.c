#include <ctype.h>
#include <stdio.h>
#include "codec.h"

/* 
Matala 2 in Operating systems
 by ilan Souffir and Nerya Rez
*/

void encode(char *input) {

    char output[1024] = {'\0'};
    char * p = output;

    while (*input) {
        *p = *input + 3;
        input++;
        p++;
    }
    puts(output);
}

void decode(char *input) {

    char output[1024] = {'\0'};
    char * p = output;

    while (*input) {
        *p = *input - 3;
        input++;
        p++;
    }
    puts(output);
}
