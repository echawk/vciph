#include <string.h>
#include <stdlib.h>

#include "vigenere.h"

#ifdef DEBUG
#include <stdio.h>
#endif

char *ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getIndexOfChar(char *str, char c) {
    /* 'strchr(str, c)' -- get the mem address of the character
    *  '- str' -- subtract the memory address of the string
    */
    /* This is the current fix that I have come up with,
       * if the character is not in the list (strchr returns
       * NULL), the the index that is returned is a -1. I think
       * this is a fair compromise, so that we don't fail here.
    */
    char *search_char = strchr(str, c);
    if (search_char == NULL)
        return -1;
    return (int) (search_char - str); /* here is our index */
}

/* key and message must be in uppercase before this call */
char *translate_string(char *key, char *message, char mode) {

    /* FIXME: there is currently a bug with the overflow implementation.
       When decrypting with a key that is either too small (A or B), or
       with a key that causes an overflow (X, Y, or Z), the decryption
       step doesn't work. I can confirm that the encryption step does work
       as my previous implemenation yields the same results.
    */

    /* allocate enough memory for the translated string */
    char *translated_str = (char *) malloc(sizeof(char) * strlen(message));
    if (translated_str == NULL)
        exit(EXIT_FAILURE);

    int i;
    int num = 0;
    int key_count = 0;

    for (i = 0; i < strlen(message); i++) {
        /* get the index of the current letter in the message in the alphabet */
        num = getIndexOfChar((char *) ALPHABET, message[i]);
#ifdef DEBUG
        printf("num = %d, ", num);
        printf("key[%d] = %d", key_count, key[key_count]);
#endif
        if (num < 0)
            exit(EXIT_FAILURE);
        switch (mode) {
        /* encrypt */
        case 'e':
            num += getIndexOfChar((char *)ALPHABET, key[key_count]);
            break;
        /* decrypt */
        case 'd':
            num -= getIndexOfChar((char *)ALPHABET, key[key_count]);
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }

#ifdef DEBUG
        printf("num = %d, ", num);
#endif

        /* if negative, wrap around*/
        if (num < 0) {
            num = strlen(ALPHABET) + num;
        } else if (num > strlen(ALPHABET)) {
            num = num % strlen(ALPHABET);
        }

        translated_str[i] = ALPHABET[num];

        key_count++;
        if (key_count == strlen(key)) {
            key_count = 0;
        }
        /*FIXME: if the character is not in the string, don't change it */
    }

    return translated_str;
}

/*printf("%d + %d\n", num , getIndexOfChar((char *)ALPHABET, key[key_count])); */
/*printf("%d - %d\n", num , getIndexOfChar((char *)ALPHABET, key[key_count])); */
/*printf("translated_str[%d] = %c -- message[%d] = %c\n", i, ALPHABET[num], i, message[i]); */
/*printf("key_count is strlen\n"); */
