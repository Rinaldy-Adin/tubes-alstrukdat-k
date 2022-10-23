#include "cmdline.h"

#include <stdio.h>

#include "boolean.h"

Word readCommand() {
    /* KAMUS */
    int nWords;
    Word command;
    boolean valid;

    /* ALGORITMA */
    valid = false;

    while (!valid) {
        printf("Enter Command: ");
        STARTWORD();
        nWords = 0;

        while (!endWord) {
            duplicateWord(&currentWord, &command);
            nWords++;
            valid = true;
            ADVWORD();
        }

        if (nWords != 1) {
            valid = false;
            printf("Commands must only consist of one word");
        }
    }

    return command;
}

/* Wait for user to enter "START" command */
void waitForStart() {
    Word command = readCommand();

    printf("%s\n", command.TabWord);
}

/* Run command line until user enters "EXIT" command */
void commandLineCycle();
