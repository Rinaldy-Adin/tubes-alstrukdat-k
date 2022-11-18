#include "cmdline.h"

void displayCurrentState(Matrix peta, Simulator sim, ListStatik listCatalog,
                         Stack undoStack, Stack redoStack, boolean isRedo) {
    int i, n_events, j;
    Simulator lastSim = InfoTop(redoStack);
    ListStatik eventStrings;
    String event, id;
    Makanan eventMakanan;
    POINT position = PositionSim(sim);

    printf("\n");
    printf("=========================================");
    printf("\n");
    printString(NamaSim(sim));
    printf(" di posisi: (%d,%d)", ROW(position) - 1, COL(position) - 1);
    printf("\n");
    printf("Waktu: %02d.%02d", Jam(TimeSim(sim)), Menit(TimeSim(sim)));
    printf("\n");
    printf("Notifikasi: ");

    if (((StackIsEmpty(redoStack) || isRedo) && isEmptyStat(EventsSim(sim)) ||
         ((!StackIsEmpty(redoStack) && !isRedo) &&
          isEmptyStat(EventsSim(lastSim))))) {
        printf("-");
    } else {
        if (StackIsEmpty(redoStack) || isRedo) {
            n_events = NEFFSTAT(EventsSim(sim));
        } else {
            n_events = NEFFSTAT(EventsSim(lastSim));
        }

        j = 0;
        for (i = 0; i < n_events; i++) {
            if (StackIsEmpty(redoStack)) {
                eventStrings = splitString(STRING(ELMTSTAT(EventsSim(sim), i)));
                event = STRING(ELMTSTAT(eventStrings, 0));
                id = STRING(ELMTSTAT(eventStrings, 1));

                if (stringsAreEqual(event, createString("Deliv"))) {
                    printf("\n");
                    printf("   %d. ", j + 1);
                    j++;

                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah diterima oleh ");
                    printString(NamaSim(sim));
                    printf("!");
                } else if (stringsAreEqual(event, createString("Exp"))) {
                    printf("\n");
                    printf("   %d. ", j + 1);
                    j++;

                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah kedaluarsa");
                }

            } else if (isRedo) {
                printf("\n");
                printf("   %d. ", j + 1);
                j++;

                eventStrings = splitString(STRING(ELMTSTAT(EventsSim(sim), i)));
                event = STRING(ELMTSTAT(eventStrings, 0));
                id = STRING(ELMTSTAT(eventStrings, 1));

                if (stringsAreEqual(event, createString("Deliv"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah diterima oleh ");
                    printString(NamaSim(sim));
                    printf("!");
                } else if (stringsAreEqual(event, createString("Exp"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah kedaluarsa");
                } else if (stringsAreEqual(event, createString("Buy"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan pembelian ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Fry"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan penggorengan ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Mix"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan pencampuran ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Boil"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan perebusan ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Chop"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan pemotongan ");
                    printString(Nama(eventMakanan));
                }
            } else {
                printf("\n");
                printf("   %d. ", j + 1);
                j++;

                eventStrings =
                    splitString(STRING(ELMTSTAT(EventsSim(lastSim), i)));
                event = STRING(ELMTSTAT(eventStrings, 0));
                id = STRING(ELMTSTAT(eventStrings, 1));

                if (stringsAreEqual(event, createString("Buy"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Pembelian ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Fry"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Penggorengan ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Mix"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Pencampuran ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Boil"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Perebusan ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Chop"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Pemotongan ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Exp"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dikembalikan ke inventory");
                } else if (stringsAreEqual(event, createString("Deliv"))) {
                    eventMakanan = MAKANAN(
                        ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dihapus dari inventory");
                }
            }

            if (j == 0) {
                printf("-");
            }
        }
    }

    printf("\n");
    printf("\n");
    displayMatrix(peta);
    printf("\n");
}

int buyCommand(Simulator *sim, Simulator *nextSim, ListStatik listCatalog) {
    /* KAMUS */
    ListStatik list;
    Makanan chosenMakanan;
    infotype inventoryItem;
    String eventStr, commandStr;
    ElTypeStat eType;
    int command;

    /* ALGORITMA */
    printf("=========================================\n");
    printf("=                   BUY                 =\n");
    printf("=========================================\n");
    list = listMakananCommand(createString("Buy"), listCatalog);

    printf("Kirim 0 untuk exit.\n\n");
    printf("Enter command: ");
    commandStr = removeLongSpaces(readLine());

    while (true) {
        if (stringIsIntParsable(commandStr)) {
            command = stringToInt(commandStr);
            if (command >= 0 && command <= NEFFSTAT(list))
                break;
        }
        printf("Masukkan command yang valid (angka 0 - %d)\n\n",
               NEFFSTAT(list));
        printf("Enter command: ");
        commandStr = removeLongSpaces(readLine());
        printf("\n");
    }

    if (command > 0) {
        chosenMakanan = MAKANAN(ELMTSTAT(list, command - 1));

        printf("Berhasil memesan ");
        printString(Nama(chosenMakanan));
        printf(". ");
        printString(Nama(chosenMakanan));
        printf(" akan diantar dalam ");
        TulisTIMEShort(DelTime(chosenMakanan));
        printf(".\n");

        delivery(&chosenMakanan, &DeliverySim(*nextSim));

        eventStr = createString("Buy");
        eventStr = concatString(eventStr, ID(chosenMakanan));

        STRING(eType) = eventStr;
        insertLastStat(&EventsSim(*nextSim), eType);

        return 1;
    }
    return -1;
}

int cookCommand(Simulator *sim, Simulator *nextSim, ListStatik listCatalog,
                ListStatik listResep, String cookMethod) {
    /* KAMUS */
    ListStatik list;
    Makanan chosenMakanan;
    infotype inventoryItem;
    ElTypeStat eType;
    String eventStr, commandStr;
    int command;
    boolean cookable;

    /* ALGORITMA */
    printf("=========================================\n");
    printf("=                   ");
    printString(cookMethod);
    printf("                 =\n");
    printf("=========================================\n");
    list = listMakananCommand(cookMethod, listCatalog);

    printf("Kirim 0 untuk exit.\n\n");
    printf("Enter command: ");
    commandStr = removeLongSpaces(readLine());
    printf("\n");

    while (true) {
        if (stringIsIntParsable(commandStr)) {
            command = stringToInt(commandStr);
            if (command >= 0 && command <= NEFFSTAT(list)) {
                if (command == 0) {
                    break;
                } else {
                    cookable = Cook(ID(MAKANAN(ELMTSTAT(list, command - 1))),
                                    &InventorySim(*nextSim), listResep);

                    if (cookable) {
                        break;
                    } else {
                        printf("\nEnter command: ");
                        commandStr = removeLongSpaces(readLine());
                        continue;
                    }
                }
            }
        }

        printf("Masukkan command yang valid (angka 0 - %d)\n\n",
               NEFFSTAT(list));
        printf("Enter command: ");
        commandStr = removeLongSpaces(readLine());
        printf("\n");
    }

    if (command > 0) {
        chosenMakanan = MAKANAN(ELMTSTAT(list, command - 1));

        printString(Nama(chosenMakanan));
        printf(" selesai dibuat dan sudah masuk ke inventory!\n");
        eventStr = concatString(cookMethod, ID(chosenMakanan));

        STRING(eType) = eventStr;
        insertLastStat(&EventsSim(*nextSim), eType);

        return TIMEToMenit(ActTime(chosenMakanan));
    }
    return -1;
}

void removeActions(Simulator *sim) {
    /* KAMUS */
    int i;
    ListStatik eventStrings;
    String event;
    ElTypeStat tmp;

    /* ALGORITMA */
    if (listLengthStat(EventsSim(*sim)) == 0)
        return;

    for (i = listLengthStat(EventsSim(*sim)) - 1; i >= 0; i--) {
        eventStrings = splitString(STRING(ELMTSTAT(EventsSim(*sim), i)));
        event = STRING(ELMTSTAT(eventStrings, 0));

        if (!(stringsAreEqual(event, createString("Deliv")) ||
              stringsAreEqual(event, createString("Exp")))) {
            deleteAtStat(&EventsSim(*sim), &tmp, i);
        }
    }
}

void undoCommand(Matrix *peta, Simulator *sim, Simulator *nextSim,
                 Stack *undoStack, Stack *redoStack) {
    /* KAMUS */
    POINT oldPos;

    /* ALGOITMA */
    if (!StackIsEmpty(*undoStack)) {
        oldPos = PositionSim(*sim);
        Push(redoStack, *sim);
        Pop(undoStack, sim);
        moveTo(oldPos, PositionSim(*sim), peta);
        *nextSim = *sim;
    } else {
        printf("Stack undo masih kosong. Belum ada aksi yang dilakukan.\n");
    }
}

void redoCommand(Matrix *peta, Simulator *sim, Simulator *nextSim,
                 Stack *undoStack, Stack *redoStack) {
    /* KAMUS */
    POINT oldPos;

    /* ALGORITMA */
    if (!StackIsEmpty(*redoStack)) {
        oldPos = PositionSim(*sim);
        Pop(redoStack, sim);
        Push(undoStack, *sim);
        moveTo(oldPos, PositionSim(*sim), peta);
        *nextSim = *sim;
    } else {
        printf(
            "Stack redo masih kosong. Belum ada aksi undo yang dilakukan.\n");
    }
}

void decrementSim(Simulator *sim, Simulator *nextSim, Stack *undoStack,
                  Stack *redoStack, int nMenit) {
    /* ALGORITMA */
    Push(undoStack, *sim);

    TimeSim(*nextSim) = NextNMenit(TimeSim(*nextSim), nMenit);
    decrementTime(&DeliverySim(*nextSim), &InventorySim(*nextSim),
                  &EventsSim(*nextSim), nMenit);
    // removeDelivered(&DeliverySim(*nextSim), &InventorySim(*nextSim),
    //                 &EventsSim(*nextSim));
    // decrementTime(&InventorySim(*nextSim), nMenit);
    // removeExpired(&InventorySim(*nextSim), &EventsSim(*nextSim));

    CopySimulator(*nextSim, sim);
    CreateListStatik(&EventsSim(*nextSim));
}

void runCommand(Matrix *peta, Simulator *sim, Simulator *nextSim,
                Stack *undoStack, Stack *redoStack, boolean *isRedo,
                ListStatik listCatalog, ListStatik listResep, String command) {
    /* KAMUS */
    String mv_north = createString("MOVE NORTH");
    String mv_east = createString("MOVE EAST");
    String mv_south = createString("MOVE SOUTH");
    String mv_west = createString("MOVE WEST");

    String buy = createString("BUY");
    String fry = createString("FRY");
    String mix = createString("MIX");
    String boil = createString("BOIL");
    String chop = createString("CHOP");
    int actTime;

    String catalog = createString("CATALOG");
    String cookbook = createString("COOKBOOK");
    String inventory = createString("INVENTORY");
    String delivery = createString("DELIVERY");
    String recommend = createString("RECOMMEND");

    String wait = createString("WAIT");
    int x, y, minutes;

    String undo = createString("UNDO");
    String redo = createString("REDO");

    /* ALGORITMA */
    *isRedo = false;
    printf("\n");
    if (stringsAreEqual(command, mv_north)) {
        if (move(&PositionSim(*nextSim), peta, 'N'))
            decrementSim(sim, nextSim, undoStack, redoStack, 1);
    } else if (stringsAreEqual(command, mv_east)) {
        if (move(&PositionSim(*nextSim), peta, 'E'))
            decrementSim(sim, nextSim, undoStack, redoStack, 1);
    } else if (stringsAreEqual(command, mv_south)) {
        if (move(&PositionSim(*nextSim), peta, 'S'))
            decrementSim(sim, nextSim, undoStack, redoStack, 1);
    } else if (stringsAreEqual(command, mv_west)) {
        if (move(&PositionSim(*nextSim), peta, 'W'))
            decrementSim(sim, nextSim, undoStack, redoStack, 1);
    } else if (stringsAreEqual(command, catalog)) {
        printListMakanan(listCatalog);
    } else if (stringsAreEqual(command, cookbook)) {
        printResep(listResep);
    } else if (stringsAreEqual(command, inventory)) {
        displayInventory(InventorySim(*sim));
    } else if (stringsAreEqual(command, recommend)) {
        RecommendMakanan(InventorySim(*sim), listResep, listCatalog);
    } else if (stringsAreEqual(command, delivery)) {
        displayDelivery(DeliverySim(*sim));
    } else if (stringsAreEqual(command, undo)) {
        undoCommand(peta, sim, nextSim, undoStack, redoStack);
    } else if (stringsAreEqual(command, redo)) {
        redoCommand(peta, sim, nextSim, undoStack, redoStack);
        *isRedo = true;
    } else if (stringsAreEqual(command, buy)) {
        if (isAdjacent(PositionSim(*sim), *peta, 'T')) {
            actTime = buyCommand(sim, nextSim, listCatalog);
            if (actTime != -1)
                decrementSim(sim, nextSim, undoStack, redoStack, actTime);
        } else {
            printString(NamaSim(*sim));
            printf(" tidak berada di area telepon\n");
        }
    } else if (stringsAreEqual(command, fry)) {
        if (isAdjacent(PositionSim(*sim), *peta, 'F')) {
            actTime = cookCommand(sim, nextSim, listCatalog, listResep,
                                  createString("Fry"));
            if (actTime != -1)
                decrementSim(sim, nextSim, undoStack, redoStack, actTime);
        } else {
            printString(NamaSim(*sim));
            printf(" tidak berada di area menggoreng\n");
        }
    } else if (stringsAreEqual(command, mix)) {
        if (isAdjacent(PositionSim(*sim), *peta, 'M')) {
            actTime = cookCommand(sim, nextSim, listCatalog, listResep,
                                  createString("Mix"));
            if (actTime != -1)
                decrementSim(sim, nextSim, undoStack, redoStack, actTime);
        } else {
            printString(NamaSim(*sim));
            printf(" tidak berada di area mencampur\n");
        }
    } else if (stringsAreEqual(command, boil)) {
        if (isAdjacent(PositionSim(*sim), *peta, 'B')) {
            actTime = cookCommand(sim, nextSim, listCatalog, listResep,
                                  createString("Boil"));
            if (actTime != -1)
                decrementSim(sim, nextSim, undoStack, redoStack, actTime);
        } else {
            printString(NamaSim(*sim));
            printf(" tidak berada di area merebus\n");
        }
    } else if (stringsAreEqual(command, chop)) {
        if (isAdjacent(PositionSim(*sim), *peta, 'C')) {
            actTime = cookCommand(sim, nextSim, listCatalog, listResep,
                                  createString("Chop"));
            if (actTime != -1)
                decrementSim(sim, nextSim, undoStack, redoStack, actTime);
        } else {
            printString(NamaSim(*sim));
            printf(" tidak berada di area memotong\n");
        }
    } else if (stringsAreEqual(STRING(ELMTSTAT(splitString(command), 0)),
                               wait)) {
        if (NEFFSTAT(splitString(command)) == 3 &&
            stringIsIntParsable(STRING(ELMTSTAT(splitString(command), 1))) &&
            stringIsIntParsable(STRING(ELMTSTAT(splitString(command), 1)))) {
            x = stringToInt(STRING(ELMTSTAT(splitString(command), 1)));
            y = stringToInt(STRING(ELMTSTAT(splitString(command), 2)));
            minutes = 60 * x + y;

            decrementSim(sim, nextSim, undoStack, redoStack, minutes);
            printf("Berhasil menunggu selama %d jam dan %d menit \n", x, y);
        } else {
            printf("%d\n", NEFFSTAT(splitString(command)));
            printf(
                "\nCommand Wait salah (expected \"WAIT x y\" dimana x adalah "
                "jam dan y adalah menit)\n");
        }
    } else {
        printf("command salah\n");
    }
}

void initializeSimulator(Simulator *sim, Matrix peta) {
    /* KAMUS */
    String nama;
    POINT pos;
    PrioQueue inventory, delivery;
    ListStatik events;
    TIME time;

    /* ALGORITMA */
    pos = currentPosition(peta);
    MakeEmpty(&inventory, 100);
    MakeEmpty(&delivery, 100);
    CreateTime(&time, 0, 0, 0);
    CreateListStatik(&events);

    printf("\n");
    printf("=========================================");
    printf("\n\n");
    printf("Masukkan nama anda : ");
    nama = readLine();
    nama = removeLongSpaces(nama);

    CreateSimulator(sim, nama, pos, time, inventory, delivery, events);
}
