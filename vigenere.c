#include <string.h>
#include <stdlib.h>

#include "vigenere.h"

char *ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getIndexOfChar(char *str, char c) {
    /* 'strchr(str, c)' -- get the mem address of the character
    *  '- str' -- subtract the memory address of the string
    */
    /* FIXME: make the function return null if the character is not in the string */
    return (int) (strchr(str, c) - str); /* here is our index */
}

/* key and message must be in uppercase before this call */
char *translate_string(char *key, char *message, char mode) {
    char *translated_str = (char *) malloc(sizeof(char) * strlen(message));
    int num = 0;
    int key_count = 0;
    for (int i = 0; i < strlen(message); i++) {
        /* get the index of the current letter in the message in the alphabet */
        num = getIndexOfChar((char *) ALPHABET, message[i]);

        /* encrypt */
        if (mode == 'e') {
            num += getIndexOfChar((char *)ALPHABET, key[key_count]);
            /* decrypt */
        } else if (mode == 'd') {
            num -= getIndexOfChar((char *)ALPHABET, key[key_count]);
        }

        /* if over 26, wrap back around */
        num %= strlen(ALPHABET);

        translated_str[i] = ALPHABET[num];

        key_count++;
        if (key_count == strlen(key)) {
            key_count = 0;
        }
        /*FIXME: if the character is not in the string, don't change it */
    }

    return translated_str;
}

//printf("%d + %d\n", num , getIndexOfChar((char *)ALPHABET, key[key_count]));
//printf("%d - %d\n", num , getIndexOfChar((char *)ALPHABET, key[key_count]));
//printf("translated_str[%d] = %c -- message[%d] = %c\n", i, ALPHABET[num], i, message[i]);
//printf("key_count is strlen\n");
