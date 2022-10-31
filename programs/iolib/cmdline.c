#include "cmdline.h"

void displayCurrentState(Matrix peta) {
    POINT position = currentPosition(peta);

    printf("\n");
    printf("========================================");
    printf("\n");
    printf("BNMO di posisi: (%d,%d)", ROW(position)-1, COL(position)-1);
    printf("\n");
    printf("Waktu: ");
    printf("\n");
    printf("Notifikasi: ");
    printf("\n");
    printf("\n");
    displayMatrix(peta);
    printf("\n");
}

/* Run command line until user enters "EXIT" command */
void commandLineCycle(Matrix peta) {
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
            displayCurrentState(peta);

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