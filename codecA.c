
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
        if (isupper(*input)) {
            *p = tolower(*input);
        } else if (islower(*input)) {
            *p = toupper(*input);
        } else {
            *p = *input;
        }
        input++;
        p++;
    }
    puts(output);
}

void decode(char *input) {
    encode(input);
}

