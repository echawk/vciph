#include <string.h>
#include <stdlib.h>

#include "reverse_string.h"

char *reverse_string(char *str) {
    /* allocate for a temporary string; will be freed */
    /* can use a single char */
    /*
    char tchar;
    for (int i = 0; i < len / 2; i++) {
        tchar = *str[i];
        *str[i] = *str[len - i];
        *str[len - i] = tchar;
    }
    */
    int len = (int) strlen(str);
    char *tstr = (char *) malloc(sizeof(char) * strlen(str));
    int i; /* Loop iterator */
    if (tstr == NULL)
        exit(EXIT_FAILURE);
    /* save the reversed version of str in tstr */
    for (i = 0; i < len; i++) {
        tstr[i] = (str)[len - 1 - i];
        /* printf("tstr[%d] = %c -- str[%d] = %c\n", i, tstr[i], i, (str)[i]); */
    }
    tstr[len] = '\0';

    return tstr;
}
