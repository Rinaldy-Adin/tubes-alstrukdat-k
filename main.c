#include "./ADT/kulkas/kulkas.h"
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
    Kulkas kulkas;
    boolean started, isRedo;
    int actTime, x, y, minutes;

    /* ALGORITMA */
    loadMakanan(&listCatalog, "./pita.txt");
    loadResep(&listResep, listCatalog, "./pitaResep.txt");
    readPetaFromFile(&peta, "peta.txt");

    command = createString("");
    exit = createString("EXIT");
    start = createString("START");
    CreateEmptyStack(&undoStack);
    CreateEmptyStack(&redoStack);
    createEmptyKulkas(&kulkas);

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
            displayCurrentState(peta, simulator, listCatalog, undoStack, redoStack, isRedo);

            printf("Enter command: ");
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                isRedo = false;
                printf("\n");
                if (stringsAreEqual(command, createString("MOVE NORTH"))) {
                    if (move(&PositionSim(nextSimulator), &peta, 'N'))
                        decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack, 1);
                } else if (stringsAreEqual(command, createString("MOVE EAST"))) {
                    if (move(&PositionSim(nextSimulator), &peta, 'E'))
                        decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack, 1);
                } else if (stringsAreEqual(command, createString("MOVE SOUTH"))) {
                    if (move(&PositionSim(nextSimulator), &peta, 'S'))
                        decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack, 1);
                } else if (stringsAreEqual(command, createString("MOVE WEST"))) {
                    if (move(&PositionSim(nextSimulator), &peta, 'W'))
                        decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack, 1);
                } else if (stringsAreEqual(command, createString("CATALOG"))) {
                    printListMakanan(listCatalog);
                } else if (stringsAreEqual(command, createString("COOKBOOK"))) {
                    printResep(listResep);
                } else if (stringsAreEqual(command, createString("INVENTORY"))) {
                    displayInventory(InventorySim(simulator));
                } else if (stringsAreEqual(command, createString("RECOMMEND"))) {
                    RecommendMakanan(InventorySim(simulator), listResep, listCatalog);
                } else if (stringsAreEqual(command, createString("DELIVERY"))) {
                    displayDelivery(DeliverySim(simulator));
                } else if (stringsAreEqual(command, createString("UNDO"))) {
                    undoCommand(&peta, &simulator, &nextSimulator, &undoStack, &redoStack);
                } else if (stringsAreEqual(command, createString("REDO"))) {
                    redoCommand(&peta, &simulator, &nextSimulator, &undoStack, &redoStack);
                    isRedo = true;
                } else if (stringsAreEqual(command, createString("KULKAS"))) {
                    actTime = kulkasCommand(&simulator, &nextSimulator, &kulkas);
                    if (actTime != -1)
                        decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack, actTime);
                } else if (stringsAreEqual(command, createString("BUY"))) {
                    if (isAdjacent(PositionSim(simulator), peta, 'T')) {
                        actTime = buyCommand(&simulator, &nextSimulator, listCatalog);
                        if (actTime != -1)
                            decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack,
                                         actTime);
                    } else {
                        printString(NamaSim(simulator));
                        printf(
                            " tidak berada di area "
                            "telepon\n");
                    }
                } else if (stringsAreEqual(command, createString("FRY"))) {
                    if (isAdjacent(PositionSim(simulator), peta, 'F')) {
                        actTime = cookCommand(&simulator, &nextSimulator, listCatalog, listResep,
                                              createString("Fry"));
                        if (actTime != -1)
                            decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack,
                                         actTime);
                    } else {
                        printString(NamaSim(simulator));
                        printf(
                            " tidak berada di area "
                            "menggoreng\n");
                    }
                } else if (stringsAreEqual(command, createString("MIX"))) {
                    if (isAdjacent(PositionSim(simulator), peta, 'M')) {
                        actTime = cookCommand(&simulator, &nextSimulator, listCatalog, listResep,
                                              createString("Mix"));
                        if (actTime != -1)
                            decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack,
                                         actTime);
                    } else {
                        printString(NamaSim(simulator));
                        printf(
                            " tidak berada di area "
                            "mencampur\n");
                    }
                } else if (stringsAreEqual(command, createString("BOIL"))) {
                    if (isAdjacent(PositionSim(simulator), peta, 'B')) {
                        actTime = cookCommand(&simulator, &nextSimulator, listCatalog, listResep,
                                              createString("Boil"));
                        if (actTime != -1)
                            decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack,
                                         actTime);
                    } else {
                        printString(NamaSim(simulator));
                        printf(
                            " tidak berada di area "
                            "merebus\n");
                    }
                } else if (stringsAreEqual(command, createString("CHOP"))) {
                    if (isAdjacent(PositionSim(simulator), peta, 'C')) {
                        actTime = cookCommand(&simulator, &nextSimulator, listCatalog, listResep,
                                              createString("Chop"));
                        if (actTime != -1)
                            decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack,
                                         actTime);
                    } else {
                        printString(NamaSim(simulator));
                        printf(
                            " tidak berada di area "
                            "memotong\n");
                    }
                } else if (stringsAreEqual(STRING(ELMTSTAT(splitString(command), 0)),
                                           createString("WAIT"))) {
                    if (NEFFSTAT(splitString(command)) == 3 &&
                        stringIsIntParsable(STRING(ELMTSTAT(splitString(command), 1))) &&
                        stringIsIntParsable(STRING(ELMTSTAT(splitString(command), 1)))) {
                        x = stringToInt(STRING(ELMTSTAT(splitString(command), 1)));
                        y = stringToInt(STRING(ELMTSTAT(splitString(command), 2)));
                        minutes = 60 * x + y;

                        decrementSim(&simulator, &nextSimulator, &undoStack, &redoStack, minutes);
                        printf(
                            "Berhasil menunggu selama %d "
                            "jam dan %d menit \n",
                            x, y);
                    } else {
                        printf("%d\n", NEFFSTAT(splitString(command)));
                        printf(
                            "\nCommand Wait salah "
                            "(expected \"WAIT x y\" "
                            "dimana x adalah "
                            "jam dan y adalah menit)\n");
                    }
                } else {
                    printf("command salah\n");
                }
            }
        }
    }

    return 0;
}