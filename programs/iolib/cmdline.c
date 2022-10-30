#include "cmdline.h"

#include <stdio.h>

#include "../../ADT/wordmachine/strlib.h"
#include "boolean.h"
#include "cursed.h"

void displayCurrentState() {
    printf("\n");
    printf("========================================");
    printf("\n");
    printf("BNMO di posisi: ");
    printf("\n");
    printf("Waktu: ");
    printf("\n");
    printf("Notifikasi: ");
    printf("\n");
    // Display map
    printf("\n");
}

/* Run command line until user enters "EXIT" command */
void commandLineCycle() {
    /* KAMUS */
    String command, exit, start;
    boolean started;

    /* ALGORITMA */
    command = createString("");
    exit = createString("EXIT");
    start = createString("START");

    // splashScreen();

    printf("Enter command: ");
    START();
    started = false;
    while (!endWord) {
        if (!started) {
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, start)) {
                started = true;
            } else if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                printf("Enter command: ");
            }
        } else {
            displayCurrentState();

            printf("Enter command: ");
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                printString(command);
                printf("\n");
            }
        }
    }
}