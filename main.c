#include "./ADT/liststatik/listStatik.h"
#include "./ADT/matrix/matrix.h"
#include "./ADT/prioqueue/prioqueue.h"
#include "./programs/iolib/cmdline.h"

int main() {
    /* KAMUS */
    Matrix peta;
    ListStatik listCatalog;
    ListStatik listResep;
    String command, exit, start;
    Simulator simulator, nextSimulator;
    Stack undoStack, redoStack;
    boolean started, isRedo;

    /* ALGORITMA */
    loadMakanan(&listCatalog, "./pita.txt");
    loadResep(&listResep, listCatalog, "./pitaResep.txt");
    readPetaFromFile(&peta, "peta.txt");

    command = createString("");
    exit = createString("EXIT");
    start = createString("START");
    CreateEmptyStack(&undoStack);
    CreateEmptyStack(&redoStack);

    splashScreen();

    printf("Enter START/EXIT: ");
    START();
    started = false;
    while (!endWord) {
        if (!started) {
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, start)) {
                initializeSimulator(&simulator, peta);
                CopySimulator(simulator, &nextSimulator);
                started = true;
                isRedo = false;
            } else if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                printf("Enter START/EXIT: ");
            }
        } else {
            displayCurrentState(peta, simulator, listCatalog, undoStack,
                                redoStack, isRedo);

            printf("Enter command: ");
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                runCommand(&peta, &simulator, &nextSimulator, &undoStack,
                           &redoStack, &isRedo, listCatalog, listResep,
                           command);
            }
        }
    }

    return 0;
}