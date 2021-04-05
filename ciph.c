#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_string.h"
#include "vigenere.h"

#define true 1
#define false 0

int main(int argc, char *argv[]) {

    char *key = NULL;
    char *message = NULL;
    char *outFilename = NULL;
    /* char *inFilename = NULL; */

    int dec = false;
    int enc = false;
    int rev = false;

    /* if we have options to parse and the first character
        is a '-', switch on the second character of the
        argument. argv[1][2] is the rest of the argument.
        Flags k, m, and o require text immediately following
        the flag.
    */
    while ((argc > 1) && (argv[1][0] == '-')) {
        switch (argv[1][1]) {
        case 'e':
            enc = true;
            dec = false;
            break;
        case 'd':
            enc = false;
            dec = true;
            break;
        case 'k':
            key = &argv[1][2];
            break;
        case 'r':
            rev = true;
            break;
        case 'm':
            message = &argv[1][2];
            break;
        case 'o':
            outFilename = &argv[1][2];
            break;
            /*
        case 'f':
            inFilename = &argv[1][2];
            break;
            */
        case 'h':
            break;
        default:
            break;
        }
        ++argv;
        --argc;
    }

    if ((enc == false) && (dec == false)) {
        printf("Need to provide '-e' or '-d'. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    if (key == NULL)
        exit(EXIT_FAILURE);


    FILE *ofp = NULL;
    if (outFilename == NULL) {
        ofp = stdout;
    } else {
        ofp = fopen(outFilename, "w");
        if (ofp == NULL)
            exit(EXIT_FAILURE);
    }
    /*
    FILE *ifp = NULL;
    if (inFilename != NULL) {
        ifp = fopen(inFilename, "r");
        if (ifp) {
            fseek(ifp, 0, SEEK_END);
            long len = ftell(ifp);
            fseek (ifp, 0, SEEK_SET);
            message = malloc(len);
            if (message) {
                fread(message, 1, len, ifp);
            }
        }
        fclose(ifp);
    }
    */
    if (message == NULL)
        exit(EXIT_FAILURE);
    /*
    printf("%s\n", message);
    printf("%s\n", reverse_string(message));
    */
    if (rev) {
        if (enc)
            fprintf(ofp, "%s\n", translate_string(key, reverse_string(message), 'e'));

        if (dec)
            fprintf(ofp, "%s\n", reverse_string(translate_string(key, message, 'd')));

    } else {
        if (enc)
            fprintf(ofp, "%s\n", translate_string(key, message, 'e'));

        if (dec)
            fprintf(ofp, "%s\n", translate_string(key, message, 'd'));
    }

    /* close the file if opened */
    if (ofp != NULL)
        fclose(ofp);

    return EXIT_SUCCESS;
}
